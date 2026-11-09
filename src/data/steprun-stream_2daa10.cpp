// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2DAA10-0X2DAA50 (piece data/steprun-stream_2daa10), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void HandleJumperMessage();
extern "C" void OnLoAdd__FP2LO();
extern "C" void PostLoMessage();
extern "C" void PostScriptMessage();
extern "C" void func_00114320();
extern "C" void func_00132B08();

// data-ok: retail's bytes at 0X2DAA10
void *D_002DAA10[16] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleJumperMessage, 0, (void *)func_00114320, 0, 0};
