// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2D8368-0X2D8568 (piece data/game-stepguard_2d8368), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void CGc_PopScreen();
extern "C" void CGc_PushScreen();
extern "C" void HandleLoMessage();
extern "C" void JobMenu_PostLoad();
extern "C" void JobMenu_Reset();
extern "C" void JobMenu_SetDirection();
extern "C" void JobMenu_Update();
extern "C" void Menu52D_SetDirection();
extern "C" void Menu_PostLoad();
extern "C" void Menu_Reset();
extern "C" void Menu_Update();
extern "C" void OnLoAdd__FP2LO();
extern "C" void PostLoMessage();
extern "C" void PostScriptMessage();
extern "C" void ShopMenu_Reset();
extern "C" void ShopMenu_SetDirection();
extern "C" void ShopMenu_Update();
extern "C" void TitleMenu_SetDirection();
extern "C" void TitleMenu_Update();
extern "C" void func_00113A10();
extern "C" void func_00132B08();
extern "C" void func_001D9878();
extern "C" void func_001D98A8();
extern "C" void func_001DD690();

// data-ok: retail's bytes at 0X2D8368
void *D_002D8368[32] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113A10, 0, (void *)TitleMenu_Update, 0, (void *)func_001D9878, 0, (void *)func_001D98A8, 0, (void *)CGc_PushScreen, 0, (void *)CGc_PopScreen, 0, (void *)Menu_PostLoad, 0, (void *)Menu_Reset, 0, (void *)TitleMenu_SetDirection, 0, 0};

// data-ok: retail's bytes at 0X2D83E8
void *D_002D83E8[32] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113A10, 0, (void *)Menu_Update, 0, (void *)func_001D9878, 0, (void *)func_001D98A8, 0, (void *)CGc_PushScreen, 0, (void *)CGc_PopScreen, 0, (void *)func_001DD690, 0, (void *)Menu_Reset, 0, (void *)Menu52D_SetDirection, 0, 0};

// data-ok: retail's bytes at 0X2D8468
void *D_002D8468[32] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113A10, 0, (void *)JobMenu_Update, 0, (void *)func_001D9878, 0, (void *)func_001D98A8, 0, (void *)CGc_PushScreen, 0, (void *)CGc_PopScreen, 0, (void *)JobMenu_PostLoad, 0, (void *)JobMenu_Reset, 0, (void *)JobMenu_SetDirection, 0, 0};

// data-ok: retail's bytes at 0X2D84E8
void *D_002D84E8[32] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113A10, 0, (void *)ShopMenu_Update, 0, (void *)func_001D9878, 0, (void *)func_001D98A8, 0, (void *)CGc_PushScreen, 0, (void *)CGc_PopScreen, 0, (void *)Menu_PostLoad, 0, (void *)ShopMenu_Reset, 0, (void *)ShopMenu_SetDirection, 0, 0};
