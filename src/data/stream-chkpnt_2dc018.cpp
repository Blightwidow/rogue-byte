// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2DC018-0X2DC070 (piece data/stream-chkpnt_2dc018), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void FlushRenderRecords();
extern "C" void HandleLoMessage();
extern "C" void OnLoAdd__FP2LO();
extern "C" void PostLoMessage();
extern "C" void PostScriptMessage();
extern "C" void UpdateSw();
extern "C" void func_00113A20();
extern "C" void func_00132B08();
extern "C" void func_001CDA80();

// data-ok: retail's bytes at 0X2DC018
void *D_002DC018[22] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113A20, 0, (void *)UpdateSw, 0, (void *)func_001CDA80, 0, (void *)FlushRenderRecords, 0, 0};
