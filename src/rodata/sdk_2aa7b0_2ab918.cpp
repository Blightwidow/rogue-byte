// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2AB918-0X2AB938 (piece rodata/sdk_2aa7b0), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2AB918
extern const unsigned int D_002AB918[2] = {0x66776f70, 0};

// data-ok: retail's bytes at 0X2AB920
extern const unsigned int D_002AB920[2] = {0, 0x7ff80000};

// data-ok: retail's bytes at 0X2AB928
extern const unsigned int D_002AB928[2] = {0xe0000000, 0x47efffff};

// data-ok: retail's bytes at 0X2AB930
extern const unsigned int D_002AB930[2] = {0xe0000000, 0xc7efffff};
