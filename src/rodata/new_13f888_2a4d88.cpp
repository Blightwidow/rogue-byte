// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2A4D88-0X2A4DE0 (piece rodata/new_13f888), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2A4D88
extern const char D_002A4D88[8] = "episode";

// data-ok: retail's bytes at 0X2A4D90
extern const char D_002A4D90[8] = "level";

// data-ok: retail's bytes at 0X2A4D98
extern const char D_002A4D98[8] = "booty";

// data-ok: retail's bytes at 0X2A4DA0
extern const char D_002A4DA0[16] = "aoidAssembly";

// data-ok: retail's bytes at 0X2A4DB0
extern const unsigned int D_002A4DB0[4] = {0x4264696f, 0x79746f6f, 0, 0};

// data-ok: retail's bytes at 0X2A4DC0
extern const char D_002A4DC0[8] = "loot";

// data-ok: retail's bytes at 0X2A4DC8
extern const struct {
    char m0[12];
    char m1[4];
    char m2[4];
    char m3[4];
} D_002A4DC8 = {
    "mplootkc",
    "",
    "",
    ""
};
