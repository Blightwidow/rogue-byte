// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2CA5A0-0X2CA5C0 (piece data/bis-sce-libs), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void CBinaryInputStream_Close();
extern "C" void func_001184E8();

// data-ok: retail's bytes at 0X2CA5A0
void *D_002CA5A0[8] = {0, 0, 0, (void *)func_001184E8, 0, (void *)CBinaryInputStream_Close, 0, 0};
