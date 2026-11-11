// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2A9460-0X2A9490 (piece rodata/text), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2A9460
extern const short D_002A9460[4] = {45, 0, 0, 0};

// data-ok: retail's bytes at 0X2A9468
extern const short D_002A9468[4] = {43, 0, 0, 0};

// data-ok: retail's bytes at 0X2A9470
extern const short D_002A9470[4] = {32, 0, 0, 0};

// data-ok: retail's bytes at 0X2A9478
extern const unsigned int D_002A9478[2] = {0x6230, 0};

// data-ok: retail's bytes at 0X2A9480
extern const short D_002A9480[4] = {48, 0, 0, 0};

// data-ok: retail's bytes at 0X2A9488
extern const unsigned int D_002A9488[2] = {0x7830, 0};
