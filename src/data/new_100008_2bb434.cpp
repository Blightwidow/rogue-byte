// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB434-0X2BB448 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAB10[];
extern "C" void func_00112A18();

// data-ok: retail's bytes at 0X2BB434
void *D_002BB434[5] = {(void *)D_002BAB10, (void *)119, (void *)120, (void *)176, (void *)func_00112A18};
