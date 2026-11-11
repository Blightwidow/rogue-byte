// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2A8968-0X2A8A98 (piece rodata/new_20e040_2a8968), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2A8968
extern const unsigned int D_002A8968[2] = {0x7464, 0};

// data-ok: retail's bytes at 0X2A8970
extern const struct {
    char m0[12];
    char m1[4];
} D_002A8970 = {
    "widCurrent",
    ""
};

// data-ok: retail's bytes at 0X2A8980
extern const char D_002A8980[16] = "episodeCurrent";

// data-ok: retail's bytes at 0X2A8990
extern const char D_002A8990[8] = "loot";

// data-ok: retail's bytes at 0X2A8998
extern const char D_002A8998[8] = "ccoin";

// data-ok: retail's bytes at 0X2A89A0
extern const char D_002A89A0[8] = "flags";

// data-ok: retail's bytes at 0X2A89A8
extern const char D_002A89A8[8] = "lang";

// data-ok: retail's bytes at 0X2A89B0
extern const struct {
    char m0[12];
    char m1[4];
} D_002A89B0 = {
    "nMixerMode",
    ""
};

// data-ok: retail's bytes at 0X2A89C0
extern const char D_002A89C0[16] = "uMusicVolume";

// data-ok: retail's bytes at 0X2A89D0
extern const char D_002A89D0[16] = "uEffectsVolume";

// data-ok: retail's bytes at 0X2A89E0
extern const struct {
    char m0[12];
    char m1[4];
} D_002A89E0 = {
    "fUseHeadset",
    ""
};

// data-ok: retail's bytes at 0X2A89F0
extern const char D_002A89F0[16] = "dxScreenCenter";

// data-ok: retail's bytes at 0X2A8A00
extern const char D_002A8A00[16] = "dyScreenCenter";

// data-ok: retail's bytes at 0X2A8A10
extern const char D_002A8A10[16] = "fNoVibration";

// data-ok: retail's bytes at 0X2A8A20
extern const struct {
    char m0[20];
    char m1[4];
} D_002A8A20 = {
    "fReverseLookAround",
    ""
};

// data-ok: retail's bytes at 0X2A8A38
extern const struct {
    char m0[12];
    char m1[4];
} D_002A8A38 = {
    "fReverseAim",
    ""
};

// data-ok: retail's bytes at 0X2A8A48
extern const char D_002A8A48[16] = "fAutosaveWarned";

// data-ok: retail's bytes at 0X2A8A58
extern const char D_002A8A58[8] = "episode";

// data-ok: retail's bytes at 0X2A8A60
extern const struct {
    char m0[20];
    char m1[4];
} D_002A8A60 = {
    "percent_complete",
    ""
};

// data-ok: retail's bytes at 0X2A8A78
extern const unsigned int D_002A8A78[4] = {0x73697065, 0x4265646f, 0x747365, 0};

// data-ok: retail's bytes at 0X2A8A88
extern const char D_002A8A88[16] = "oidPoCurrent";
