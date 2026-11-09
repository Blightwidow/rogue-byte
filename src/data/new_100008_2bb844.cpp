// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB844-0X2BB858 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BB704[];
extern "C" void func_001133C0();

// data-ok: retail's bytes at 0X2BB844
void *D_002BB844[5] = {(void *)D_002BB704, (void *)171, (void *)172, (void *)224, (void *)func_001133C0};
