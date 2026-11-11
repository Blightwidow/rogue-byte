// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2AAD98-0X2AAE18 (piece rodata/sdk_2aa7b0), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2AAD98
extern const char D_002AAD98[56] = "# TLB spad=0 kernel=1:%d default=%d:%d extended=%d:%d\012";

// data-ok: retail's bytes at 0X2AADD0
extern const struct {
    char m0[20];
    char m1[4];
} D_002AADD0 = {
    "# TLB over flow (1)",
    ""
};

// data-ok: retail's bytes at 0X2AADE8
extern const struct {
    char m0[20];
    char m1[4];
} D_002AADE8 = {
    "# TLB over flow (2)",
    ""
};

// data-ok: retail's bytes at 0X2AAE00
extern const struct {
    char m0[20];
    char m1[4];
} D_002AAE00 = {
    "# TLB over flow (3)",
    ""
};
