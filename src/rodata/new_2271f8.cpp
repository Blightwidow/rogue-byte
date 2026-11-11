// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2A97F0-0X2A9890 (piece rodata/new_2271f8), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2A97F0
extern const struct {
    char m0[4];
    char m1[4];
} D_002A97F0 = {
    "|",
    ""
};

// data-ok: retail's bytes at 0X2A97F8
extern const struct {
    char m0[4];
    char m1[4];
    char m2[4];
    char m3[4];
    unsigned int m4[28];
} D_002A97F8 = {
    "@",
    "X",
    " ",
    "O",
    {16, 84, 128, 83, 0x800, 33, 0x100, 95, 0x1000, 94, 0x4000, 118, 0x8000, 60, 0x2000, 62, 4, 76, 1, 108, 0x200, 40, 8, 82, 2, 114, 0x400, 41}
};

// data-ok: retail's bytes at 0X2A9878
extern const char D_002A9878[8] = "&2%c&.";

// data-ok: retail's bytes at 0X2A9880
extern const float D_002A9880[4] = {-3.4028235e+38f, 0.0f, 0.0f, 0.0f};
