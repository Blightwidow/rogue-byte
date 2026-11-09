// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BFCE0-0X2BFD38 (piece data/stepguard-sw), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void InitLoadingLogoThread();
extern "C" void InitSndSystem();
extern "C" void StartupBlips__Fv();
extern "C" void StartupDma__Fv();
extern "C" void StartupFont();
extern "C" void StartupFrame();
extern "C" void StartupGs__Fv();
extern "C" void StartupJoy__Fv();
extern "C" void StartupThread__Fv();
extern "C" void StaticInitClock();
extern "C" void func_0014B660();
extern "C" void func_0014BA30();
extern "C" void func_001A7890();
extern "C" void func_001A7900();
extern "C" void func_001AA978();
extern "C" void func_001AE168();
extern "C" void func_00211528();

// data-ok: retail's bytes at 0X2BFCE0
void *D_002BFCE0[20] = {(void *)StartupDma__Fv, (void *)StartupThread__Fv, (void *)0x1a7630, (void *)StartupGs__Fv, (void *)func_001AE168, (void *)func_0014BA30, (void *)func_0014B660, (void *)StartupFont, (void *)StartupJoy__Fv, (void *)StartupFrame, (void *)InitLoadingLogoThread, (void *)StaticInitClock, (void *)func_001A7890, (void *)func_001A7900, (void *)InitSndSystem, (void *)StartupBlips__Fv, (void *)func_00211528, (void *)func_001AA978, (void *)0x1b2940, 0};

// data-ok: retail's bytes at 0X2BFD30
float D_002BFD30 = 0.5f;

// data-ok: retail's bytes at 0X2BFD34
float D_002BFD34 = 0.5f;
