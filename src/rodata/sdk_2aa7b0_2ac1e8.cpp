// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2AC1E8-0X2AC290 (piece rodata/sdk_2aa7b0), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2AC1E8
extern const unsigned int D_002AC1E8[2] = {0, 0xfff00000};

// data-ok: retail's bytes at 0X2AC1F0
extern const unsigned int D_002AC1F0[2] = {0xfee00000, 0x3fe62e42};

// data-ok: retail's bytes at 0X2AC1F8
extern const unsigned int D_002AC1F8[2] = {0x35793c76, 0x3dea39ef};

// data-ok: retail's bytes at 0X2AC200
extern const unsigned int D_002AC200[2] = {0x55555555, 0x3fd55555};

// data-ok: retail's bytes at 0X2AC208
extern const unsigned int D_002AC208[2] = {0xfee00000, 0x3fe62e42};

// data-ok: retail's bytes at 0X2AC210
extern const unsigned int D_002AC210[2] = {0x35793c76, 0x3dea39ef};

// data-ok: retail's bytes at 0X2AC218
extern const unsigned int D_002AC218[2] = {0xd078c69f, 0x3fc39a09};

// data-ok: retail's bytes at 0X2AC220
extern const unsigned int D_002AC220[2] = {0x1d8e78af, 0x3fcc71c5};

// data-ok: retail's bytes at 0X2AC228
extern const unsigned int D_002AC228[2] = {0x9997fa04, 0x3fd99999};

// data-ok: retail's bytes at 0X2AC230
extern const unsigned int D_002AC230[2] = {0xdf3e5244, 0x3fc2f112};

// data-ok: retail's bytes at 0X2AC238
extern const unsigned int D_002AC238[2] = {0x96cb03de, 0x3fc74664};

// data-ok: retail's bytes at 0X2AC240
extern const unsigned int D_002AC240[2] = {0x94229359, 0x3fd24924};

// data-ok: retail's bytes at 0X2AC248
extern const unsigned int D_002AC248[2] = {0x55555593, 0x3fe55555};

// data-ok: retail's bytes at 0X2AC250
extern const unsigned int D_002AC250[2] = {0xfee00000, 0x3fe62e42};

// data-ok: retail's bytes at 0X2AC258
extern const unsigned int D_002AC258[2] = {0x35793c76, 0x3dea39ef};

// data-ok: retail's bytes at 0X2AC260
extern const unsigned int D_002AC260[2] = {0xfee00000, 0x3fe62e42};

// data-ok: retail's bytes at 0X2AC268
extern const unsigned int D_002AC268[2] = {0x35793c76, 0x3dea39ef};

// data-ok: retail's bytes at 0X2AC270
extern const struct {
    char m0[12];
    char m1[4];
    unsigned int m2[4];
} D_002AC270 = {
    "rom0:ROMVER",
    "",
    {0x1e1f1c1f, 0x1f1f1e1f, 0x1f1e1f1e, 0}
};
