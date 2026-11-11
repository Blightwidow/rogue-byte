// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2A94F0-0X2A9530 (piece rodata/text), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2A94F0
extern const char D_002A94F0[8] = "(nan)";

// data-ok: retail's bytes at 0X2A94F8
extern const char D_002A94F8[8] = "(inf)";

// data-ok: retail's bytes at 0X2A9500
extern const unsigned int D_002A9500[2] = {10, 0};

// data-ok: retail's bytes at 0X2A9508
extern const struct {
    char m0[4];
    char m1[4];
} D_002A9508 = {
    ",\012",
    ""
};

// data-ok: retail's bytes at 0X2A9510
extern const struct {
    char m0[4];
    char m1[4];
} D_002A9510 = {
    "{ ",
    ""
};

// data-ok: retail's bytes at 0X2A9518
extern const struct {
    char m0[4];
    char m1[4];
} D_002A9518 = {
    ", ",
    ""
};

// data-ok: retail's bytes at 0X2A9520
extern const struct {
    char m0[4];
    char m1[4];
    char m2[4];
    char m3[4];
} D_002A9520 = {
    " }",
    "",
    "",
    ""
};
