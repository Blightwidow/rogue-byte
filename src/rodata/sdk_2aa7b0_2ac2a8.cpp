// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2AC2A8-0X2AC3C0 (piece rodata/sdk_2aa7b0), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2AC2A8
extern const struct {
    char m0[36];
    char m1[4];
} D_002AC2A8 = {
    "internal alignment error. _bstag:%d",
    ""
};

// data-ok: retail's bytes at 0X2AC2D0
extern const struct {
    char m0[36];
    char m1[4];
} D_002AC2D0 = {
    "internal alignment error. _idct:%d",
    ""
};

// data-ok: retail's bytes at 0X2AC2F8
extern const struct {
    char m0[36];
    char m1[4];
} D_002AC2F8 = {
    "The size of work area is too small",
    ""
};

// data-ok: retail's bytes at 0X2AC320
extern const struct {
    char m0[60];
    char m1[4];
} D_002AC320 = {
    "image buffer needs to be aligned to 64byte boundary(0x%08x)",
    ""
};

// data-ok: retail's bytes at 0X2AC360
extern const char D_002AC360[64] = "Need to re-setup libipu since sceMpegGetPicture was aborted\012";

// data-ok: retail's bytes at 0X2AC3A0
extern const char D_002AC3A0[32] = "sceMpegGetPicture is aborted\012";
