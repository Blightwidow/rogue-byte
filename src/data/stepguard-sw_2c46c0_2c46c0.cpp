// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2C46C0-0X2C48CC (piece data/stepguard-sw_2c46c0), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002C48CC[];
extern char D_002C4924[];
extern char D_002C497C[];

// data-ok: retail's bytes at 0X2C46C0
struct {
    char m0[8];
    char m1[16];
} D_002C46C0 = {
    "america",
    "08/13/04 00:32"
};

// data-ok: retail's bytes at 0X2C46D8
struct {
    char m0[12];
    char m1[4];
    char m2[4];
    void *m3[120];
} D_002C46D8 = {
    "0813.0032",
    "",
    "",
    {(void *)D_002C48CC, (void *)D_002C4924, (void *)D_002C497C, 0, 0, 0, 0, 0, 0, 0, 0, 0, (void *)0x2aa7a8, 0, 0, 0, 0, 0, 0, 0, 0, (void *)1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
