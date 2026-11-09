// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2CA8A0-0X2CA900 (piece data/ac), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void EvaluateAcgb();
extern "C" void ExplodeExploExplso__FP5EXPLOP6EXPLSO();
extern "C" void LoadAcgbFromBrx();
extern "C" void func_0012CC68();
extern "C" void func_0012CC98();
extern "C" void func_0023C820();

// data-ok: retail's bytes at 0X2CA8A0
void *D_002CA8A0[8] = {0, 0, 0, (void *)func_0012CC68, 0, (void *)func_0012CC98, 0, 0};

// data-ok: retail's bytes at 0X2CA8C0
void *D_002CA8C0[16] = {0, 0, 0, (void *)LoadAcgbFromBrx, 0, (void *)EvaluateAcgb, 0, 0, 0, 0, 0, (void *)ExplodeExploExplso__FP5EXPLOP6EXPLSO, 0, (void *)func_0023C820, 0, 0};
