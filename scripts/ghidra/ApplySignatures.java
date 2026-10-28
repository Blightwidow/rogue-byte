// SPDX-License-Identifier: GPL-3.0-or-later
// Applies the prototypes of scripts/names/demangle.py (config/recovered/sly2_signatures.json) to the program: parameter types from the GCC 2.95
// mangling, and the return type when the name implies one (otherwise the decompiler's own guess stays). Struct types
// are created empty under /sly2 (Sly 2 layouts are not known yet); function pointers become void *.
// Headless: -process <program> -noanalysis -preScript ApplySignatures.java <sly2_signatures.json>
//@category Sly
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Function.FunctionUpdateType;
import ghidra.program.model.listing.Parameter;
import ghidra.program.model.listing.ParameterImpl;
import ghidra.program.model.symbol.SourceType;

import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class ApplySignatures extends GhidraScript {
	private static final CategoryPath CATEGORY = new CategoryPath("/sly2");
	private static final Pattern ENTRY = Pattern.compile(
		"\\{\\s*\"address\":\\s*(\\d+),\\s*\"name\":\\s*\"([^\"]*)\",\\s*\"return\":\\s*(null|\"[^\"]*\"),\\s*\"parameters\":\\s*\\[(.*?)\\]\\s*\\}",
		Pattern.DOTALL);
	private static final Pattern STRING = Pattern.compile("\"((?:[^\"\\\\]|\\\\.)*)\"");

	private DataTypeManager types;

	@Override
	public void run() throws Exception {
		types = currentProgram.getDataTypeManager();
		String json = Files.readString(Path.of(getScriptArgs()[0]));
		Matcher entry = ENTRY.matcher(json);
		int applied = 0;
		int missing = 0;
		while (entry.find()) {
			Function function = getFunctionAt(toAddr(Long.parseLong(entry.group(1))));
			if (function == null) {
				missing++;
				continue;
			}
			List<Parameter> parameters = new ArrayList<>();
			Matcher parameter = STRING.matcher(entry.group(4));
			int index = 0;
			while (parameter.find()) {
				String cType = parameter.group(1);
				if (cType.equals("...")) {
					function.setVarArgs(true);
					continue;
				}
				String name = cType.endsWith(" *this") ? "this_" : "arg" + index;
				String typeText = cType.endsWith(" *this") ? cType.substring(0, cType.length() - 5) + "*" : cType;
				parameters.add(new ParameterImpl(name, parse(typeText), currentProgram));
				index++;
			}
			String returnText = entry.group(3).equals("null") ? null : entry.group(3).replace("\"", "");
			function.setCallingConvention(currentProgram.getCompilerSpec().getDefaultCallingConvention().getName());
			function.replaceParameters(parameters, FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true, SourceType.IMPORTED);
			if (returnText != null) {
				function.setReturnType(parse(returnText), SourceType.IMPORTED);
			}
			applied++;
		}
		println("ApplySignatures: " + applied + " functions, " + missing + " addresses without a function");
	}

	/** A C type string from scripts/names/demangle.py ("const VECTOR *", "unsigned int", "float (*)(void *, float)", "int [4]"). */
	private DataType parse(String text) {
		text = text.trim();
		if (text.contains("(*)")) {
			return new PointerDataType(VoidDataType.dataType, types);
		}
		if (text.endsWith("]")) {
			return new PointerDataType(parse(text.substring(0, text.lastIndexOf('['))), types);
		}
		if (text.endsWith("*")) {
			return new PointerDataType(parse(text.substring(0, text.length() - 1)), types);
		}
		text = text.replace("const ", "").replace("volatile ", "").trim();
		switch (text) {
			case "void": return VoidDataType.dataType;
			case "int": case "signed int": return IntegerDataType.dataType;
			case "unsigned int": case "unsigned": return UnsignedIntegerDataType.dataType;
			case "char": case "signed char": return CharDataType.dataType;
			case "unsigned char": return UnsignedCharDataType.dataType;
			case "short": return ShortDataType.dataType;
			case "unsigned short": return UnsignedShortDataType.dataType;
			case "long": return LongDataType.dataType;
			case "unsigned long": return UnsignedLongDataType.dataType;
			case "long long": return LongLongDataType.dataType;
			case "unsigned long long": return UnsignedLongLongDataType.dataType;
			case "float": return FloatDataType.dataType;
			case "double": return DoubleDataType.dataType;
			case "bool": return BooleanDataType.dataType;
			case "wchar_t": return WideCharDataType.dataType;
			default: return struct(text);
		}
	}

	private DataType struct(String name) {
		DataType existing = types.getDataType(CATEGORY, name);
		if (existing != null) {
			return existing;
		}
		return types.addDataType(new StructureDataType(CATEGORY, name, 0, types), DataTypeConflictHandler.KEEP_HANDLER);
	}
}
