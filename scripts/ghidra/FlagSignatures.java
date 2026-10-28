// SPDX-License-Identifier: GPL-3.0-or-later
// Flags the imported (demangled Sly 1) signatures that the Sly 2 code contradicts, and with --repair fixes the clear cases.
// For every function whose signature source is IMPORTED, the decompiler's view is checked for:
//   conflict  a parameter passed straight (through casts and copies) to a call whose callee also has an imported
//             signature, where the callee expects a different type at that position
//   missing   the body reads argument registers the signature does not declare (the decompiler's in_a2, in_t0, in_f13...)
//   unused    a declared parameter the body never reads (weak: real code has unused parameters too)
// Writes one TSV line per function with at least one finding: address, name, severity, findings.
// A struct pointer passed where its base or subclass is expected is not a conflict (C++ up- and downcasts): the class
// tree comes from config/sly1/sly1_inheritance.json (from ProjectCane's and the Sly 1 decomp's headers), path in the third
// argument.
//
// --annotate (without -readOnly): a high finding goes into the function's plate comment as "SIGNATURE SUSPECT: ...".
// --repair (implies --annotate): in rounds until nothing changes,
//   missing   parameters are appended up to the highest argument register read (the EE passes integers in a0-a3, t0-t3
//             and floats in f12-f19, counted separately); a register read as _hi/_udw gets an 8-byte type
//   conflict  the parameter takes the type the callee expects, when every call agrees and the callee is not itself
//             flagged high (a wrong callee signature must not spread); a parameter is retyped at most once, so two
//             callees that want different types cannot make it flip between rounds (it stays flagged instead)
// and every change is appended to <out.tsv>.repairs.tsv (address, name, before, after, reason) and the plate comment.
// "At most once" holds across runs: a parameter retyped in any run of that log is never retyped again (a re-run used
// to flip AdjustCmCpdefi's arg0 back to CM *).
// Headless: -process <program> -noanalysis [-readOnly] -postScript FlagSignatures.java <out.tsv> <--check|--annotate|--repair> <inheritance.json>
//@category Sly
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.DataType;
import ghidra.program.model.data.FloatDataType;
import ghidra.program.model.data.Undefined4DataType;
import ghidra.program.model.data.Undefined8DataType;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Function.FunctionUpdateType;
import ghidra.program.model.listing.Parameter;
import ghidra.program.model.listing.ParameterImpl;
import ghidra.program.model.pcode.HighFunction;
import ghidra.program.model.pcode.HighParam;
import ghidra.program.model.pcode.HighSymbol;
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
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class FlagSignatures extends GhidraScript {
	private static final Pattern ARGUMENT_REGISTER = Pattern.compile("^in_(a[0-7]|t[0-3]|f1[2-9])(_(lo|hi|udw|qw).*)?$");
	private static final List<String> INTEGER_REGISTERS = List.of("a0", "a1", "a2", "a3", "t0", "t1", "t2", "t3");
	private static final List<String> FLOAT_REGISTERS = List.of("f12", "f13", "f14", "f15", "f16", "f17", "f18", "f19");
	private static final String SUSPECT = "SIGNATURE SUSPECT: ";
	private static final int MAXIMUM_ROUNDS = 6;

	/** A parameter handed to a typed callee that wants another type at that position. */
	private record Conflict(int slot, String parameter, DataType have, Function callee, int position, DataType want) {
		String describe() {
			return parameter + " " + have.getName() + " -> " + callee.getName() + " arg" + position + " " + want.getName();
		}
	}

	/** What the decompiler says about one function's signature. */
	private record Check(Function function, List<Conflict> conflicts, Set<String> missing, List<String> unused) {
		boolean high() {
			return !conflicts.isEmpty() || !missing.isEmpty();
		}

		boolean flagged() {
			return high() || !unused.isEmpty();
		}

		String findings() {
			List<String> parts = new ArrayList<>();
			for (Conflict conflict : conflicts) {
				parts.add("conflict: " + conflict.describe());
			}
			if (!missing.isEmpty()) {
				parts.add("missing: reads " + String.join(",", missing));
			}
			if (!unused.isEmpty()) {
				parts.add("unused: " + String.join(",", unused));
			}
			return String.join("; ", parts);
		}
	}

	private DecompInterface decompiler;
	private final Map<String, String> baseOf = new HashMap<>();
	private final Set<String> retyped = new HashSet<>();

	@Override
	public void run() throws Exception {
		String[] arguments = getScriptArgs();
		Path outFile = Path.of(arguments[0]);
		boolean repair = arguments.length > 1 && arguments[1].equals("--repair");
		boolean annotate = repair || arguments.length > 1 && arguments[1].equals("--annotate");
		if (arguments.length > 2) {
			Matcher pair = Pattern.compile("\"([A-Za-z0-9_]+)\":\\s*\"([A-Za-z0-9_]+)\"").matcher(Files.readString(Path.of(arguments[2])));
			while (pair.find()) {
				baseOf.put(pair.group(1), pair.group(2));
			}
		}
		decompiler = new DecompInterface();
		decompiler.setOptions(new DecompileOptions());
		decompiler.openProgram(currentProgram);
		try {
			if (repair) {
				repairRounds(Path.of(outFile + ".repairs.tsv"));
			}
			report(outFile, annotate);
		} finally {
			decompiler.dispose();
		}
	}

	private List<Function> importedFunctions() {
		List<Function> functions = new ArrayList<>();
		for (Function function : currentProgram.getFunctionManager().getFunctions(true)) {
			if (function.getSignatureSource() == SourceType.IMPORTED) {
				functions.add(function);
			}
		}
		return functions;
	}

	private Check check(Function function) {
		DecompileResults results = decompiler.decompileFunction(function, 60, monitor);
		HighFunction high = results.getHighFunction();
		if (high == null) {
			return null;
		}
		return new Check(function, conflicts(function, high), missingArguments(high), unusedParameters(high));
	}

	private void report(Path outFile, boolean annotate) throws Exception {
		int checked = 0;
		int flagged = 0;
		int highCount = 0;
		try (PrintWriter out = new PrintWriter(Files.newBufferedWriter(outFile, StandardCharsets.UTF_8))) {
			out.println("address\tname\tseverity\tfindings");
			for (Function function : importedFunctions()) {
				monitor.checkCancelled();
				Check check = check(function);
				if (check == null) {
					continue;
				}
				checked++;
				if (annotate) {
					setSuspectNote(function, check.high() ? SUSPECT + check.findings() : null);
				}
				if (check.flagged()) {
					flagged++;
					highCount += check.high() ? 1 : 0;
					out.println(function.getEntryPoint() + "\t" + function.getName() + "\t" + (check.high() ? "high" : "low") + "\t" + check.findings());
				}
			}
		}
		println(String.format("FlagSignatures: %d checked, %d flagged (%d high, %d low) to %s", checked, flagged, highCount, flagged - highCount, outFile));
	}

	/** Replaces the SIGNATURE SUSPECT line of the plate comment (none when note is null). */
	private void setSuspectNote(Function function, String note) {
		String plate = function.getComment();
		List<String> lines = new ArrayList<>();
		if (plate != null) {
			for (String line : plate.split("\n")) {
				if (!line.startsWith(SUSPECT)) {
					lines.add(line);
				}
			}
		}
		if (note != null) {
			lines.add(note);
		}
		function.setComment(lines.isEmpty() ? null : String.join("\n", lines));
	}

	private void appendNote(Function function, String note) {
		String plate = function.getComment();
		function.setComment(plate == null ? note : plate + "\n" + note);
	}

	private void repairRounds(Path logFile) throws Exception {
		int total = 0;
		boolean exists = Files.isRegularFile(logFile);
		if (exists) {
			for (String line : Files.readAllLines(logFile)) {
				String[] columns = line.split("\t");
				if (columns.length < 5 || !columns[4].contains("as its callee expects")) {
					continue;
				}
				for (String part : columns[4].split("; ")) {
					Matcher retype = Pattern.compile("^(\\S+) .* -> .*\\(as its callee expects\\)$").matcher(part);
					if (retype.matches()) {
						retyped.add(columns[0] + ":" + retype.group(1));
					}
				}
			}
		}
		try (PrintWriter log = new PrintWriter(Files.newBufferedWriter(logFile, StandardCharsets.UTF_8,
				java.nio.file.StandardOpenOption.CREATE, java.nio.file.StandardOpenOption.APPEND))) {
			if (!exists) {
				log.println("address\tname\tbefore\tafter\treason");
			}
			for (int round = 1; round <= MAXIMUM_ROUNDS; round++) {
				List<Check> checks = new ArrayList<>();
				Set<Function> highNow = new HashSet<>();
				for (Function function : importedFunctions()) {
					monitor.checkCancelled();
					Check check = check(function);
					if (check != null && check.high()) {
						checks.add(check);
						highNow.add(function);
					}
				}
				int repaired = 0;
				for (Check check : checks) {
					String before = check.function().getPrototypeString(false, false);
					List<String> reasons = new ArrayList<>();
					List<Parameter> parameters = new ArrayList<>(List.of(check.function().getParameters()));
					boolean changed = retypeConflicts(check, parameters, highNow, reasons);
					changed |= appendMissing(check, parameters, reasons);
					if (!changed) {
						continue;
					}
					check.function().replaceParameters(parameters, FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true, SourceType.IMPORTED);
					String after = check.function().getPrototypeString(false, false);
					log.println(check.function().getEntryPoint() + "\t" + check.function().getName() + "\t" + before + "\t" + after + "\t" + String.join("; ", reasons));
					appendNote(check.function(), "SIGNATURE REPAIRED (round " + round + "): " + String.join("; ", reasons) + ". Was: " + before);
					repaired++;
				}
				println("FlagSignatures: repair round " + round + ": " + checks.size() + " high, " + repaired + " repaired");
				total += repaired;
				if (repaired == 0) {
					break;
				}
			}
		}
		println("FlagSignatures: " + total + " repairs logged to " + logFile);
	}

	/** Each conflicting parameter takes the callee's type when every call agrees and no callee involved is flagged. */
	private boolean retypeConflicts(Check check, List<Parameter> parameters, Set<Function> flagged, List<String> reasons) throws Exception {
		Map<Integer, Set<String>> wanted = new HashMap<>();
		Map<Integer, DataType> wantedType = new HashMap<>();
		Set<Integer> blocked = new HashSet<>();
		for (Conflict conflict : check.conflicts()) {
			if (flagged.contains(conflict.callee())) {
				blocked.add(conflict.slot());
				continue;
			}
			wanted.computeIfAbsent(conflict.slot(), k -> new HashSet<>()).add(conflict.want().getName());
			wantedType.put(conflict.slot(), conflict.want());
		}
		boolean changed = false;
		for (Map.Entry<Integer, Set<String>> entry : wanted.entrySet()) {
			int slot = entry.getKey();
			String key = check.function().getEntryPoint() + ":" + parameters.get(Math.min(slot, parameters.size() - 1)).getName();
			if (blocked.contains(slot) || entry.getValue().size() != 1 || slot >= parameters.size() || retyped.contains(key)) {
				continue;
			}
			retyped.add(key);
			Parameter old = parameters.get(slot);
			DataType type = wantedType.get(slot);
			parameters.set(slot, new ParameterImpl(old.getName(), type, currentProgram));
			reasons.add(old.getName() + " " + old.getDataType().getName() + " -> " + type.getName() + " (as its callee expects)");
			changed = true;
		}
		return changed;
	}

	/** Appends parameters up to the highest undeclared argument register the body reads, per register class. */
	private boolean appendMissing(Check check, List<Parameter> parameters, List<String> reasons) throws Exception {
		int integerSlots = 0;
		int floatSlots = 0;
		for (Parameter parameter : parameters) {
			if (parameter.getDataType() instanceof FloatDataType) {
				floatSlots++;
			} else {
				integerSlots++;
			}
		}
		int highestInteger = -1;
		int highestFloat = -1;
		Set<String> wide = new HashSet<>();
		for (String name : check.missing()) {
			Matcher match = ARGUMENT_REGISTER.matcher(name);
			if (!match.matches()) {
				continue;
			}
			String register = match.group(1);
			if (match.group(3) != null && !match.group(3).equals("lo")) {
				wide.add(register);
			}
			highestInteger = Math.max(highestInteger, INTEGER_REGISTERS.indexOf(register));
			highestFloat = Math.max(highestFloat, FLOAT_REGISTERS.indexOf(register));
		}
		boolean changed = false;
		for (int slot = integerSlots; slot <= highestInteger; slot++) {
			String register = INTEGER_REGISTERS.get(slot);
			DataType type = wide.contains(register) ? Undefined8DataType.dataType : Undefined4DataType.dataType;
			parameters.add(new ParameterImpl("in_" + register, type, currentProgram));
			reasons.add("added " + type.getName() + " in_" + register + " (read but not declared)");
			changed = true;
		}
		for (int slot = floatSlots; slot <= highestFloat; slot++) {
			String register = FLOAT_REGISTERS.get(slot);
			parameters.add(new ParameterImpl("in_" + register, FloatDataType.dataType, currentProgram));
			reasons.add("added float in_" + register + " (read but not declared)");
			changed = true;
		}
		return changed;
	}

	private List<Conflict> conflicts(Function function, HighFunction high) {
		List<Conflict> found = new ArrayList<>();
		Iterator<PcodeOpAST> ops = high.getPcodeOps();
		while (ops.hasNext()) {
			PcodeOpAST op = ops.next();
			if (op.getOpcode() != PcodeOp.CALL) {
				continue;
			}
			Function callee = getFunctionAt(op.getInput(0).getAddress());
			if (callee == null || callee.getSignatureSource() != SourceType.IMPORTED) {
				continue;
			}
			Parameter[] expected = callee.getParameters();
			for (int position = 1; position < op.getNumInputs() && position - 1 < expected.length; position++) {
				HighParam source = sourceParameter(op.getInput(position));
				if (source == null) {
					continue;
				}
				Parameter declared = function.getParameter(source.getSlot());
				if (declared == null) {
					continue;
				}
				DataType have = declared.getDataType();
				DataType want = expected[position - 1].getDataType();
				if (differs(have, want)) {
					found.add(new Conflict(source.getSlot(), declared.getName(), have, callee, position - 1, want));
				}
			}
		}
		return found;
	}

	/** The parameter a call argument comes from, following casts and copies; null when it is computed. */
	private HighParam sourceParameter(Varnode varnode) {
		for (int depth = 0; varnode != null && depth < 4; depth++) {
			HighVariable variable = varnode.getHigh();
			if (variable instanceof HighParam parameter) {
				return parameter;
			}
			PcodeOp definition = varnode.getDef();
			if (definition == null) {
				return null;
			}
			int opcode = definition.getOpcode();
			if (opcode != PcodeOp.CAST && opcode != PcodeOp.COPY) {
				return null;
			}
			varnode = definition.getInput(0);
		}
		return null;
	}

	/** Two types disagree when both are known and not the same: different struct pointers, or pointer vs number. */
	private boolean differs(DataType have, DataType want) {
		String a = have.getName();
		String b = want.getName();
		if (a.equals(b) || a.startsWith("undefined") || b.startsWith("undefined") || a.equals("void *") || b.equals("void *")) {
			return false;
		}
		boolean pointerA = a.endsWith("*");
		boolean pointerB = b.endsWith("*");
		if (pointerA != pointerB) {
			return true;
		}
		if (pointerA) {
			String structA = a.substring(0, a.length() - 1).trim();
			String structB = b.substring(0, b.length() - 1).trim();
			return !(derives(structA, structB) || derives(structB, structA));
		}
		return have.getLength() != want.getLength();
	}

	/** Whether class derived has base among its ancestors (per the inheritance file). */
	private boolean derives(String derived, String base) {
		Set<String> seen = new HashSet<>();
		for (String current = baseOf.get(derived); current != null && seen.add(current); current = baseOf.get(current)) {
			if (current.equals(base)) {
				return true;
			}
		}
		return false;
	}

	/** Argument registers the body reads although the signature does not declare them. */
	private Set<String> missingArguments(HighFunction high) {
		Set<String> names = new LinkedHashSet<>();
		Iterator<HighSymbol> symbols = high.getLocalSymbolMap().getSymbols();
		while (symbols.hasNext()) {
			HighSymbol symbol = symbols.next();
			if (!symbol.isParameter() && ARGUMENT_REGISTER.matcher(symbol.getName()).matches()) {
				names.add(symbol.getName());
			}
		}
		return names;
	}

	/** Declared parameters with no use in the body (their varnodes have no readers). */
	private List<String> unusedParameters(HighFunction high) {
		List<String> names = new ArrayList<>();
		for (int slot = 0; slot < high.getLocalSymbolMap().getNumParams(); slot++) {
			HighSymbol symbol = high.getLocalSymbolMap().getParamSymbol(slot);
			HighVariable variable = symbol == null ? null : symbol.getHighVariable();
			boolean read = false;
			if (variable != null) {
				for (Varnode instance : variable.getInstances()) {
					if (instance.getDescendants().hasNext()) {
						read = true;
						break;
					}
				}
			}
			if (!read && symbol != null) {
				names.add(symbol.getName());
			}
		}
		return names;
	}
}
