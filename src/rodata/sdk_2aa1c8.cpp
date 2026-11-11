// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2AA1C8-0X2AA6A1 (piece rodata/sdk), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2AA1C8
extern const unsigned int D_002AA1C8[34] = {0x73393839, 0x632e646e, 0x5052203a, 0x6f632043, 0x73696c6c, 0x216e6f69, 10, 0, 0x73393839, 0x632e646e, 0x5052203a, 0x61632043, 0x68206c6c, 0x66207361, 0x656c6961, 0x6e692064, 0x65646973, 0x646e7320, 0x6e61425f, 0x616f4c6b, 0xa64, 0, 0x5f646e73, 0x6b6e6142, 0x64616f4c, 0x3a42435f, 0x616f4c20, 0x6c612064, 0x64616572, 0x6e692079, 0x6f727020, 0x73657267, 0xa2173, 0};

// data-ok: retail's bytes at 0X2AA250
extern const char D_002AA250[48] = "snd_BankLoadByLoc: Load already in progress!\012";

// data-ok: retail's bytes at 0X2AA280
extern const char D_002AA280[32] = "snd_BankLoadByLoc: CD BUSY!\012";

// data-ok: retail's bytes at 0X2AA2A0
extern const struct {
    char m0[56];
    char m1[48];
    char m2[60];
    char m3[4];
    char m4[52];
    char m5[4];
    char m6[48];
    char m7[60];
    char m8[4];
    char m9[52];
    char m10[4];
    char m11[60];
    char m12[4];
    char m13[60];
    char m14[4];
    char m15[40];
    char m16[44];
    char m17[4];
    char m18[48];
    char m19[28];
    char m20[4];
    char m21[48];
    char m22[32];
} D_002AA2A0 = {
    "989snd.c: RPC call has failed inside snd_BankLoadByLoc\012",
    "snd_BankLoadFromEE: Load already in progress!\012",
    "989snd.c: RPC call has failed inside snd_BankLoadFromEE\012",
    "",
    "snd_BankLoadFromEE_CB: Load already in progress!\012",
    "",
    "snd_BankLoadFromIOP: Load already in progress!\012",
    "989snd.c: RPC call has failed inside snd_BankLoadFromIOP\012",
    "",
    "snd_BankLoadFromIOP_CB: Load already in progress!\012",
    "",
    "snd_BankLoadFromIOPPartialEx: Load already in progress!\012",
    "",
    "snd_BankLoadFromIOPPartialEx_CB: Load already in progress!\012",
    "",
    "snd_MMDLoad: Load already in progress!\012",
    "snd_MMDLoad_CB: Load already in progress!\012",
    "",
    "snd_MMDLoadByLoc: Load already in progress!\012",
    "snd_MMDLoadByLoc: CD BUSY!\012",
    "",
    "snd_MMDLoadByLoc_CB: Load already in progress!\012",
    "snd_MMDLoadByLoc_CB: CD BUSY!\012"
};

// data-ok: retail's bytes at 0X2AA5A0
extern const struct {
    char m0[68];
    char m1[4];
} D_002AA5A0 = {
    "989snd ERROR: cannot send external command larger then 500 bytes!\012",
    ""
};

// data-ok: retail's bytes at 0X2AA5E8
extern const struct {
    char m0[36];
    char m1[4];
} D_002AA5E8 = {
    "989snd ERROR: command too large!\012",
    ""
};

// data-ok: retail's bytes at 0X2AA610
extern const char D_002AA610[96] = "snd_SendIOPCommandNoWait: BUFFER %d FULL(%d)! Sound stalled waiting for IOP comands to finish!\012";

// data-ok: retail's bytes at 0X2AA670
extern const struct {
    char m0[44];
    char m1[5];
} D_002AA670 = {
    "snd_SendIOPCommandNoWait: continuing (%d).\012",
    ""
};
