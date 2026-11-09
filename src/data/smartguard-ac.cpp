// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BFD38-0X2C0248 (piece data/smartguard-ac), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void CycleOptionItem();
extern "C" void OpenOptionsMenu();
extern "C" void PauseMenu_BeginAdjust_thunk();
extern "C" void PauseMenu_Close_thunk();
extern "C" void PauseMenu_PopPage_thunk();
extern "C" void RefreshOptionItem();
extern "C" void SlotItem_Load();
extern "C" void func_001AD250();
extern "C" void func_001AD480();
extern "C" void func_001AD538();
extern "C" void func_001AD740();
extern "C" void func_001B0688();
extern "C" void func_001B06D8();
extern "C" void func_001B0740();
extern "C" void func_001B0808();
extern "C" void func_001B0848();
extern "C" void func_001B0878();
extern "C" void func_001B0970();
extern "C" void func_001B09A8();

// data-ok: retail's bytes at 0X2BFD38
unsigned int D_002BFD38[8] = {0x316, 0x318, 0x317, 0x319, 0x31b, 0x31a, 0x31c, 0x31d};

// data-ok: retail's bytes at 0X2BFD58
struct {
    char m0[4];
    char m1[4];
    char m2[4];
    char m3[4];
} D_002BFD58 = {
    "N",
    "M",
    "L",
    ""
};

// data-ok: retail's bytes at 0X2BFD68
struct {
    char m0[4];
    char m1[4];
} D_002BFD68 = {
    "H",
    "I"
};

// data-ok: retail's bytes at 0X2BFD70
struct {
    char m0[4];
    char m1[4];
} D_002BFD70 = {
    "O",
    "P"
};

// data-ok: retail's bytes at 0X2BFD78
struct {
    char m0[4];
    char m1[4];
} D_002BFD78 = {
    "Q",
    "R"
};

// data-ok: retail's bytes at 0X2BFD80
struct {
    char m0[4];
    char m1[4];
} D_002BFD80 = {
    "S",
    "T"
};

// data-ok: retail's bytes at 0X2BFD88
unsigned int D_002BFD88[8] = {0x5c2, 0x5c3, 0x5c4, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};

// data-ok: retail's bytes at 0X2BFDA8
struct {
    char m0[4];
    void *m1[23];
} D_002BFDA8 = {
    "E",
    {(void *)func_001AD250, 0, 0, (void *)func_001AD740, (void *)func_001AD538, 0, 0, (void *)69, (void *)func_001AD250, (void *)1, 0, (void *)func_001AD740, 0, 0, 0, (void *)69, (void *)func_001AD250, (void *)2, 0, (void *)func_001AD740, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2BFE08
struct {
    char m0[4];
    void *m1[23];
} D_002BFE08 = {
    "E",
    {(void *)SlotItem_Load, 0, 0, (void *)func_001AD740, (void *)func_001AD538, 0, 0, (void *)69, (void *)SlotItem_Load, (void *)1, 0, (void *)func_001AD740, 0, 0, 0, (void *)69, (void *)SlotItem_Load, (void *)2, 0, (void *)func_001AD740, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2BFE68
struct {
    char m0[4];
    void *m1[23];
} D_002BFE68 = {
    "E",
    {(void *)func_001AD480, 0, 0, (void *)func_001AD740, (void *)func_001AD538, 0, 0, (void *)69, (void *)func_001AD480, (void *)1, 0, (void *)func_001AD740, 0, 0, 0, (void *)69, (void *)func_001AD480, (void *)2, 0, (void *)func_001AD740, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2BFEC8
struct {
    char m0[4];
    void *m1[87];
} D_002BFEC8 = {
    "<",
    {(void *)func_001B0688, (void *)3, (void *)&D_002BFDA8, 0, 0, (void *)&D_002BFD88, 0, (void *)61, (void *)func_001B0688, (void *)3, (void *)&D_002BFE08, 0, 0, (void *)&D_002BFD88, 0, (void *)62, (void *)func_001B0688, (void *)3, (void *)&D_002BFE68, 0, 0, (void *)&D_002BFD88, 0, (void *)76, (void *)CycleOptionItem, (void *)3, (void *)&D_002BFD58, 0, (void *)RefreshOptionItem, 0, 0, (void *)103, (void *)PauseMenu_BeginAdjust_thunk, 0, 0, 0, 0, 0, 0, (void *)104, (void *)PauseMenu_BeginAdjust_thunk, 0, 0, 0, 0, 0, 0, (void *)80, (void *)CycleOptionItem, (void *)2, (void *)&D_002BFD70, 0, (void *)RefreshOptionItem, 0, 0, (void *)81, (void *)CycleOptionItem, (void *)2, (void *)&D_002BFD78, 0, (void *)RefreshOptionItem, 0, 0, (void *)83, (void *)CycleOptionItem, (void *)2, (void *)&D_002BFD80, 0, (void *)RefreshOptionItem, 0, 0, (void *)63, (void *)PauseMenu_BeginAdjust_thunk, 0, 0, 0, 0, 0, 0, (void *)72, (void *)CycleOptionItem, (void *)2, (void *)&D_002BFD68, 0, (void *)RefreshOptionItem, 0, 0}
};

// data-ok: retail's bytes at 0X2C0028
void *D_002C0028[16] = {(void *)11, (void *)PauseMenu_PopPage_thunk, 0, 0, 0, 0, 0, 0, (void *)10, (void *)func_001B0878, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2C0068
struct {
    char m0[4];
    void *m1[15];
} D_002C0068 = {
    "\015",
    {(void *)PauseMenu_PopPage_thunk, 0, 0, 0, 0, 0, 0, (void *)12, (void *)func_001B09A8, 0, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2C00A8
void *D_002C00A8[16] = {(void *)15, (void *)PauseMenu_PopPage_thunk, 0, 0, 0, 0, 0, 0, (void *)14, (void *)func_001B0970, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2C00E8
struct {
    char m0[4];
    void *m1[55];
} D_002C00E8 = {
    "9",
    {(void *)PauseMenu_Close_thunk, 0, 0, 0, 0, 0, 0, (void *)70, (void *)func_001B06D8, (void *)2, (void *)&D_002C0028, (void *)func_001B0848, 0, 0, 0, (void *)66, (void *)func_001B06D8, (void *)2, (void *)&D_002C0068, 0, 0, 0, 0, (void *)107, (void *)func_001B06D8, (void *)2, (void *)&D_002C00A8, 0, 0, 0, 0, (void *)44, (void *)OpenOptionsMenu, 0, 0, 0, 0, 0, 0, (void *)67, (void *)func_001B0740, 0, 0, 0, 0, 0, 0, (void *)106, (void *)func_001B0808, 0, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2C01C8
float D_002C01C8 = 5.0f;

// data-ok: retail's bytes at 0X2C01CC
float D_002C01CC = 2.0f;

// data-ok: retail's bytes at 0X2C01D0
unsigned int D_002C01D0[8] = {0x328, 0x329, 0x32a, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};

// data-ok: retail's bytes at 0X2C01F0
unsigned int D_002C01F0[8] = {0x32b, 0x32c, 0x32d, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};

// data-ok: retail's bytes at 0X2C0210
unsigned int D_002C0210[8] = {0x32e, 0x32f, 0x330, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};

// data-ok: retail's bytes at 0X2C0230
unsigned int D_002C0230[6] = {8, 8, 0xffffffff, 0, 8, 0xffffffff};
