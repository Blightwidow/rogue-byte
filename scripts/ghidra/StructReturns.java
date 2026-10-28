// SPDX-License-Identifier: GPL-3.0-or-later
// Finds functions that return a struct by value through a hidden pointer, and with --apply models it. GCC passes the
// caller's result buffer in a0, so every declared parameter moves one register later; the function writes the result
// through a0 and returns a0. The mangled Sly 1 names do not encode return types, so the demangled signatures miss the
// buffer. A function is taken when all three hold:
//   returns   the returned value is parameter 0 (through casts and copies)
//   writes    there is a STORE through parameter 0 (+ a constant)
//   shifted   the body reads the argument register right after the declared ones (in_a2 for two declared integer
//             parameters): the real last parameter, pushed out by the buffer
// An explicit pointer return (MATRIX4 *f(MATRIX4 *pmat, ...)) returns and writes parameter 0 too, but reads no extra
// register, so it is not taken. A function with no declared parameter is not taken either: there the buffer and the
// "shifted" register are both a0, and the evidence only says it takes a pointer (Sly 2's StartGame).
// The buffer is typed after the first declared struct parameter (operator*(const MATRIX4 &, ...) returns a MATRIX4):
// the decompiler resolves only some 128-bit stores as buffer + constant, so the written extent is a fallback.
//
// --detect: lists the functions (address, name, written extent) to <out.tsv>.
// --apply:  inserts "ret" as parameter 0, typed from the written extent (16 bytes VECTOR *, 48 MATRIX3 *, 64 MATRIX4 *,
//           else void *), makes it the return type, notes it in the plate comment and logs to <out.tsv>.
// Headless: -process <program> -noanalysis [-readOnly] -postScript StructReturns.java <--detect|--apply> <out.tsv>
//@category Sly
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Function.FunctionUpdateType;
import ghidra.program.model.listing.Parameter;
import ghidra.program.model.listing.ParameterImpl;
import ghidra.program.model.pcode.HighFunction;
import ghidra.program.model.pcode.HighParam;
import ghidra.program.model.pcode.HighSymbol;
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

public class StructReturns extends GhidraScript {
	private static final List<String> INTEGER_REGISTERS = List.of("a0", "a1", "a2", "a3", "t0", "t1", "t2", "t3");
	private static final CategoryPath CATEGORY = new CategoryPath("/sly2");

	@Override
	public void run() throws Exception {
		boolean apply = getScriptArgs()[0].equals("--apply");
		DecompInterface decompiler = new DecompInterface();
		decompiler.setOptions(new DecompileOptions());
		decompiler.openProgram(currentProgram);
		int found = 0;
		try (PrintWriter out = new PrintWriter(Files.newBufferedWriter(Path.of(getScriptArgs()[1]), StandardCharsets.UTF_8))) {
			out.println("address\tname\textent\tbefore\tafter");
			for (Function function : currentProgram.getFunctionManager().getFunctions(true)) {
				monitor.checkCancelled();
				long declared = java.util.Arrays.stream(function.getParameters()).filter(p -> !p.getName().startsWith("in_")).count();
				if (function.getSignatureSource() != SourceType.IMPORTED || declared == 0) {
					continue;
				}
				DecompileResults results = decompiler.decompileFunction(function, 60, monitor);
				HighFunction high = results.getHighFunction();
				if (high == null) {
					continue;
				}
				long extent = writtenExtent(high);
				if (extent <= 0 || !returnsParameterZero(high) || !readsShiftedRegister(function, high)) {
					continue;
				}
				String before = function.getPrototypeString(false, false);
				String after = before;
				if (apply) {
					DataType buffer = new PointerDataType(bufferType(function, extent), currentProgram.getDataTypeManager());
					List<Parameter> parameters = new ArrayList<>();
					parameters.add(new ParameterImpl("ret", buffer, currentProgram));
					for (Parameter parameter : function.getParameters()) {
						if (!parameter.getName().startsWith("in_")) {  // a register the repair added is now the shifted real parameter
							parameters.add(new ParameterImpl(parameter.getName(), parameter.getDataType(), currentProgram));
						}
					}
					function.setCustomVariableStorage(false);
					function.replaceParameters(parameters, FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true, SourceType.IMPORTED);
					function.setReturnType(buffer, SourceType.IMPORTED);
					after = function.getPrototypeString(false, false);
					String plate = function.getComment();
					String note = "STRUCT RETURN: hidden result buffer in a0 (" + extent + " bytes written), parameters shifted. Was: " + before;
					function.setComment(plate == null ? note : plate + "\n" + note);
				}
				out.println(function.getEntryPoint() + "\t" + function.getName() + "\t" + extent + "\t" + before + "\t" + after);
				found++;
			}
		} finally {
			decompiler.dispose();
		}
		println("StructReturns: " + found + " functions " + (apply ? "modelled" : "detected"));
	}

