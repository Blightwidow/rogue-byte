// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2A8298-0X2A83B8 (piece rodata/light-button), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void ContinueAmb();
extern "C" void PauseAmb();

// data-ok: retail's bytes at 0X2A8298
extern void *const D_002A8298[2] = {(void *)0xffff0000, (void *)PauseAmb};

// data-ok: retail's bytes at 0X2A82A0
extern void *const D_002A82A0[2] = {(void *)0xffff0000, (void *)ContinueAmb};

// data-ok: retail's bytes at 0X2A82A8
extern const unsigned int D_002A82A8[42] = {0xfffffffb, 0xfffffffb, 0xfffffffb, 0xfffffffb, 0xfffffffb, 0xfffffffb, 0xfffffffb, 0xfffffffb, 0xfffffffb, 0xfffffffb, 0xfffffffb, 1, 0xfffffffb, 0xfffffffb, 0xfffffffb, 0xfffffffb, 1, 1, 0xfffffffb, 0xfffffffb, 0xfffffffb, 1, 1, 1, 0xfffffffb, 0xfffffffb, 1, 1, 1, 1, 0xfffffffb, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

// data-ok: retail's bytes at 0X2A8350
extern const unsigned int D_002A8350[26] = {6, 6, 6, 6, 6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 3, 2, 1, 0, 0};
