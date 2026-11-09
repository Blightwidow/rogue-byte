// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB1DC-0X2BB1F0 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAEA8[];
extern "C" void func_00112160();

// data-ok: retail's bytes at 0X2BB1DC
void *D_002BB1DC[5] = {(void *)D_002BAEA8, (void *)89, (void *)90, (void *)0x190, (void *)func_00112160};
