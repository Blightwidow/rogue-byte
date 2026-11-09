// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2D36D0-0X2D37D0 (piece data/memcard-memory), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void BusyMenu_SetDir();
extern "C" void BusyMenu_Update();
extern "C" void CGc_PopScreen();
extern "C" void CGc_PushScreen();
extern "C" void HandleLoMessage();
extern "C" void MemcardMenu_PostLoad();
extern "C" void MemcardMenu_Reset();
extern "C" void MemcardMenu_SetDir();
extern "C" void MemcardMenu_Update();
extern "C" void Menu_PostLoad();
extern "C" void Menu_Reset();
extern "C" void OnLoAdd__FP2LO();
extern "C" void PostLoMessage();
extern "C" void PostScriptMessage();
extern "C" void func_00113A10();
extern "C" void func_00132B08();
extern "C" void func_001D9878();
extern "C" void func_001D98A8();

// data-ok: retail's bytes at 0X2D36D0
void *D_002D36D0[32] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113A10, 0, (void *)BusyMenu_Update, 0, (void *)func_001D9878, 0, (void *)func_001D98A8, 0, (void *)CGc_PushScreen, 0, (void *)CGc_PopScreen, 0, (void *)Menu_PostLoad, 0, (void *)Menu_Reset, 0, (void *)BusyMenu_SetDir, 0, 0};

// data-ok: retail's bytes at 0X2D3750
void *D_002D3750[32] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113A10, 0, (void *)MemcardMenu_Update, 0, (void *)func_001D9878, 0, (void *)func_001D98A8, 0, (void *)CGc_PushScreen, 0, (void *)CGc_PopScreen, 0, (void *)MemcardMenu_PostLoad, 0, (void *)MemcardMenu_Reset, 0, (void *)MemcardMenu_SetDir, 0, 0};
