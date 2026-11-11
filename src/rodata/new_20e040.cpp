// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2A39E8-0X2A3A10 (piece rodata/new_20e040), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002A8918[];
extern char D_002A8920[];
extern char D_002A8930[];
extern char D_002A8938[];
extern char D_002A8940[];
extern char D_002A8948[];
extern char D_002A8950[];
extern char D_002A8958[];
extern char D_002A8960[];

// data-ok: retail's bytes at 0X2A39E8
extern void *const D_002A39E8[10] = {(void *)D_002A8918, (void *)D_002A8920, (void *)D_002A8930, (void *)D_002A8938, (void *)D_002A8940, (void *)D_002A8948, (void *)D_002A8950, (void *)D_002A8958, (void *)D_002A8960, 0};
