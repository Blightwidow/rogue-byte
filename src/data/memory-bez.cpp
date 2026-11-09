// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2CA578-0X2CA5A0 (piece data/memory-bez), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void PvAllocSwAlign16();
extern "C" void func_00116A58();
extern "C" void func_00116A90();

// data-ok: retail's bytes at 0X2CA578
void *D_002CA578[10] = {0, 0, 0, (void *)PvAllocSwAlign16, 0, (void *)func_00116A58, 0, (void *)func_00116A90, 0, 0};
