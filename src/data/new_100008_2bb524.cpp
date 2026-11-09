// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB524-0X2BB538 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BB4C0[];
extern "C" void func_00112CF8();

// data-ok: retail's bytes at 0X2BB524
void *D_002BB524[5] = {(void *)D_002BB4C0, (void *)131, (void *)132, (void *)0x140, (void *)func_00112CF8};
