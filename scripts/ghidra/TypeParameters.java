// SPDX-License-Identifier: GPL-3.0-or-later
// Infers parameter types from how the Sly 2 code uses them, for the parameters the signature repair added
// (named in_a1, in_t0... with an undefined type). Evidence for one parameter:
//   inside   the parameter passed straight to a call whose callee has an imported signature: that slot's type
//   callers  at each call site, the type of the variable the caller passes in that position, when it is known
//            (a typed parameter or local of the caller, not undefined)
// A type is chosen when every piece of evidence agrees; struct pointers related by inheritance agree, and the most
// derived one is taken. undefined, void * and generic register types (int, long) say nothing.
//
// --evaluate: blind test on the parameters of byte-identical functions (plate comment match:exact), whose types are
//             right: each typed parameter is predicted without its own type, and the prediction is compared.
// --apply:    types the added parameters, logs each change to <log.tsv> and adds a PARAMETER TYPED line to the plate
//             comment.
// Headless: -process <program> -noanalysis [-readOnly] -postScript TypeParameters.java <--evaluate|--apply> <log.tsv> <inheritance.json>
//@category Sly
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.DataType;
import ghidra.program.model.data.Pointer;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Parameter;
import ghidra.program.model.pcode.HighFunction;
import ghidra.program.model.pcode.HighParam;
import ghidra.program.model.pcode.HighVariable;
import ghidra.program.model.pcode.PcodeOp;
import ghidra.program.model.pcode.PcodeOpAST;
import ghidra.program.model.pcode.Varnode;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.SourceType;

