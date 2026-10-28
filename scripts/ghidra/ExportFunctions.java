// SPDX-License-Identifier: GPL-3.0-or-later
// Exports every function of the program as one JSON line: entry, name (null when Ghidra made it up), size, the raw
// instruction words and mnemonics in address order, the entries of the functions it calls (in call-site order), and the
// strings and other data it references. The matcher (scripts/names/match.py) normalises the words itself.
// Headless: -postScript ExportFunctions.java <out.jsonl>
//@category Sly
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.SourceType;

import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

public class ExportFunctions extends GhidraScript {
	@Override
	public void run() throws Exception {
		Path outFile = Path.of(getScriptArgs()[0]);
		int count = 0;
		try (PrintWriter out = new PrintWriter(Files.newBufferedWriter(outFile, StandardCharsets.UTF_8))) {
			for (Function function : currentProgram.getFunctionManager().getFunctions(true)) {
				out.println(exportFunction(function));
				count++;
			}
		}
		println("ExportFunctions: " + count + " functions to " + outFile);
	}

	private String exportFunction(Function function) throws Exception {
		List<String> words = new ArrayList<>();
		List<String> mnemonics = new ArrayList<>();
		List<String> calls = new ArrayList<>();
		List<String> strings = new ArrayList<>();
		List<String> dataRefs = new ArrayList<>();
		for (Instruction instruction : currentProgram.getListing().getInstructions(function.getBody(), true)) {
			words.add(Long.toString(Integer.toUnsignedLong(currentProgram.getMemory().getInt(instruction.getAddress()))));
			mnemonics.add(quote(instruction.getMnemonicString()));
			for (Reference reference : instruction.getReferencesFrom()) {
				Address target = reference.getToAddress();
				if (reference.getReferenceType().isCall()) {
					calls.add(Long.toString(target.getOffset()));
				} else if (reference.getReferenceType().isData()) {
					Data data = getDataAt(target);
					if (data != null && data.hasStringValue()) {
						strings.add(quote(String.valueOf(data.getValue())));
					} else {
						dataRefs.add(Long.toString(target.getOffset()));
					}
				}
			}
		}
		boolean named = function.getSymbol().getSource() != SourceType.DEFAULT;
		return "{\"entry\":" + function.getEntryPoint().getOffset()
			+ ",\"name\":" + (named ? quote(function.getName()) : "null")
			+ ",\"size\":" + function.getBody().getNumAddresses()
			+ ",\"words\":[" + String.join(",", words) + "]"
			+ ",\"mnemonics\":[" + String.join(",", mnemonics) + "]"
			+ ",\"calls\":[" + String.join(",", calls) + "]"
			+ ",\"strings\":[" + String.join(",", strings) + "]"
			+ ",\"data\":[" + String.join(",", dataRefs) + "]}";
	}

	private static String quote(String text) {
		StringBuilder builder = new StringBuilder("\"");
		for (char character : text.toCharArray()) {
			switch (character) {
				case '"' -> builder.append("\\\"");
				case '\\' -> builder.append("\\\\");
				case '\n' -> builder.append("\\n");
				case '\r' -> builder.append("\\r");
				case '\t' -> builder.append("\\t");
				default -> {
					if (character < 0x20) {
						builder.append(String.format("\\u%04x", (int) character));
					} else {
						builder.append(character);
					}
				}
			}
		}
		return builder.append('"').toString();
	}
}
