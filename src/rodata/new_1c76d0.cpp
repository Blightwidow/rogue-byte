// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2A7768-0X2A77A0 (piece rodata/new_1c76d0), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2A7768
extern const unsigned int D_002A7768[2] = {0x6425, 0};

// data-ok: retail's bytes at 0X2A7770
extern const char D_002A7770[8] = "loot";

// data-ok: retail's bytes at 0X2A7778
extern const struct {
    char m0[12];
    char m1[4];
} D_002A7778 = {
    "mplootkc",
    ""
};

// data-ok: retail's bytes at 0X2A7788
extern const unsigned int D_002A7788[2] = {0x6c436661, 0x6575};

// data-ok: retail's bytes at 0X2A7790
extern const char D_002A7790[8] = "fVault";

// data-ok: retail's bytes at 0X2A7798
extern const float D_002A7798[2] = {3.4028235e+38f, 0.0f};
