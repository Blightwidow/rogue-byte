// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2AC510-0X2AC728 (piece rodata/sdk_2aa7b0), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2AC510
extern const char D_002AC510[32] = "(a) invalid motion_type(%d)-0";

// data-ok: retail's bytes at 0X2AC530
extern const char D_002AC530[32] = "(b) invalid motion_type(%d)-1";

// data-ok: retail's bytes at 0X2AC550
extern const char D_002AC550[32] = "(c) invalid motion_type(%d)-2";

// data-ok: retail's bytes at 0X2AC570
extern const struct {
    char m0[36];
    char m1[4];
} D_002AC570 = {
    "Invalid modion type -- ignored(%d)",
    ""
};

// data-ok: retail's bytes at 0X2AC598
extern const struct {
    char m0[20];
    char m1[4];
} D_002AC598 = {
    "intra && skip MB",
    ""
};

// data-ok: retail's bytes at 0X2AC5B0
extern const char D_002AC5B0[32] = "= Skip to the next picture =";

// data-ok: retail's bytes at 0X2AC5D0
extern const char D_002AC5D0[32] = "Too many macroblocks in picture";

// data-ok: retail's bytes at 0X2AC5F0
extern const char D_002AC5F0[48] = "skiped macroblock in I picure is not allowed";

// data-ok: retail's bytes at 0X2AC620
extern const char D_002AC620[32] = "Invalid macroblock_type code: 0";

// data-ok: retail's bytes at 0X2AC640
extern const unsigned int D_002AC640[14] = {0x61766e49, 0x2064696c, 0x7263616d, 0x6f6c626f, 0x615f6b63, 0x65726464, 0x695f7373, 0x6572636e, 0x746e656d, 0x646f6320, 0x78302865, 0x78383025, 41, 0};

// data-ok: retail's bytes at 0X2AC678
extern const char D_002AC678[40] = "slice_start_code(0x%08x) out of range";

// data-ok: retail's bytes at 0X2AC6A0
extern const struct {
    char m0[36];
    char m1[4];
} D_002AC6A0 = {
    "_sceMpegSliceA0(): error happens",
    ""
};

// data-ok: retail's bytes at 0X2AC6C8
extern const char D_002AC6C8[24] = "vertical size > 2800";

// data-ok: retail's bytes at 0X2AC6E0
extern const struct {
    char m0[36];
    char m1[4];
} D_002AC6E0 = {
    "_chroma_format needs to be 1: 420",
    ""
};

// data-ok: retail's bytes at 0X2AC708
extern const struct {
    char m0[28];
    char m1[4];
} D_002AC708 = {
    "Unsupported profile/level",
    ""
};
