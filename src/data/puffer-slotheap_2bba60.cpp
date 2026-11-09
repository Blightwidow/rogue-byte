// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BBA60-0X2BBAF0 (piece data/puffer-slotheap), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BB704[];
extern "C" void func_001139D8();
extern "C" void func_00116CA0();
extern "C" void func_00116CC0();
extern "C" void func_00116CE0();
extern "C" void func_00116D00();

// data-ok: retail's bytes at 0X2BBA60
void *D_002BBA60[36] = {(void *)D_002BB704, (void *)198, (void *)199, (void *)64, (void *)func_001139D8, 0, 0, 0, 0, 0, 0, 0, (void *)func_00116CA0, 0, 0, 0, (void *)func_00116CC0, 0, 0, 0, (void *)func_00116CE0, 0, 0, 0, (void *)func_00116D00, 0, 0, 0, 0, 0, 0, (void *)0xccbebc20, 0, 0, 0, 0};
