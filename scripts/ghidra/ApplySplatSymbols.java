// SPDX-License-Identifier: GPL-3.0-or-later
// Applies a splat symbol_addrs.txt (name = 0xADDR; // type:func ...) to the program before analysis: a label for every
// symbol, and a function at every type:func address, so that analysis starts from the decomp's function boundaries.
// An existing function is renamed. A trailing comment with "source:" (scripts/names/combine.py: where the name came from and how sure
// the match is) becomes the plate comment, so it shows above the function in the listing.
// Headless: -preScript ApplySplatSymbols.java <symbol_addrs.txt>
//@category Sly
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.SourceType;

import java.nio.file.Files;
import java.nio.file.Path;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class ApplySplatSymbols extends GhidraScript {
	private static final Pattern SYMBOL_LINE = Pattern.compile("^\\s*([A-Za-z_.$][\\w.$]*)\\s*=\\s*(0x[0-9A-Fa-f]+)\\s*;(.*)$");

	@Override
	public void run() throws Exception {
		Path symbolFile = Path.of(getScriptArgs()[0]);
		int functionCount = 0;
		int labelCount = 0;
		int skippedCount = 0;
		for (String line : Files.readAllLines(symbolFile)) {
			Matcher match = SYMBOL_LINE.matcher(line);
			if (!match.matches()) {
				continue;
			}
			String name = match.group(1);
			Address address = toAddr(Long.decode(match.group(2)));
			if (!currentProgram.getMemory().contains(address)) {
				skippedCount++;
				continue;
			}
			String trailing = match.group(3);
			if (trailing.contains("type:func")) {
				disassemble(address);
				Function function = getFunctionAt(address);
				if (function == null) {
					createFunction(address, name);
				} else {
					function.setName(name, SourceType.IMPORTED);
				}
				functionCount++;
			} else {
				createLabel(address, name, true, SourceType.IMPORTED);
				labelCount++;
			}
			int source = trailing.indexOf("source:");
			if (source >= 0) {
				setPlateComment(address, trailing.substring(source).trim());
			}
		}
		println(String.format("ApplySplatSymbols: %d functions, %d labels, %d outside memory", functionCount, labelCount, skippedCount));
	}
}
