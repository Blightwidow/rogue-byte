// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2A7637-0X2A7640 (piece rodata/mpeg-memcard), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2A7637
extern const struct {
    unsigned char m0;
    unsigned int m1[2];
} D_002A7637 = {
    0,
    {0, 0}
};
