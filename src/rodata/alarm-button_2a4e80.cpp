// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2A4E80-0X2A4E87 (piece rodata/alarm-button), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2A4E80
extern const struct {
    unsigned int m0;
    unsigned char m1[3];
} D_002A4E80 = {
    0xffff0000,
    {16, 144, 20}
};
