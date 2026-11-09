// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BD910-0X2BD950 (piece data/cm-tn), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2BD910
unsigned int D_002BD910[12] = {0x43160000, 0, 0xc30c0000, 0, 0xc2960000, 0x43020000, 0xc30c0000, 0, 0xc2960000, 0xc3020000, 0xc30c0000, 0};

// data-ok: retail's bytes at 0X2BD940
unsigned int D_002BD940[4] = {0xc3480000, 0x43480000, 0, 0};
