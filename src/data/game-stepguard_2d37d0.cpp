// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2D37D0-0X2D3838 (piece data/game-stepguard_2d37d0), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void HandleLoMessage();
extern "C" void OnLoAdd__FP2LO();
extern "C" void PauseMenu_Freeze();
extern "C" void PauseMenu_Hide();
extern "C" void PauseMenu_Show();
extern "C" void PauseMenu_Update();
extern "C" void PostLoMessage();
extern "C" void PostScriptMessage();
extern "C" void func_00113A10();
extern "C" void func_00132B08();
extern "C" void func_001AF388();

// data-ok: retail's bytes at 0X2D37D0
void *D_002D37D0[26] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113A10, 0, (void *)PauseMenu_Update, 0, (void *)func_001AF388, 0, (void *)PauseMenu_Freeze, 0, (void *)PauseMenu_Show, 0, (void *)PauseMenu_Hide, 0, 0};
