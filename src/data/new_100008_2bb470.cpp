// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB470-0X2BB484 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAB10[];
extern "C" void func_00112AC0();

// data-ok: retail's bytes at 0X2BB470
void *D_002BB470[5] = {(void *)D_002BAB10, (void *)122, (void *)123, (void *)96, (void *)func_00112AC0};