	private DataType bufferType(Function function, long extent) {
		for (Parameter parameter : function.getParameters()) {
			if (parameter.getDataType() instanceof Pointer pointer && pointer.getDataType() instanceof Structure structure) {
				return structure;
			}
		}
		String name = extent == 16 ? "VECTOR" : extent == 48 ? "MATRIX3" : extent == 64 ? "MATRIX4" : null;
		if (name != null) {
			DataType type = currentProgram.getDataTypeManager().getDataType(CATEGORY, name);
			if (type != null) {
				return type;
			}
		}
		return VoidDataType.dataType;
	}

	/** The highest byte written through parameter 0 (+ constant), or 0 when nothing is. */
	private long writtenExtent(HighFunction high) {
		long extent = 0;
		Iterator<PcodeOpAST> ops = high.getPcodeOps();
		while (ops.hasNext()) {
			PcodeOpAST op = ops.next();
			if (op.getOpcode() != PcodeOp.STORE) {
				continue;
			}
			long offset = offsetFromParameterZero(op.getInput(1), 0);
			if (offset >= 0) {
				extent = Math.max(extent, offset + op.getInput(2).getSize());
			}
		}
		return extent;
	}

	private boolean returnsParameterZero(HighFunction high) {
		Iterator<PcodeOpAST> ops = high.getPcodeOps();
		boolean any = false;
		while (ops.hasNext()) {
			PcodeOpAST op = ops.next();
			if (op.getOpcode() != PcodeOp.RETURN) {
				continue;
			}
			if (op.getNumInputs() < 2 || offsetFromParameterZero(op.getInput(1), 0) != 0) {
				return false;  // every return must hand back the buffer
			}
			any = true;
		}
		return any;
	}

	/** Whether the body reads the integer argument register right after the declared integer parameters. */
	private boolean readsShiftedRegister(Function function, HighFunction high) {
		int integers = 0;
		for (Parameter parameter : function.getParameters()) {
			if (parameter.getName().startsWith("in_")) {
				continue;  // added by the repair: may itself be the shifted parameter
			}
			if (!(parameter.getDataType() instanceof FloatDataType)) {
				integers++;
			}
		}
		if (integers >= INTEGER_REGISTERS.size()) {
			return false;
		}
		String next = INTEGER_REGISTERS.get(integers);
		for (Parameter parameter : function.getParameters()) {
			if (parameter.getName().equals("in_" + next) || parameter.getName().startsWith("in_" + next + "_")) {
				return true;
			}
		}
		Iterator<HighSymbol> symbols = high.getLocalSymbolMap().getSymbols();
		while (symbols.hasNext()) {
			String name = symbols.next().getName();
			if (name.equals("in_" + next) || name.startsWith("in_" + next + "_")) {
				return true;
			}
		}
		return false;
	}

	/** offset when varnode is parameter 0 plus a constant (through casts, copies, PTRSUB, INT_ADD), else -1. */
	private long offsetFromParameterZero(Varnode varnode, int depth) {
		if (varnode == null || depth > 8) {
			return -1;
		}
		if (varnode.getHigh() instanceof HighParam parameter && parameter.getSlot() == 0 && varnode.getDef() == null) {
			return 0;
		}
		PcodeOp definition = varnode.getDef();
		if (definition == null) {
			return varnode.getHigh() instanceof HighParam parameter && parameter.getSlot() == 0 ? 0 : -1;
		}
		switch (definition.getOpcode()) {
			case PcodeOp.CAST, PcodeOp.COPY -> {
				return offsetFromParameterZero(definition.getInput(0), depth + 1);
			}
			case PcodeOp.PTRSUB, PcodeOp.INT_ADD -> {
				Varnode right = definition.getInput(1);
				if (right.isConstant()) {
					long inner = offsetFromParameterZero(definition.getInput(0), depth + 1);
					return inner < 0 ? -1 : inner + right.getOffset();
				}
				return -1;
			}
			case PcodeOp.MULTIEQUAL -> {
				return varnode.getHigh() instanceof HighParam parameter && parameter.getSlot() == 0 ? 0 : -1;
			}
			default -> {
				return -1;
			}
		}
	}
}
