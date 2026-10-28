// SPDX-License-Identifier: GPL-3.0-or-later
// The EE has 128-bit general registers, and Sly 2 passes vectors by value in one of them (Sly 1 passed VECTOR *): the
// body then reads the upper half of a declared parameter's register (the decompiler's in_a0_udw, in_a1_hi). The
// plugin's calling convention caps a register parameter at 8 bytes, so such a parameter is moved to custom storage on
// the 128-bit register (a0_qw...).
//   1. Sizes from how the byte-identical functions use them: VECTOR, VU_VECTOR, VECTOR4 are four floats (x, y, z, w)
//      and QW 16 bytes; VU_FLOAT is one float (a VU_FLOAT argument arrives as a 32-bit scalar, _qmtc2(in_a2_lo)).
//   2. A parameter whose register is read above its declared size becomes VU_VECTOR in aN_qw (CalculateVectorPanTilt).
//   3. A 16-byte class passed by value (G9VU_VECTOR) moves to aN_qw: operator=(VU_VECTOR) stores all four 32-bit
//      pieces of a1.
// Not handled: a function returning a struct by value takes a hidden return pointer in a0 that shifts its parameters
// (operator*(const MATRIX4 &, VU_FLOAT)); those stay flagged.
// Every change is logged to <log.tsv> and noted in the plate comment.
// Headless: -process <program> -noanalysis -postScript QuadwordParameters.java <log.tsv>
//@category Sly
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import ghidra.program.model.lang.Register;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Parameter;
import ghidra.program.model.listing.VariableStorage;
import ghidra.program.model.pcode.HighFunction;
import ghidra.program.model.pcode.HighSymbol;
import ghidra.program.model.symbol.SourceType;

import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Set;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class QuadwordParameters extends GhidraScript {
	private static final CategoryPath CATEGORY = new CategoryPath("/sly2");
	private static final Pattern UPPER_READ = Pattern.compile("^in_(a[0-3]|t[0-3])_(hi|udw)$");
	private static final List<String> VECTOR_TYPES = List.of("VECTOR", "VU_VECTOR", "VECTOR4");

	@Override
	public void run() throws Exception {
		DataTypeManager types = currentProgram.getDataTypeManager();
		for (String name : VECTOR_TYPES) {
			sized(types, name, true);
		}
		sized(types, "QW", false);
		scalar(types, "VU_FLOAT");
		DataType vuVector = types.getDataType(CATEGORY, "VU_VECTOR");
		DecompInterface decompiler = new DecompInterface();
		decompiler.setOptions(new DecompileOptions());
		decompiler.openProgram(currentProgram);
		int moved = 0;
		try (PrintWriter log = new PrintWriter(Files.newBufferedWriter(Path.of(getScriptArgs()[0]), StandardCharsets.UTF_8))) {
			log.println("address\tfunction\tparameter\tbefore\tafter");
			for (Function function : currentProgram.getFunctionManager().getFunctions(true)) {
				if (function.getSignatureSource() != SourceType.IMPORTED) {
					continue;
				}
				Set<String> upper = new HashSet<>();
				DecompileResults results = decompiler.decompileFunction(function, 60, monitor);
				HighFunction high = results.getHighFunction();
				if (high != null) {
					Iterator<HighSymbol> symbols = high.getLocalSymbolMap().getSymbols();
					while (symbols.hasNext()) {
						Matcher match = UPPER_READ.matcher(symbols.next().getName());
						if (match.matches()) {
							upper.add(match.group(1));
						}
					}
				}
				boolean customised = false;
				for (Parameter parameter : function.getParameters()) {
					DataType type = parameter.getDataType();
					Register register = parameter.getRegister();
					if (register == null) {
						continue;
					}
					String base = register.getBaseRegister().getName().replaceAll("_(qw|lo|hi|udw)$", "");
					boolean wide = type instanceof Structure && type.getLength() == 16;
					if (!wide && !upper.contains(base)) {
						continue;
					}
					Register quadword = currentProgram.getRegister(base + "_qw");
					if (quadword == null || parameter.getVariableStorage().getRegister() == quadword) {
						continue;
					}
					if (!customised) {
						function.setCustomVariableStorage(true);
						customised = true;
					}
					DataType newType = wide ? type : vuVector;
					String before = type.getName() + " in " + register.getName();
					parameter.setDataType(newType, new VariableStorage(currentProgram, quadword), true, SourceType.IMPORTED);
					String after = newType.getName() + " in " + quadword.getName();
					log.println(function.getEntryPoint() + "\t" + function.getName() + "\t" + parameter.getName() + "\t" + before + "\t" + after);
					String plate = function.getComment();
					String note = "QUADWORD PARAMETER: " + parameter.getName() + " " + before + " -> " + after + " (128-bit register read)";
					function.setComment(plate == null ? note : plate + "\n" + note);
					moved++;
				}
			}
		} finally {
			decompiler.dispose();
		}
		println("QuadwordParameters: " + moved + " parameters moved to 128-bit registers");
	}

	/** Makes an empty /sly2 struct a single float. */
	private void scalar(DataTypeManager types, String name) {
		DataType existing = types.getDataType(CATEGORY, name);
		Structure structure = existing instanceof Structure s ? s
			: (Structure) types.addDataType(new StructureDataType(CATEGORY, name, 0, types), DataTypeConflictHandler.KEEP_HANDLER);
		if (structure.getNumDefinedComponents() == 0) {
			StructureDataType complete = new StructureDataType(CATEGORY, name, 0, types);
			complete.add(FloatDataType.dataType, 4, "f", "scalar, passed in a 32-bit register");
			structure.replaceWith(complete);
		}
	}

	/** Gives a /sly2 struct its 16 bytes: four floats x y z w for vectors, raw bytes otherwise. An empty struct is
	 *  replaced by a complete one; a struct that already has fields only grows. */
	private void sized(DataTypeManager types, String name, boolean floats) {
		DataType existing = types.getDataType(CATEGORY, name);
		Structure structure = existing instanceof Structure s ? s
			: (Structure) types.addDataType(new StructureDataType(CATEGORY, name, 0, types), DataTypeConflictHandler.KEEP_HANDLER);
		if (structure.getNumDefinedComponents() == 0) {
			StructureDataType complete = new StructureDataType(CATEGORY, name, 0, types);
			if (floats) {
				for (String lane : new String[] { "x", "y", "z", "w" }) {
					complete.add(FloatDataType.dataType, 4, lane, "PS2 VU lane");
				}
			} else {
				complete.add(new ArrayDataType(Undefined1DataType.dataType, 16, 1, types), 16, "qw", "128-bit value");
			}
			structure.replaceWith(complete);
		} else if (structure.getLength() < 16) {
			structure.growStructure(16 - structure.getLength());
		}
	}
}
