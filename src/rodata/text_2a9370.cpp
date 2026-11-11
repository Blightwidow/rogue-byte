// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2A9370-0X2A9380 (piece rodata/text), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2A9370
extern const struct {
    char m0[8];
    char m1[4];
    char m2[4];
} D_002A9370 = {
    "(null)",
    "",
    ""
};
