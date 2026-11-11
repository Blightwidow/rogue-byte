// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2AB330-0X2AB510 (piece rodata/sdk_2aa7b0), one global per Splat label: written by scripts/build/make_data_files.py,
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

// data-ok: retail's bytes at 0X2AB3C8
extern const unsigned char D_002AB3C8[80] = {0, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 115, 99, 101, 67, 100, 67, 98, 102, 117, 110, 99, 61, 32, 37, 100, 32, 115, 99, 101, 67, 100, 67, 98, 102, 117, 110, 99, 95, 110, 117, 109, 61, 32, 37, 100, 10, 0, 0, 0, 0, 83, 99, 101, 67, 100, 67, 97, 108, 108, 98, 97, 99, 107, 84, 104, 114, 101, 97, 100, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AB418
extern const char D_002AB418[16] = "SceCdNcmdSema";

// data-ok: retail's bytes at 0X2AB428
extern const char D_002AB428[16] = "SceCdScmdSema";

// data-ok: retail's bytes at 0X2AB438
extern const char D_002AB438[16] = "SceCdRcmdSema";

// data-ok: retail's bytes at 0X2AB448
extern const struct {
    char m0[20];
    char m1[4];
    char m2[32];
    char m3[24];
    char m4[16];
    char m5[16];
    char m6[20];
    char m7[4];
} D_002AB448 = {
    "SceCdCallbackSema",
    "",
    "Libcdvd bind err CdSearchFile\012",
    "ee call cmd search %s\012",
    "search name %s\012",
    "search size %d\012",
    "search loc lbn %d\012",
    ""
};

// data-ok: retail's bytes at 0X2AB4D0
extern const char D_002AB4D0[40] = "Ncmd fail sema cur_cmd:%d keep_cmd:%d\012";

// data-ok: retail's bytes at 0X2AB4F8
extern const char D_002AB4F8[24] = "Libcdvd bind err N CMD\012";
