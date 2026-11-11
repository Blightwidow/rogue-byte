// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2AAAB0-0X2AAB28 (piece rodata/sdk_2aa7b0), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2AAAB0
extern const struct {
    char m0[20];
    char m1[4];
} D_002AAAB0 = {
    "SceStdioOpenSema",
    ""
};

// data-ok: retail's bytes at 0X2AAAC8
extern const struct {
    char m0[20];
    char m1[4];
    char m2[20];
    char m3[4];
} D_002AAAC8 = {
    "SceStdioCloseSema",
    "",
    "SceStdioLseekSema",
    ""
};

// data-ok: retail's bytes at 0X2AAAF8
extern const struct {
    char m0[20];
    char m1[4];
} D_002AAAF8 = {
    "SceStdioReadSema",
    ""
};

// data-ok: retail's bytes at 0X2AAB10
extern const struct {
    char m0[20];
    char m1[4];
} D_002AAB10 = {
    "SceStdioWriteSema",
    ""
};
