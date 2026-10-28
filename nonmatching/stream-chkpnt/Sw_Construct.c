#include "m2c_macros.h"

M2C_UNK CreateSlotheapSwAlign(void *, s32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK InitDl__FP2DLi(void *, M2C_UNK);            /* extern */
M2C_UNK InitSl(void *, M2C_UNK);                    /* extern */
s32 func_001CF5C8();                                /* extern */
M2C_UNK memset(void *, M2C_UNK, M2C_UNK, M2C_UNK);  /* extern */
extern M2C_UNK D_002DC018;
extern f32 D_FLT_002C3E60;
extern f32 D_FLT_002C3E64;
extern f32 D_FLT_002C3E68;
extern f32 D_FLT_002C3E6C;

void *Sw_Construct(void *arg0) {
    f32 temp_f0;
    s32 temp_v0;
    s32 var_s2_2;
    u32 var_s2;
    u32 var_s2_3;
    void *temp_s3;
    void *temp_s5;
    void *var_s0;
    void *var_s0_2;
    void *var_s0_3;

    var_s2 = 0;
    var_s0 = arg0 + 0x38;
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0xC) = &D_002DC018;
    CreateSlotheapSwAlign(arg0 + 0x398C, 0x14, 0x100, 0x10);
    CreateSlotheapSwAlign(arg0 + 0x39FC, 0x14, 0x100, 0x10);
    CreateSlotheapSwAlign(arg0 + 0x3C90, 0x14, 0x100, 0x10);
    CreateSlotheapSwAlign(arg0 + 0x3CB4, 0xC, 0x200, 0x10);
    CreateSlotheapSwAlign(arg0 + 0x3CE0, 0x80, 0x300, 0x10);
    CreateSlotheapSwAlign(arg0 + 0x3CF8, 0x14, 0x400, 0x10);
    CreateSlotheapSwAlign(arg0 + 0x3D40, 0xC0, 0x100, 0x10);
    CreateSlotheapSwAlign(arg0 + 0x3D94, 0x60, 0x100, 0x10);
    CreateSlotheapSwAlign(arg0 + 0x3DAC, 0x80, 0x400, 0x10);
    CreateSlotheapSwAlign(arg0 + 0x3DC4, 0x14, 8, 0x10);
    CreateSlotheapSwAlign(arg0 + 0x3DE8, 0x50, 0x80, 0x10);
    M2C_FIELD(arg0, s32 *, 0x3E00) = 0x80000000;
    CreateSlotheapSwAlign(arg0 + 0x3E44, 0x30, 0x40, 0x10);
    CreateSlotheapSwAlign(arg0 + 0x4008, 0x60, 0x40, 0x10);
    CreateSlotheapSwAlign(arg0 + 0x403C, 0x1B0, 0x10, 0x10);
    temp_v0 = func_001CF5C8();
    CreateSlotheapSwAlign(arg0 + 0x4054, (temp_v0 != 0) ? temp_v0 : 0xF0, 0x80, 0x10);
    CreateSlotheapSwAlign(arg0 + 0x4070, 0x460, 0x28, 0x10);
    CreateSlotheapSwAlign(arg0 + 0x4088, 0x10C0, 0x80, 0x40);
    CreateSlotheapSwAlign(arg0 + 0x40A0, 0x560, 8, 0x10);
    CreateSlotheapSwAlign(arg0 + 0x40B8, 0x1C, 0x200, 0x10);
    CreateSlotheapSwAlign(arg0 + 0x40D0, 0xF0, 0x20, 0x10);
    CreateSlotheapSwAlign(arg0 + 0x40E8, 0x10, 0x10, 0x10);
    CreateSlotheapSwAlign(arg0 + 0x4118, 0x60, 0x20, 0x10);
    CreateSlotheapSwAlign(arg0 + 0x413C, 0x30, 0x10, 0x10);
    CreateSlotheapSwAlign(arg0 + 0x4648, 0x40, 0x10, 0x10);
    CreateSlotheapSwAlign(arg0 + 0x4660, 0xD0, 0x10, 0x10);
    InitDl__FP2DLi(arg0 + 0x10, 0x24);
    InitDl__FP2DLi(arg0 + 0x20, 4);
    InitDl__FP2DLi(arg0 + 0x2C, 0xC);
    InitDl__FP2DLi(arg0 + 0x3D10, 0x48);
    InitDl__FP2DLi(arg0 + 0x3D1C, 0x40);
    InitDl__FP2DLi(arg0 + 0x3D28, 0x50);
    InitDl__FP2DLi(arg0 + 0x3D34, 0x58);
    InitDl__FP2DLi(arg0 + 0x3D88, 0x24);
    InitSl(arg0 + 0x39F0, 0x10);
    InitSl(arg0 + 0x3CA8, 0x10);
    InitDl__FP2DLi(arg0 + 0x3F24, 0xE0);
    InitDl__FP2DLi(arg0 + 0x3F30, 0x1B4);
    InitDl__FP2DLi(arg0 + 0x3F3C, 0x1B4);
    InitDl__FP2DLi(arg0 + 0x3F48, 0x104);
    InitDl__FP2DLi(arg0 + 0x3F54, 0x174);
    InitDl__FP2DLi(arg0 + 0x3F60, 0x1B4);
    InitDl__FP2DLi(arg0 + 0x3F6C, 0x104);
    InitDl__FP2DLi(arg0 + 0x3F78, 0x104);
    InitDl__FP2DLi(arg0 + 0x3F84, 0x104);
    InitDl__FP2DLi(arg0 + 0x3F90, 0xE0);
    InitDl__FP2DLi(arg0 + 0x3FA8, 0x154);
    InitDl__FP2DLi(arg0 + 0x3F9C, 0x100);
    InitDl__FP2DLi(arg0 + 0x3DDC, 0x1C);
    InitDl__FP2DLi(arg0 + 0x3FFC, 0x58);
    InitDl__FP2DLi(arg0 + 0x3FB4, 0xFE0);
    InitDl__FP2DLi(arg0 + 0x3FC0, 0x174);
    InitSl(arg0 + 0x3EAC, 0x84);
    InitSl(arg0 + 0x4100, 0x18);
    InitSl(arg0 + 0x410C, 0x40);
    InitDl__FP2DLi(arg0 + 0x4130, 0x50);
    InitDl__FP2DLi(arg0 + 0x3FCC, 0x20);
    InitDl__FP2DLi(arg0 + 0x3FD8, 0x104);
    InitDl__FP2DLi(arg0 + 0x45B0, 0x1D0);
    InitDl__FP2DLi(arg0 + 0x45BC, 0x1E0);
    InitDl__FP2DLi(arg0 + 0x3B00, 0x88);
    InitDl__FP2DLi(arg0 + 0x3FE4, 0xE0);
    InitDl__FP2DLi(arg0 + 0x3FF0, 0x130);
    InitDl__FP2DLi(arg0 + 0x3BD0, 0xB4);
    InitSl(arg0 + 0x3BDC, 0x4C);
    do {
        InitSl(var_s0, 0x1C);
        var_s2 += 1;
        var_s0 += 0xC;
    } while (var_s2 < 0x200U);
    temp_s3 = arg0 + 0x3E10;
    temp_s5 = arg0 + 0x45D0;
    var_s0_2 = arg0 + 0x3038;
    var_s2_2 = 0xC6;
    do {
        InitSl(var_s0_2, 0x20);
        var_s2_2 -= 1;
        var_s0_2 += 0xC;
    } while (var_s2_2 >= 0);
    var_s2_3 = 0;
    var_s0_3 = arg0 + 0x1838;
    do {
        InitSl(var_s0_3, 0xC);
        var_s2_3 += 1;
        var_s0_3 += 0xC;
    } while (var_s2_3 < 0x200U);
    M2C_FIELD(arg0, f32 *, 0x3E10) = 180.0f;
    temp_f0 = D_FLT_002C3E64 - D_FLT_002C3E60;
    M2C_FIELD(temp_s3, f32 *, 8) = 255.0f;
    M2C_FIELD(temp_s3, f32 *, 4) = 255.0f;
    M2C_FIELD(arg0, f32 *, 0x3E20) = 90.0f;
    M2C_FIELD(arg0, f32 *, 0x3E64) = 128.0f;
    M2C_FIELD(arg0, f32 *, 0x3E68) = 96.0f;
    M2C_FIELD(arg0, f32 *, 0x3E6C) = 160.0f;
    M2C_FIELD(arg0, s32 *, 0x3C88) = 0x189;
    M2C_FIELD(arg0, s32 *, 0x3C80) = -1;
    M2C_FIELD(arg0, s32 *, 0x3C8C) = -1;
    M2C_FIELD(arg0, s32 *, 0x3CCC) = 1;
    M2C_FIELD(arg0, f32 *, 0x45E0) = (f32) D_FLT_002C3E6C;
    M2C_FIELD(arg0, s32 *, 0x3F10) = -2;
    M2C_FIELD(arg0, s32 *, 0x3E24) = 0;
    M2C_FIELD((arg0 + 0x45E0), f32 *, 4) = (f32) D_FLT_002C3E68;
    M2C_FIELD(arg0, f32 *, 0x45D0) = (f32) (((D_FLT_002C3E64 * D_FLT_002C3E68) - (D_FLT_002C3E60 * D_FLT_002C3E6C)) / temp_f0);
    M2C_FIELD(temp_s5, f32 *, 4) = (f32) ((D_FLT_002C3E6C - D_FLT_002C3E68) / temp_f0);
    M2C_FIELD(temp_s5, s32 *, 8) = 0;
    M2C_FIELD(arg0, s32 *, 0x4740) = -1;
    M2C_FIELD(arg0, f32 *, 0x4754) = -60.0f;
    M2C_FIELD(arg0, s32 *, 0x4554) = 1;
    M2C_FIELD(arg0, f32 *, 0x4750) = -60.0f;
    memset(arg0 + 0x4590, -1, 0x20, 0x189);
    return arg0;
}
