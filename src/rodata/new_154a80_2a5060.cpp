// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2A5060-0X2A50A0 (piece rodata/new_154a80), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2A5060
extern const char D_002A5060[16] = "suck_history";

// data-ok: retail's bytes at 0X2A5070
extern const struct {
    char m0[12];
    char m1[4];
} D_002A5070 = {
    "mission_0",
    ""
};

// data-ok: retail's bytes at 0X2A5080
extern const struct {
    char m0[12];
    char m1[4];
} D_002A5080 = {
    "mission_1",
    ""
};

// data-ok: retail's bytes at 0X2A5090
extern const struct {
    char m0[12];
    char m1[4];
} D_002A5090 = {
    "mission_2",
    ""
};
