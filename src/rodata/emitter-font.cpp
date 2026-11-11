// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2A5160-0X2A5180 (piece rodata/emitter-font), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2A5160
extern const char D_002A5160[8] = "%d%%";

// data-ok: retail's bytes at 0X2A5168
extern const struct {
    char m0[12];
    char m1[4];
    char m2[4];
    char m3[4];
} D_002A5168 = {
    "%01d:%02d",
    "",
    "",
    ""
};
