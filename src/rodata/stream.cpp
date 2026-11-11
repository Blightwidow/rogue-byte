// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2A8910-0X2A8968 (piece rodata/stream), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2A8910
extern const struct {
    char m0[4];
    char m1[4];
} D_002A8910 = {
    "%s",
    ""
};

// data-ok: retail's bytes at 0X2A8918
extern const char D_002A8918[8] = "intro";

// data-ok: retail's bytes at 0X2A8920
extern const struct {
    char m0[12];
    char m1[4];
} D_002A8920 = {
    "nightclub",
    ""
};

// data-ok: retail's bytes at 0X2A8930
extern const char D_002A8930[8] = "palace";

// data-ok: retail's bytes at 0X2A8938
extern const char D_002A8938[8] = "temple";

// data-ok: retail's bytes at 0X2A8940
extern const char D_002A8940[8] = "prison";

// data-ok: retail's bytes at 0X2A8948
extern const char D_002A8948[8] = "castle";

// data-ok: retail's bytes at 0X2A8950
extern const char D_002A8950[8] = "train";

// data-ok: retail's bytes at 0X2A8958
extern const char D_002A8958[8] = "sawmill";

// data-ok: retail's bytes at 0X2A8960
extern const char D_002A8960[8] = "blimp";
