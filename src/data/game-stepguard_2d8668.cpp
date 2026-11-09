// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2D8668-0X2D8738 (piece data/game-stepguard_2d8668), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void CGc_PopScreen();
extern "C" void CGc_PushScreen();
extern "C" void HandleLoMessage();
extern "C" void OnLoAdd__FP2LO();
extern "C" void PostLoMessage();
extern "C" void PostScriptMessage();
extern "C" void UpdateMeter();
extern "C" void func_00113A10();
extern "C" void func_00132B08();
extern "C" void func_001D9870();
extern "C" void func_001D9878();
extern "C" void func_001D98A8();

// data-ok: retail's bytes at 0X2D8668
void *D_002D8668[52] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113A10, 0, (void *)UpdateMeter, 0, (void *)func_001D9878, 0, (void *)func_001D98A8, 0, (void *)CGc_PushScreen, 0, (void *)CGc_PopScreen, 0, 0, 0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113A10, 0, (void *)func_001D9870, 0, (void *)func_001D9878, 0, (void *)func_001D98A8, 0, (void *)CGc_PushScreen, 0, (void *)CGc_PopScreen, 0, 0};
