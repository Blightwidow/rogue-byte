// SPDX-License-Identifier: GPL-3.0-or-later
// Creates a function at every address listed in a file (one hex address per line) that is code but not yet a
// function: the methods only reachable through Sly 2's vtables, which analysis never reaches by calls.
// Headless: -process <program> -noanalysis -preScript CreateFunctionsAt.java <addresses.txt>
//@category Sly
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;

import java.nio.file.Files;
import java.nio.file.Path;

public class CreateFunctionsAt extends GhidraScript {
	@Override
	public void run() throws Exception {
		int created = 0;
		int existing = 0;
		for (String line : Files.readAllLines(Path.of(getScriptArgs()[0]))) {
			if (line.isBlank()) {
				continue;
			}
			Address address = toAddr(Long.decode(line.trim()));
			if (getFunctionAt(address) != null) {
				existing++;
				continue;
			}
			disassemble(address);
			if (createFunction(address, null) != null) {
				created++;
			}
		}
		println("CreateFunctionsAt: created " + created + ", already functions " + existing);
	}
}
