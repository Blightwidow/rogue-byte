// SPDX-License-Identifier: GPL-3.0-or-later
// Exports Ghidra's decompilation of every function as one JSON line: {"entry":..., "name":"...", "signature":"...",
// "c":"..."}. The input of the decompilation work (data/batches, src/game), so the C text can be read without driving Ghidra.
// Headless: -process <program> -noanalysis -readOnly -postScript ExportDecompiled.java <out.jsonl>
//@category Sly
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;

import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;

public class ExportDecompiled extends GhidraScript {
	@Override
	public void run() throws Exception {
		Path outFile = Path.of(getScriptArgs()[0]);
		DecompInterface decompiler = new DecompInterface();
		decompiler.setOptions(new DecompileOptions());
		decompiler.openProgram(currentProgram);
		int count = 0;
		int failed = 0;
		try (PrintWriter out = new PrintWriter(Files.newBufferedWriter(outFile, StandardCharsets.UTF_8))) {
			for (Function function : currentProgram.getFunctionManager().getFunctions(true)) {
				monitor.checkCancelled();
				DecompileResults results = decompiler.decompileFunction(function, 60, monitor);
				String c = results.getDecompiledFunction() == null ? null : results.getDecompiledFunction().getC();
				if (c == null) {
					failed++;
				}
				out.println("{\"entry\":" + function.getEntryPoint().getOffset()
					+ ",\"name\":" + quote(function.getName())
					+ ",\"signature\":" + quote(function.getPrototypeString(false, false))
					+ ",\"c\":" + (c == null ? "null" : quote(c)) + "}");
				count++;
			}
		} finally {
			decompiler.dispose();
		}
		println("ExportDecompiled: " + count + " functions, " + failed + " failed, to " + outFile);
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
