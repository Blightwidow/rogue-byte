// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BF670-0X2BF70C (piece data/stephide), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2BF670
struct {
    char m0[4];
    char m1[4];
    char m2[4];
    char m3[4];
    char m4[4];
    unsigned int m5[31];
} D_002BF670 = {
    "0",
    "",
    "",
    "",
    "",
    {0x3f800000, 0, 0, 0xc3610000, 0x3f800000, 0, 0, 0x41a00000, 0x3f800000, 0, 0, 0xff7fffff, 0x7f7fffff, 0xff7fffff, 0x7f7fffff, 0xff7fffff, 0x7f7fffff, 0, 0, 0x3f800000, 0, 0x3f800000, 0, 0x3f800000, 0x3f800000, 0x3f800000, 0, 0x3f800000, 0x3f800000, 0xff7fffff, 0x7f7fffff}
};

// data-ok: retail's bytes at 0X2BF700
unsigned int D_002BF700[3] = {0x451c4000, 0, 0x3f800000};
