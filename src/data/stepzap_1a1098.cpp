// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BFA30-0X2BFA90 (piece data/stepzap_1a1098), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2BFA30
struct {
    char m0[4];
    unsigned int m1[23];
} D_002BFA30 = {
    "\015",
    {0x41f00000, 0, 12, 0x41f00000, 0, 19, 0x41f00000, 0, 18, 0x41f00000, 0, 22, 0x42700000, 0, 247, 0x41f00000, 0, 0x13d, 0x41f00000, 0, 0, 0, 0}
};
