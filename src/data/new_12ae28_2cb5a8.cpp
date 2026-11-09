// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2CB5A8-0X2CB5D8 (piece data/new_12ae28_2cb5a8), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void EvaluateAcpbl();
extern "C" void EvaluateAcsb__FP4ACSBP3ALOfiP7MATRIX3();
extern "C" void func_0012B4F0();
extern "C" void func_002581B8();

// data-ok: retail's bytes at 0X2CB5A8
void *D_002CB5A8[12] = {0, 0, 0, (void *)func_0012B4F0, 0, (void *)EvaluateAcsb__FP4ACSBP3ALOfiP7MATRIX3, 0, (void *)EvaluateAcpbl, 0, (void *)func_002581B8, 0, 0};
