// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2AB530-0X2AB680 (piece rodata/sdk_2aa7b0), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2AB530
extern const char D_002AB530[40] = "Scmd fail sema cur_cmd:%d keep_cmd:%d\012";

// data-ok: retail's bytes at 0X2AB558
extern const char D_002AB558[24] = "Libcdvd bind err S cmd\012";

// data-ok: retail's bytes at 0X2AB570
extern const char D_002AB570[32] = "Libcdvd bind err %d CD_Init %d\012";

// data-ok: retail's bytes at 0X2AB590
extern const char D_002AB590[16] = "Libcdvd Exit\012";

// data-ok: retail's bytes at 0X2AB5A0
extern const struct {
    char m0[20];
    char m1[4];
} D_002AB5A0 = {
    "OLD DiskReady Call\012",
    ""
};

// data-ok: retail's bytes at 0X2AB5B8
extern const unsigned int D_002AB5B8[8] = {0x6362694c, 0x20647664, 0x646e6962, 0x72726520, 0x44644320, 0x526b7369, 0x79646165, 10};

// data-ok: retail's bytes at 0X2AB5D8
extern const unsigned int D_002AB5D8[6] = {0x6b736944, 0x64616552, 0x6e652079, 0xa646564, 0, 0};

// data-ok: retail's bytes at 0X2AB5F0
extern const struct {
    char m0[20];
    char m1[4];
} D_002AB5F0 = {
    "NEW DiskReady Call\012",
    ""
};

// data-ok: retail's bytes at 0X2AB608
extern const struct {
    char m0[20];
    char m1[4];
} D_002AB608 = {
    "call cdread cmd\012",
    ""
};

// data-ok: retail's bytes at 0X2AB620
extern const struct {
    char m0[12];
    char m1[4];
    char m2[36];
    char m3[4];
    char m4[36];
    char m5[4];
} D_002AB620 = {
    "cdread end\012",
    "",
    "sceCdChgSys: Illegal_function_call\012",
    "",
    "libpad: tPadDma Structure Invalid\012",
    ""
};
