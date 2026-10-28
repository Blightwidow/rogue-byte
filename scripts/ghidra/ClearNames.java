// SPDX-License-Identifier: GPL-3.0-or-later
// Takes names back off functions whose match was withdrawn (a veto, or a later run that pairs them differently): the
// function gets its default FUN_ name and an empty default signature again, and the plate comment says what it was
// and why. Input: a TSV with columns address, name, reason (address in hex, header line first).
// Headless: -process <program> -noanalysis -preScript ClearNames.java <withdrawn.tsv>
//@category Sly
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Function.FunctionUpdateType;
import ghidra.program.model.symbol.SourceType;

import java.nio.file.Files;
import java.nio.file.Path;
import java.util.List;

public class ClearNames extends GhidraScript {
	@Override
	public void run() throws Exception {
		List<String> lines = Files.readAllLines(Path.of(getScriptArgs()[0]));
		int cleared = 0;
		for (String line : lines.subList(1, lines.size())) {
			String[] columns = line.split("\t");
			Function function = getFunctionAt(toAddr(Long.decode(columns[0])));
			if (function == null || !function.getName().equals(columns[1])) {
				continue;  // gone, or already renamed by something else: leave it
			}
			function.setName(null, SourceType.DEFAULT);
			function.replaceParameters(List.of(), FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true, SourceType.DEFAULT);
			function.setSignatureSource(SourceType.DEFAULT);
			String note = "NAME WITHDRAWN: was " + columns[1] + " (" + columns[2] + ")";
			String plate = function.getComment();
			function.setComment(plate == null ? note : plate + "\n" + note);
			cleared++;
		}
		println("ClearNames: " + cleared + " functions back to their default name");
	}
}
