// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2AC3D8-0X2AC418 (piece rodata/sdk_2aa7b0), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2AC3D8
extern const char D_002AC3D8[32] = "odd number of field pictures";

// data-ok: retail's bytes at 0X2AC3F8
extern const struct {
    char m0[28];
    char m1[4];
} D_002AC3F8 = {
    "unknown picture sutructure",
    ""
};
