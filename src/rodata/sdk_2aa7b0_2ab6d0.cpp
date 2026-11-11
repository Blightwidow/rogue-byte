// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2AB6D0-0X2AB8F0 (piece rodata/sdk_2aa7b0), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2AB6D0
extern const struct {
    char m0[28];
    char m1[4];
} D_002AB6D0 = {
    "libpad: sceSifSetDma faild\012",
    ""
};

// data-ok: retail's bytes at 0X2AB6F0
extern const char D_002AB6F0[48] = "libpad: buffer addr is not 64 byte align. %08x\012";

// data-ok: retail's bytes at 0X2AB720
extern const struct {
    char m0[44];
    char m1[4];
    char m2[8];
    char m3[8];
    char m4[8];
    char m5[12];
    char m6[4];
    char m7[4];
    char m8[4];
    char m9[12];
    char m10[4];
    char m11[8];
    char m12[8];
    char m13[12];
    char m14[4];
} D_002AB720 = {
    "libpad: pad port is already open [%d][%d]\012",
    "",
    "ERROR",
    "STABLE",
    "EXECCMD",
    "FINDCTP1",
    "",
    "",
    "",
    "DISCONNECT",
    "",
    "BUSY",
    "FAILED",
    "COMPLETE",
    ""
};

// data-ok: retail's bytes at 0X2AB7B0
extern const char D_002AB7B0[16] = "sceMc_sema_regs";

// data-ok: retail's bytes at 0X2AB7C0
extern const struct {
    char m0[20];
    char m1[4];
} D_002AB7C0 = {
    "sceMc_sema_timer",
    ""
};

// data-ok: retail's bytes at 0X2AB7D8
extern const unsigned int D_002AB7D8[6] = {0x646e6962, 0x72726520, 0x6c20726f, 0x636d6269, 0xa20, 0};

// data-ok: retail's bytes at 0X2AB7F0
extern const char D_002AB7F0[40] = "libmc: too old release of mcserv.irx\012";

// data-ok: retail's bytes at 0X2AB818
extern const struct {
    char m0[40];
    char m1[32];
} D_002AB818 = {
    "libmc: too old release of mcman.irx\012",
    "sceMcUdCheckNewCard RPC faild\012"
};

// data-ok: retail's bytes at 0X2AB860
extern const float D_002AB860[3] = {0.4636476f, 0.7853981f, 0.9827937f};

// data-ok: retail's bytes at 0X2AB86C
extern const float D_002AB86C = 1.5707963f;

// data-ok: retail's bytes at 0X2AB870
extern const float D_002AB870[3] = {5.0121582e-09f, 3.7748947e-08f, 3.4473217e-08f};

// data-ok: retail's bytes at 0X2AB87C
extern const float D_002AB87C = 7.5497894e-08f;

// data-ok: retail's bytes at 0X2AB880
extern const float D_002AB880[16] = {0.33333334f, -0.2f, 0.14285715f, -0.111111104f, 0.09090887f, -0.07691876f, 0.06661073f, -0.058335703f, 0.04976878f, -0.03653157f, 0.01628582f, 1.0f, 1e+30f, 1.0f, 1e+30f, 0.0f};

// data-ok: retail's bytes at 0X2AB8C0
extern const char D_002AB8C0[8] = "log10";

// data-ok: retail's bytes at 0X2AB8C8
extern const unsigned int D_002AB8C8[2] = {0xe0000000, 0xc7efffff};

// data-ok: retail's bytes at 0X2AB8D0
extern const unsigned int D_002AB8D0[2] = {0x776f70, 0};

// data-ok: retail's bytes at 0X2AB8D8
extern const unsigned int D_002AB8D8[2] = {0, 0x7ff80000};

// data-ok: retail's bytes at 0X2AB8E0
extern const unsigned int D_002AB8E0[2] = {0xe0000000, 0x47efffff};

// data-ok: retail's bytes at 0X2AB8E8
extern const unsigned int D_002AB8E8[2] = {0xe0000000, 0xc7efffff};