import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class TypeParameters extends GhidraScript {
	private DecompInterface decompiler;
	private final Map<Function, HighFunction> decompiled = new HashMap<>();
	private final Map<String, String> baseOf = new HashMap<>();

	@Override
	public void run() throws Exception {
		String[] arguments = getScriptArgs();
		boolean apply = arguments[0].equals("--apply");
		Path logFile = Path.of(arguments[1]);
		Matcher pair = Pattern.compile("\"([A-Za-z0-9_]+)\":\\s*\"([A-Za-z0-9_]+)\"").matcher(Files.readString(Path.of(arguments[2])));
		while (pair.find()) {
			baseOf.put(pair.group(1), pair.group(2));
		}
		decompiler = new DecompInterface();
		decompiler.setOptions(new DecompileOptions());
		decompiler.openProgram(currentProgram);
		try (PrintWriter log = new PrintWriter(Files.newBufferedWriter(logFile, StandardCharsets.UTF_8))) {
			if (apply) {
				applyTypes(log);
			} else {
				evaluate(log);
			}
		} finally {
			decompiler.dispose();
		}
	}

	private HighFunction high(Function function) {
		return decompiled.computeIfAbsent(function, f -> {
			DecompileResults results = decompiler.decompileFunction(f, 60, monitor);
			return results.getHighFunction();
		});
	}

	/** The evidence for parameter slot of function: one type per piece of evidence that says something. */
	private List<DataType> evidence(Function function, int slot) {
		List<DataType> found = new ArrayList<>();
		HighFunction body = high(function);
		if (body != null) {
			Iterator<PcodeOpAST> ops = body.getPcodeOps();
			while (ops.hasNext()) {
				PcodeOpAST op = ops.next();
				if (op.getOpcode() != PcodeOp.CALL) {
					continue;
				}
				Function callee = getFunctionAt(op.getInput(0).getAddress());
				if (callee == null || callee.getSignatureSource() != SourceType.IMPORTED) {
					continue;
				}
				for (int position = 1; position < op.getNumInputs() && position - 1 < callee.getParameterCount(); position++) {
					HighParam source = sourceParameter(op.getInput(position));
					if (source != null && source.getSlot() == slot) {
						addInformative(found, callee.getParameter(position - 1).getDataType());
					}
				}
			}
		}
		for (Reference reference : getReferencesTo(function.getEntryPoint())) {
			if (!reference.getReferenceType().isCall()) {
				continue;
			}
			Function caller = getFunctionContaining(reference.getFromAddress());
			HighFunction callerBody = caller == null ? null : high(caller);
			if (callerBody == null) {
				continue;
			}
			Iterator<PcodeOpAST> ops = callerBody.getPcodeOps(reference.getFromAddress());
			while (ops.hasNext()) {
				PcodeOpAST op = ops.next();
				if (op.getOpcode() == PcodeOp.CALL && op.getInput(0).getAddress().equals(function.getEntryPoint()) && slot + 1 < op.getNumInputs()) {
					HighVariable variable = op.getInput(slot + 1).getHigh();
					if (variable != null) {
						addInformative(found, variable.getDataType());
					}
				}
			}
		}
		return found;
	}

	private void addInformative(List<DataType> found, DataType type) {
		String name = type.getName();
		// generic register types the decompiler gives anything (int, long for a 64-bit register) are no evidence
		if (name.startsWith("undefined") || name.equals("void *") || name.equals("void") || name.matches("u?int|u?long|u?longlong")) {
			return;
		}
		found.add(type);
	}

	/** The type all the evidence agrees on (the most derived struct pointer), or null. */
	private DataType agree(List<DataType> found) {
		if (found.isEmpty()) {
			return null;
		}
		DataType chosen = found.get(0);
		for (DataType other : found) {
			if (other.getName().equals(chosen.getName())) {
				continue;
			}
			String a = structOf(chosen);
			String b = structOf(other);
			if (a == null || b == null) {
				return null;
			}
			if (derives(b, a)) {
				chosen = other;
			} else if (!derives(a, b)) {
				return null;
			}
		}
		return chosen;
	}

	private String structOf(DataType type) {
		return type instanceof Pointer pointer && pointer.getDataType() != null ? pointer.getDataType().getName() : null;
	}

	private boolean derives(String derived, String base) {
		Set<String> seen = new HashSet<>();
		for (String current = baseOf.get(derived); current != null && seen.add(current); current = baseOf.get(current)) {
			if (current.equals(base)) {
				return true;
			}
		}
		return false;
	}

	private HighParam sourceParameter(Varnode varnode) {
		for (int depth = 0; varnode != null && depth < 4; depth++) {
			if (varnode.getHigh() instanceof HighParam parameter) {
				return parameter;
			}
			PcodeOp definition = varnode.getDef();
			if (definition == null || (definition.getOpcode() != PcodeOp.CAST && definition.getOpcode() != PcodeOp.COPY)) {
				return null;
			}
			varnode = definition.getInput(0);
		}
		return null;
	}

	private void evaluate(PrintWriter log) {
		log.println("address\tfunction\tparameter\tdeclared\tpredicted\tresult");
		int right = 0;
		int wrong = 0;
		int silent = 0;
		for (Function function : currentProgram.getFunctionManager().getFunctions(true)) {
			String plate = function.getComment();
			if (plate == null || !plate.contains("match:exact") || function.getSignatureSource() != SourceType.IMPORTED) {
				continue;
			}
			for (Parameter parameter : function.getParameters()) {
				List<DataType> informative = new ArrayList<>();
				addInformative(informative, parameter.getDataType());
				if (informative.isEmpty()) {
					continue;  // nothing to predict: the declared type itself says nothing
				}
				DataType predicted = agree(evidence(function, parameter.getOrdinal()));
				String result;
				if (predicted == null) {
					silent++;
					result = "silent";
				} else if (predicted.getName().equals(parameter.getDataType().getName())) {
					right++;
					result = "right";
				} else {
					String a = structOf(predicted);
					String b = structOf(parameter.getDataType());
					boolean related = a != null && b != null && (derives(a, b) || derives(b, a));
					if (related) {
						right++;
						result = "related";
					} else {
						wrong++;
						result = "wrong";
					}
				}
				log.println(function.getEntryPoint() + "\t" + function.getName() + "\t" + parameter.getName() + "\t" + parameter.getDataType().getName() + "\t" + (predicted == null ? "" : predicted.getName()) + "\t" + result);
			}
		}
		println(String.format("TypeParameters evaluate: %d right (same or related class), %d wrong, %d silent", right, wrong, silent));
	}

	private void applyTypes(PrintWriter log) throws Exception {
		log.println("address\tfunction\tparameter\tbefore\tafter\tevidence");
		int typed = 0;
		int undecided = 0;
		for (Function function : currentProgram.getFunctionManager().getFunctions(true)) {
			if (function.getSignatureSource() != SourceType.IMPORTED) {
				continue;
			}
			for (Parameter parameter : function.getParameters()) {
				if (!parameter.getName().startsWith("in_") || !parameter.getDataType().getName().startsWith("undefined")) {
					continue;
				}
				List<DataType> found = evidence(function, parameter.getOrdinal());
				DataType chosen = agree(found);
				if (chosen == null || chosen.getLength() > parameter.getLength()) {
					undecided++;
					continue;
				}
				String before = parameter.getDataType().getName();
				parameter.setDataType(chosen, SourceType.IMPORTED);
				String plate = function.getComment();
				String note = "PARAMETER TYPED: " + parameter.getName() + " " + before + " -> " + chosen.getName() + " (" + found.size() + " uses agree)";
				function.setComment(plate == null ? note : plate + "\n" + note);
				log.println(function.getEntryPoint() + "\t" + function.getName() + "\t" + parameter.getName() + "\t" + before + "\t" + chosen.getName() + "\t" + found.size());
				typed++;
			}
		}
		println(String.format("TypeParameters apply: %d parameters typed, %d left undefined (no or conflicting evidence)", typed, undecided));
	}
}
