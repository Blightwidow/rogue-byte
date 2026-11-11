// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2A4F00-0X2A4FF0 (piece rodata/cd_2a4f00), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2A4F00
extern const struct {
    char m0[4];
    char m1[4];
    char m2[20];
    char m3[4];
    char m4[16];
    char m5[28];
    char m6[4];
    char m7[16];
    char m8[28];
    char m9[4];
    char m10[12];
    char m11[4];
    char m12[12];
    char m13[4];
    char m14[8];
    char m15[8];
    char m16[8];
    char m17[8];
    char m18[16];
} D_002A4F00 = {
    ";1",
    "",
    "PlayStation2 DVD",
    "",
    "PlayStation2 CD",
    "PlayStation2 CD with CDDA",
    "",
    "PlayStation CD",
    "PlayStation CD with CDDA",
    "",
    "IllgalMedia",
    "",
    "DVD video",
    "",
    "CD-DA",
    "Working",
    "No Disc",
    "Unknown",
    "    %#x = %s\012"
};

// data-ok: retail's bytes at 0X2A4FD0
extern const short g_2a4fd0[4] = {92, 0, 0, 0};

// data-ok: retail's bytes at 0X2A4FD8
extern const char D_002A4FD8[8] = "%s\134%s";

// data-ok: retail's bytes at 0X2A4FE0
extern const char D_002A4FE0[8] = "cdrom0:";

// data-ok: retail's bytes at 0X2A4FE8
extern const unsigned int D_002A4FE8[2] = {0, 0};
