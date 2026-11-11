// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2A7A70-0X2A7A80 (piece rodata/game-stepguard), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2A7A70
extern const struct {
    char m0[4];
    char m1[4];
    char m2[4];
    char m3[4];
} D_002A7A70 = {
    "\012",
    "",
    "",
    ""
};
