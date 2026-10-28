// SPDX-License-Identifier: GPL-3.0-or-later
// Prints the decompiled C of the functions at the given addresses (a quick look at what the names and types give).
// Headless: -process <program> -noanalysis -readOnly -postScript DecompileFunctions.java 0x14E698 0x11D4D0 ...
//@category Sly
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;

public class DecompileFunctions extends GhidraScript {
	@Override
	public void run() throws Exception {
		DecompInterface decompiler = new DecompInterface();
		decompiler.openProgram(currentProgram);
		try {
			for (String argument : getScriptArgs()) {
				Function function = getFunctionAt(toAddr(Long.decode(argument)));
				if (function == null) {
					println("no function at " + argument);
					continue;
				}
				DecompileResults results = decompiler.decompileFunction(function, 60, monitor);
				println("\n" + results.getDecompiledFunction().getC());
			}
		} finally {
			decompiler.dispose();
		}
	}
}
