// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2A7878-0X2A7890 (piece rodata/new_1d7268), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2A7878
extern const struct {
    char m0[16];
    char m1[4];
    char m2[4];
} D_002A7878 = {
    "oidPoCurrent",
    "",
    ""
};
