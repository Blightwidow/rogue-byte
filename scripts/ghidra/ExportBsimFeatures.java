// SPDX-License-Identifier: GPL-3.0-or-later
// Exports the BSim feature hashes of every function (decompiler p-code data-flow features, which mostly survive a
// change of compiler) as one JSON line per function: {"entry":..., "features":[...]}. scripts/names/match.py compares them itself.
// Headless: -process <program> -noanalysis -postScript ExportBsimFeatures.java <out.jsonl>
//@category Sly
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.signature.SignatureResult;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;

import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

public class ExportBsimFeatures extends GhidraScript {
	// the settings DumpBSimSignaturesScript uses (BSim's default feature set)
	private static final int SIGNATURE_SETTINGS = 0x4d;

	@Override
	public void run() throws Exception {
		Path outFile = Path.of(getScriptArgs()[0]);
		DecompInterface decompiler = new DecompInterface();
		int count = 0;
		int failed = 0;
		try (PrintWriter out = new PrintWriter(Files.newBufferedWriter(outFile, StandardCharsets.UTF_8))) {
			decompiler.setOptions(new DecompileOptions());
			decompiler.toggleSyntaxTree(false);
			decompiler.setSignatureSettings(SIGNATURE_SETTINGS);
			if (!decompiler.openProgram(currentProgram)) {
				throw new IllegalStateException("decompiler: " + decompiler.getLastMessage());
			}
			for (Function function : currentProgram.getFunctionManager().getFunctions(true)) {
				monitor.checkCancelled();
				SignatureResult result = decompiler.generateSignatures(function, false, 30, monitor);
				if (result == null) {
					failed++;
					continue;
				}
				List<String> features = new ArrayList<>();
				for (int feature : result.features) {
					features.add(Integer.toString(feature));
				}
				out.println("{\"entry\":" + function.getEntryPoint().getOffset() + ",\"features\":[" + String.join(",", features) + "]}");
				count++;
			}
		} finally {
			decompiler.closeProgram();
			decompiler.dispose();
		}
		println("ExportBsimFeatures: " + count + " functions, " + failed + " failed, to " + outFile);
	}
}
