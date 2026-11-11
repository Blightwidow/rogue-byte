// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2AB330-0X2AB3C8 (piece rodata/sdk_2aa7b0), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2AB330
extern const struct {
    char m0[52];
    char m1[4];
} D_002AB330 = {
    "sceGsDefDispEnv:Not support displaymode for 0x%x!!\012",
    ""
};

// data-ok: retail's bytes at 0X2AB368
extern const char D_002AB368[24] = "libdma: sync timeout\012";

// data-ok: retail's bytes at 0X2AB380
extern const unsigned int D_002AB380[10] = {1, 1, 1, 1, 1, 0, 0, 0, 1, 1};

// data-ok: retail's bytes at 0X2AB3A8
extern const unsigned char D_002AB3A8[16] = {0, 0, 0, 3, 0, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AB3B8
extern const unsigned char D_002AB3B8[16] = {0, 1, 2, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0};
