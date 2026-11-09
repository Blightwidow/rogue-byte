// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB330-0X2BB344 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAEA8[];
extern "C" void func_001126E0();

// data-ok: retail's bytes at 0X2BB330
void *D_002BB330[5] = {(void *)D_002BAEA8, (void *)106, (void *)107, (void *)0x160, (void *)func_001126E0};
