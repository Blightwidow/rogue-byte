// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2A7838-0X2A7847 (piece rodata/rip-rumble), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2A7838
extern const float D_002A7838 = -3.4028235e+38f;

// data-ok: retail's bytes at 0X2A783C
extern const float D_002A783C = 3.4028235e+38f;

// data-ok: retail's bytes at 0X2A7840
extern const struct {
    unsigned int m0;
    unsigned char m1[3];
} D_002A7840 = {
    0xffff0000,
    {240, 63, 29}
};
