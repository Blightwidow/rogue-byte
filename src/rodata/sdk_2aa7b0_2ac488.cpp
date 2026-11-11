// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2AC488-0X2AC500 (piece rodata/sdk_2aa7b0), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2AC488
extern const struct {
    char m0[20];
    char m1[4];
} D_002AC488 = {
    "CSC handler error\012",
    ""
};

// data-ok: retail's bytes at 0X2AC4A0
extern const unsigned int D_002AC4A0[4] = {0x18081000, 0x20101808, 0x30202818, 0x38283020};

// data-ok: retail's bytes at 0X2AC4B0
extern const char D_002AC4B0[48] = "pack_header_field_flag needs to be '0' in PS\012";

// data-ok: retail's bytes at 0X2AC4E0
extern const struct {
    char m0[28];
    char m1[4];
} D_002AC4E0 = {
    "Error code detected(BDEC)",
    ""
};
