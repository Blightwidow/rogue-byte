// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2CA5C0-0X2CA6A0 (piece data/bez-geom), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void CBinaryInputStream_Close();
extern "C" void HashTable_Clear_thunk();
extern "C" void Vector_Add();
extern "C" void Vector_Clear();
extern "C" void Vector_Init();
extern "C" void Vector_Load();
extern "C" void Vector_NotifyAdd();
extern "C" void func_00119BD0();
extern "C" void func_00119C08();
extern "C" void func_0023C820();
extern "C" void func_002566B0();
extern "C" void func_00256AF0();

// data-ok: retail's bytes at 0X2CA5C0
void *D_002CA5C0[56] = {0, 0, 0, (void *)func_0023C820, 0, (void *)CBinaryInputStream_Close, 0, 0, 0, 0, 0, (void *)func_00119BD0, 0, (void *)Vector_Clear, 0, (void *)Vector_Load, 0, (void *)func_00119C08, 0, (void *)Vector_Add, 0, (void *)Vector_NotifyAdd, 0, 0, 0, 0, 0, (void *)HashTable_Clear_thunk, 0, (void *)func_00256AF0, 0, 0, 0, 0, 0, (void *)func_0023C820, 0, (void *)func_0023C820, 0, 0, 0, 0, 0, (void *)Vector_Init, 0, (void *)Vector_Clear, 0, (void *)Vector_Load, 0, (void *)func_002566B0, 0, (void *)Vector_Add, 0, (void *)Vector_NotifyAdd, 0, 0};
