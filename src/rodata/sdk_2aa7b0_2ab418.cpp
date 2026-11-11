// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2AB418-0X2AB510 (piece rodata/sdk_2aa7b0), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

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
