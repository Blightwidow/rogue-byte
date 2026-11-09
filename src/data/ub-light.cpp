// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BFB20-0X2BFC60 (piece data/ub-light), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002A68A0[];

// data-ok: retail's bytes at 0X2BFB20
float D_002BFB20 = 1.0f;

// data-ok: retail's bytes at 0X2BFB24
float D_002BFB24 = 0.3f;

// data-ok: retail's bytes at 0X2BFB28
unsigned int D_002BFB28[14] = {0xffffffff, 0, 0, 0, 0xffffffff, 0, 0, 0, 0, 0xffffffff, 8, 8, 5, 4};

// data-ok: retail's bytes at 0X2BFB60
unsigned int D_002BFB60[2] = {0, 0};

// data-ok: retail's bytes at 0X2BFB68
unsigned int D_002BFB68[2] = {0, 0};

// data-ok: retail's bytes at 0X2BFB70
unsigned int D_002BFB70[6] = {0, 1, 3, 4, 2, 0};

// data-ok: retail's bytes at 0X2BFB88
unsigned int D_002BFB88[12] = {0, 1, 3, 4, 2, 5, 6, 7, 8, 9, 10, 0};

// data-ok: retail's bytes at 0X2BFBB8
unsigned int D_002BFBB8[2] = {11, 0};

// data-ok: retail's bytes at 0X2BFBC0
struct {
    char m0[4];
    char m1[4];
} D_002BFBC0 = {
    "\014",
    ""
};

// data-ok: retail's bytes at 0X2BFBC8
struct {
    char m0[4];
    char m1[4];
} D_002BFBC8 = {
    "\015",
    ""
};

// data-ok: retail's bytes at 0X2BFBD0
void *D_002BFBD0[36] = {(void *)1, (void *)&D_002BFB60, (void *)1, (void *)&D_002BFB68, (void *)5, (void *)&D_002BFB70, (void *)11, (void *)&D_002BFB88, (void *)1, (void *)&D_002BFBB8, (void *)1, (void *)&D_002BFBC0, (void *)1, (void *)&D_002BFBC8, (void *)D_002A68A0, (void *)0x2a68a8, (void *)0x2a68b0, (void *)0x2a68b8, (void *)0x2a68c0, (void *)0x2a68c8, (void *)0x2a68d0, (void *)0x2a68e0, (void *)0x2a68e8, (void *)0x2a68f0, (void *)0x2a6900, (void *)0x2a6908, (void *)0x2a6918, (void *)0x2a6920, (void *)0x2a6948, (void *)0x2a6950, (void *)0x2a6958, (void *)0x2a6960, (void *)0x2a6970, (void *)0x2a6978, (void *)0x2a6980, 0};
