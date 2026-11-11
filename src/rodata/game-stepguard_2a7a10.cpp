// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2A7A10-0X2A7A50 (piece rodata/game-stepguard), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2A7A10
extern const unsigned char D_002A7A10[8] = {0, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2A7A18
extern const struct {
    char m0[12];
    char m1[4];
} D_002A7A18 = {
    "%s%s%s. %s",
    ""
};

// data-ok: retail's bytes at 0X2A7A28
extern const struct {
    char m0[4];
    char m1[4];
} D_002A7A28 = {
    ": ",
    ""
};

// data-ok: retail's bytes at 0X2A7A30
extern const char D_002A7A30[8] = "%s (%d)";

// data-ok: retail's bytes at 0X2A7A38
extern const struct {
    char m0[12];
    char m1[4];
    char m2[4];
    char m3[4];
} D_002A7A38 = {
    "%s: %s. %s",
    "",
    "",
    ""
};
