// SPDX-License-Identifier: GPL-3.0-or-later
// Exports, for every function with an imported signature, the struct fields it touches through its parameters: each
// LOAD or STORE (and each field address handed to a call) whose address is a struct-pointer parameter plus a constant,
// in p-code order. One JSON line per function:
//   {"entry":..., "accesses":[[slot, "STRUCT", offset, size, "L|S|A", "f|i|p|v"], ...]}
// kind L load, S store, A address passed to a call; value f float, p pointer, v 16-byte vector, i anything else.
// scripts/names/field_layout.py aligns these between Sly 1 and Sly 2 to map field offsets.
// Headless: -process <program> -noanalysis -readOnly -postScript ExportFieldAccesses.java <out.jsonl>
//@category Sly
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.DataType;
import ghidra.program.model.data.Pointer;
import ghidra.program.model.data.Structure;
import ghidra.program.model.data.TypeDef;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Parameter;
import ghidra.program.model.pcode.HighFunction;
import ghidra.program.model.pcode.HighParam;
import ghidra.program.model.pcode.HighVariable;
import ghidra.program.model.pcode.PcodeOp;
import ghidra.program.model.pcode.PcodeOpAST;
import ghidra.program.model.pcode.Varnode;
import ghidra.program.model.symbol.SourceType;

import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class ExportFieldAccesses extends GhidraScript {
	/** A parameter plus a constant offset. */
	private record Base(int slot, long offset) {
	}

	@Override
	public void run() throws Exception {
		Path outFile = Path.of(getScriptArgs()[0]);
		DecompInterface decompiler = new DecompInterface();
		decompiler.setOptions(new DecompileOptions());
		decompiler.openProgram(currentProgram);
		int functions = 0;
		long total = 0;
		try (PrintWriter out = new PrintWriter(Files.newBufferedWriter(outFile, StandardCharsets.UTF_8))) {
			for (Function function : currentProgram.getFunctionManager().getFunctions(true)) {
				monitor.checkCancelled();
				if (function.getSignatureSource() != SourceType.IMPORTED) {
					continue;
				}
				DecompileResults results = decompiler.decompileFunction(function, 60, monitor);
				HighFunction high = results.getHighFunction();
				if (high == null) {
					continue;
				}
				List<String> accesses = new ArrayList<>();
				Iterator<PcodeOpAST> ops = high.getPcodeOps();
				while (ops.hasNext()) {
					PcodeOpAST op = ops.next();
					int opcode = op.getOpcode();
					if (opcode == PcodeOp.LOAD) {
						record(function, op.getInput(1), op.getOutput().getSize(), "L", op.getOutput(), accesses);
					} else if (opcode == PcodeOp.STORE) {
						record(function, op.getInput(1), op.getInput(2).getSize(), "S", op.getInput(2), accesses);
					} else if (opcode == PcodeOp.CALL) {
						for (int i = 1; i < op.getNumInputs(); i++) {
							Base base = base(op.getInput(i), 0);
							if (base != null && base.offset() != 0) {
								add(function, base, 0, "A", "i", accesses);
							}
						}
					}
				}
				if (!accesses.isEmpty()) {
					out.println("{\"entry\":" + function.getEntryPoint().getOffset() + ",\"accesses\":[" + String.join(",", accesses) + "]}");
					functions++;
					total += accesses.size();
				}
			}
		} finally {
			decompiler.dispose();
		}
		println("ExportFieldAccesses: " + total + " accesses in " + functions + " functions to " + outFile);
	}

	private void record(Function function, Varnode address, int size, String kind, Varnode value, List<String> accesses) {
		Base base = base(address, 0);
		if (base != null) {
			add(function, base, size, kind, valueKind(value, size), accesses);
		}
	}

	private void add(Function function, Base base, int size, String kind, String value, List<String> accesses) {
		Parameter parameter = function.getParameter(base.slot());
		if (parameter == null) {
			return;
		}
		String struct = structName(parameter.getDataType());
		if (struct == null || base.offset() < 0 || base.offset() > 0x10000) {
			return;
		}
		accesses.add("[" + base.slot() + ",\"" + struct + "\"," + base.offset() + "," + size + ",\"" + kind + "\",\"" + value + "\"]");
	}

	/** The struct a parameter points to, or null when it is not a struct pointer. */
	private String structName(DataType type) {
		if (type instanceof TypeDef typeDef) {
			type = typeDef.getBaseDataType();
		}
		if (type instanceof Pointer pointer) {
			DataType target = pointer.getDataType();
			if (target instanceof TypeDef typeDef) {
				target = typeDef.getBaseDataType();
			}
			if (target instanceof Structure) {
				return target.getName();
			}
		}
		return null;
	}

	/** Follows an address back to parameter + constant through casts, copies, PTRSUB/PTRADD and INT_ADD of constants. */
	private Base base(Varnode varnode, int depth) {
		if (varnode == null || depth > 8) {
			return null;
		}
		HighVariable high = varnode.getHigh();
		if (high instanceof HighParam parameter && varnode.getDef() == null) {
			return new Base(parameter.getSlot(), 0);
		}
		PcodeOp definition = varnode.getDef();
		if (definition == null) {
			if (high instanceof HighParam parameter) {
				return new Base(parameter.getSlot(), 0);
			}
			return null;
		}
		switch (definition.getOpcode()) {
			case PcodeOp.CAST, PcodeOp.COPY -> {
				return base(definition.getInput(0), depth + 1);
			}
			case PcodeOp.PTRSUB, PcodeOp.INT_ADD -> {
				Varnode left = definition.getInput(0);
				Varnode right = definition.getInput(1);
				if (right.isConstant()) {
					Base inner = base(left, depth + 1);
					return inner == null ? null : new Base(inner.slot(), inner.offset() + right.getOffset());
				}
				if (left.isConstant()) {
					Base inner = base(right, depth + 1);
					return inner == null ? null : new Base(inner.slot(), inner.offset() + left.getOffset());
				}
				return null;
			}
			case PcodeOp.PTRADD -> {
				Varnode index = definition.getInput(1);
				Varnode element = definition.getInput(2);
				if (index.isConstant() && element.isConstant()) {
					Base inner = base(definition.getInput(0), depth + 1);
					return inner == null ? null : new Base(inner.slot(), inner.offset() + index.getOffset() * element.getOffset());
				}
				return null;
			}
			case PcodeOp.MULTIEQUAL -> {
				// the parameter itself flowing in from several paths (loops): accept when it is the parameter
				return high instanceof HighParam parameter ? new Base(parameter.getSlot(), 0) : null;
			}
			default -> {
				return null;
			}
		}
	}

	private String valueKind(Varnode value, int size) {
		if (size == 16) {
			return "v";
		}
		HighVariable high = value == null ? null : value.getHigh();
		DataType type = high == null ? null : high.getDataType();
		if (type != null) {
			String name = type.getName();
			if (name.contains("float")) {
				return "f";
			}
			if (type instanceof Pointer) {
				return "p";
			}
		}
		return "i";
	}
}
