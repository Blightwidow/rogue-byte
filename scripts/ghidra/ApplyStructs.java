// SPDX-License-Identifier: GPL-3.0-or-later
// Fills the /sly2 structs (created empty by ApplySignatures.java) with the fields of scripts/names/struct_layout.py
// (config/recovered/sly2_structs.json): each field at its Sly 2 offset with its name, type and origin as the field comment. The struct
// grows to the end of its last known field; what lies between known fields stays undefined.
// Headless: -process <program> -noanalysis -preScript ApplyStructs.java <sly2_structs.json>
//@category Sly
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;

import java.nio.file.Files;
import java.nio.file.Path;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class ApplyStructs extends GhidraScript {
	private static final CategoryPath CATEGORY = new CategoryPath("/sly2");
	private static final Pattern STRUCT = Pattern.compile("\"([A-Za-z0-9_]+)\":\\s*\\[(.*?)\\]\\s*(?=,\\s*\"[A-Za-z0-9_]+\":\\s*\\[|\\}\\s*$)", Pattern.DOTALL);
	private static final Pattern FIELD = Pattern.compile("\\{([^{}]*)\\}");

	private DataTypeManager types;

	@Override
	public void run() throws Exception {
		types = currentProgram.getDataTypeManager();
		String json = Files.readString(Path.of(getScriptArgs()[0]));
		int structCount = 0;
		int fieldCount = 0;
		int failed = 0;
		Matcher struct = STRUCT.matcher(json);
		while (struct.find()) {
			Structure target = structure(struct.group(1));
			Matcher field = FIELD.matcher(struct.group(2));
			while (field.find()) {
				String body = field.group(1);
				int offset = Integer.parseInt(value(body, "offset"));
				int size = Integer.parseInt(value(body, "size"));
				DataType type = parse(value(body, "type"), size);
				int end = offset + Math.max(type.getLength(), 1);
				if (target.getLength() < end) {
					target.growStructure(end - target.getLength());
				}
				String sly1 = value(body, "sly1_offset");
				String comment = sly1.equals("null") ? "seen only in Sly 2 code" : "Sly 1 offset 0x" + Integer.toHexString(Integer.parseInt(sly1));
				try {
					target.replaceAtOffset(offset, type, type.getLength(), value(body, "name"), comment);
					fieldCount++;
				} catch (IllegalArgumentException error) {
					failed++;
				}
			}
			structCount++;
		}
		println("ApplyStructs: " + fieldCount + " fields in " + structCount + " structs, " + failed + " not placed");
	}

	private Structure structure(String name) {
		DataType existing = types.getDataType(CATEGORY, name);
		if (existing instanceof Structure structure) {
			return structure;
		}
		return (Structure) types.addDataType(new StructureDataType(CATEGORY, name, 0, types), DataTypeConflictHandler.REPLACE_HANDLER);
	}

	private static String value(String body, String key) {
		Matcher match = Pattern.compile("\"" + key + "\":\\s*(\"((?:[^\"\\\\]|\\\\.)*)\"|[^,}\\s]+)").matcher(body);
		if (!match.find()) {
			throw new IllegalArgumentException("no " + key + " in " + body);
		}
		return match.group(2) != null ? match.group(2) : match.group(1);
	}

	private DataType parse(String text, int size) {
		text = text.trim();
		if (text.endsWith("*")) {
			String target = text.substring(0, text.length() - 1).trim();
			return new PointerDataType(target.equals("void") ? VoidDataType.dataType : structure(target), types);
		}
		switch (text) {
			case "float": return FloatDataType.dataType;
			case "int": return IntegerDataType.dataType;
			case "short": return ShortDataType.dataType;
			case "char": return CharDataType.dataType;
			case "long long": return LongLongDataType.dataType;
			default: return size > 1 ? new ArrayDataType(Undefined1DataType.dataType, size, 1, types) : Undefined1DataType.dataType;
		}
	}
}
