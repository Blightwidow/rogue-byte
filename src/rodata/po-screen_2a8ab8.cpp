// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2A8AB8-0X2A8AF0 (piece rodata/po-screen), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2A8AB8
extern const struct {
    char m0[4];
    char m1[4];
} D_002A8AB8 = {
    "x%d",
    ""
};

// data-ok: retail's bytes at 0X2A8AC0
extern const char D_002A8AC0[8] = "x%5.3f";

// data-ok: retail's bytes at 0X2A8AC8
extern const struct {
    char m0[4];
    char m1[4];
} D_002A8AC8 = {
    "Far",
    ""
};

// data-ok: retail's bytes at 0X2A8AD0
extern const char D_002A8AD0[8] = "Near";

// data-ok: retail's bytes at 0X2A8AD8
extern const struct {
    char m0[8];
    char m1[8];
} D_002A8AD8 = {
    "YIKES",
    "&2S&."
};

// data-ok: retail's bytes at 0X2A8AE8
extern const char D_002A8AE8[8] = "ZRB.";
