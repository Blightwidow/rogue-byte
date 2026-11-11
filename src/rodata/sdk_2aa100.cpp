// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2AA100-0X2AA140 (piece rodata/sdk), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2AA100
extern const unsigned int D_002AA100[10] = {0x6f727265, 0x73203a72, 0x69536563, 0x6e694266, 0x63705264, 0x206e6920, 0x202c7325, 0x6c207461, 0x20656e69, 0xa6425};

// data-ok: retail's bytes at 0X2AA128
extern const unsigned int D_002AA128[6] = {0x765c3a63, 0x705c7373, 0x38392f33, 0x646e7339, 0x7070632e, 0};
