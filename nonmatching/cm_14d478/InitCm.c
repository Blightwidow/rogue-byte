#include "m2c_macros.h"

M2C_UNK CPLCY_Destruct(void *);                     /* extern */
M2C_UNK CPLCY_Destruct_thunk(s32);                  /* extern */
M2C_UNK RecalcCmFrustrum__FP2CM(void *);            /* extern */
M2C_UNK SetCmLookAt(void *, s128, s128, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK SetCmPolicy__FP2CM3CPPP5CPLCYP2SOPv(void *, M2C_UNK, s32, M2C_UNK); /* extern */
M2C_UNK SetResetFlag__FP2CM(void *);                /* extern */
M2C_UNK bevy_camera_follow_new(void *);             /* extern */
M2C_UNK memset(void *, M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
extern M2C_UNK B_002DDF30;
extern s32 B_002DDF34;
extern s128 D_002BD830;
extern s128 D_002BD840;
extern f32 D_FLT_002BD81C;
extern f32 D_FLT_002BD820;
extern f32 D_FLT_002BD824;

void InitCm(void *arg0) {
    s32 temp_s1;
    void *temp_s0;
    void *temp_v0;

    if (B_002DDF34 == 0) {
        B_002DDF34 = 1;
        M2C_FIELD(&B_002DDF30, s32 *, 0) = 0x80303030;
    }
    temp_s0 = arg0 + 0x60;
    temp_v0 = arg0 + 0x2C;
    temp_s1 = arg0 + 0x3A0;
    M2C_FIELD(arg0, f32 *, 0x4C) = 100.0f;
    M2C_FIELD(arg0, f32 *, 0x240) = (f32) D_FLT_002BD81C;
    M2C_FIELD(arg0, f32 *, 0x244) = (f32) D_FLT_002BD820;
    M2C_FIELD(arg0, f32 *, 0x248) = (f32) D_FLT_002BD824;
    M2C_FIELD(arg0, f32 *, 0x3C) = 1.2987015f;
    M2C_FIELD(arg0, f32 *, 0x50) = 100000.0f;
    M2C_FIELD(arg0, f32 *, 0x1C) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0x18) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0x24) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0x20) = 1.0f;
    M2C_FIELD(arg0, M2C_UNK *, 0x24C) = M2C_UNALIGNED32(M2C_FIELD(&B_002DDF30, s32 *, 0));
    M2C_FIELD(arg0, f32 *, 0x2C) = 0.5f;
    M2C_FIELD(temp_v0, f32 *, 0xC) = 10.0f;
    M2C_FIELD(temp_v0, f32 *, 8) = 0.1f;
    M2C_FIELD(temp_v0, s32 *, 4) = 0;
    memset(temp_s0, 0, 0x40, &B_002DDF30);
    M2C_FIELD(temp_s0, f32 *, 0x14) = 1.0f;
    M2C_FIELD(temp_s0, f32 *, 0x3C) = 1.0f;
    M2C_FIELD(temp_s0, f32 *, 0x28) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0x60) = 1.0f;
    RecalcCmFrustrum__FP2CM(arg0);
    SetCmLookAt(arg0, D_002BD830, D_002BD840, 0, 0);
    SetResetFlag__FP2CM(arg0);
    M2C_FIELD(arg0, s32 *, 0x30C) = 0;
    CPLCY_Destruct_thunk(temp_s1);
    bevy_camera_follow_new(arg0 + 0x3B0);
    CPLCY_Destruct(arg0 + 0x450);
    CPLCY_Destruct(arg0 + 0x4A8);
    CPLCY_Destruct(arg0 + 0x4C0);
    CPLCY_Destruct(arg0 + 0x500);
    CPLCY_Destruct(arg0 + 0x520);
    CPLCY_Destruct(arg0 + 0x5F0);
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0xFF;
    SetCmPolicy__FP2CM3CPPP5CPLCYP2SOPv(arg0, 0, temp_s1, 0);
    M2C_FIELD(arg0, s32 *, 0x61C) = -1;
    M2C_FIELD(arg0, f32 *, 0x618) = -10.0f;
}
