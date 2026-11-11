// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2AA7F0-0X2AA870 (piece rodata/sdk_2aa7b0), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2AA7F0
extern const struct {
    char m0[24];
    char m1[4];
    char m2[4];
} D_002AA7F0 = {
    "SceKernelDelayThread",
    "",
    ""
};

// data-ok: retail's bytes at 0X2AA810
extern const char D_002AA810[8] = "0.%d";

// data-ok: retail's bytes at 0X2AA818
extern const char D_002AA818[8] = "e+%d";

// data-ok: retail's bytes at 0X2AA820
extern const struct {
    char m0[4];
    char m1[4];
} D_002AA820 = {
    "e%d",
    ""
};

// data-ok: retail's bytes at 0X2AA828
extern const unsigned int D_002AA828[2] = {0x9999999a, 0x3fb99999};

// data-ok: retail's bytes at 0X2AA830
extern const unsigned int D_002AA830[2] = {0x9999999a, 0x3fb99999};

// data-ok: retail's bytes at 0X2AA838
extern const unsigned int D_002AA838[2] = {0, 0x412e8480};

// data-ok: retail's bytes at 0X2AA840
extern const unsigned char D_002AA840[24] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 97, 98, 99, 100, 101, 102, 0, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AA858
extern const struct {
    char m0[20];
    char m1[4];
} D_002AA858 = {
    "0123456789ABCDEF",
    ""
};
