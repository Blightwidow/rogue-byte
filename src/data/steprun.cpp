// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2C3DC0-0X2C3DE0 (piece data/steprun), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2C3DC0
unsigned int D_002C3DC0[2] = {0x17d, 0x17e};

// data-ok: retail's bytes at 0X2C3DC8
unsigned int D_002C3DC8[2] = {0x17f, 0x180};

// data-ok: retail's bytes at 0X2C3DD0
unsigned int D_002C3DD0[2] = {2, 2};

// data-ok: retail's bytes at 0X2C3DD8
struct {
    char m0[4];
    char m1[4];
} D_002C3DD8 = {
    " ",
    "0"
};
