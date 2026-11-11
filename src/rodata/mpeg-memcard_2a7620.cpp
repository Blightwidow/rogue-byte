// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2A7620-0X2A7637 (piece rodata/mpeg-memcard), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2A7620
extern const float D_002A7620[4] = {3.4028235e+38f, 0.0f, 0.0f, 0.0f};

// data-ok: retail's bytes at 0X2A7630
extern const struct {
    unsigned int m0;
    unsigned char m1[3];
} D_002A7630 = {
    0xffff0000,
    {0, 180, 27}
};
