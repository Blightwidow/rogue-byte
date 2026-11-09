// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB538-0X2BB54C (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAB10[];
extern "C" void func_00112D38();

// data-ok: retail's bytes at 0X2BB538
void *D_002BB538[5] = {(void *)D_002BAB10, (void *)132, (void *)133, (void *)0x100, (void *)func_00112D38};
