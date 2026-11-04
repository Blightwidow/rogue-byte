#include "m2c_macros.h"

M2C_UNK AddDmaCnt__4DMAS(s32, M2C_UNK *, s32, s32); /* extern */
M2C_UNK AddVifBaseOffset__4VIFSii(s32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK AddVifDirect__4VIFSiP2QWi(s32, s32, s32, M2C_UNK); /* extern */
M2C_UNK AddVifFlush__4VIFS(s32);                    /* extern */
M2C_UNK AddVifFlusha__4VIFS(s32);                   /* extern */
M2C_UNK AddVifUnpack__4VIFS3UPKiPvi(s32, M2C_UNK, M2C_UNK, s128 *); /* extern */
M2C_UNK BuildSimpleProjectionMatrix__FffffffP7MATRIX4(M2C_UNK *, f32, f32, M2C_UNK, M2C_UNK, f32, f32); /* extern */
M2C_UNK CombineEyeLookAtProj(s128 *, M2C_UNK *, s128 *); /* extern */
M2C_UNK EndDmaCnt__4DMAS(s32);                      /* extern */
void *PmatLoWorld(void *);                          /* extern */
M2C_UNK PosLoWorld(void *, s128);                   /* extern */
M2C_UNK __as__6VECTORG9VU_VECTOR(M2C_UNK *, M2C_UNK); /* extern */
f32 tanf(f32);                                      /* extern */
extern M2C_UNK D_002C1F00;
extern M2C_UNK D_002C1F10;

void func_001BE6F0(void *arg0, s32 arg1) {
    M2C_UNK sp30;
    M2C_UNK sp40;
    M2C_UNK unksp6C;
    s128 sp50;
    s128 sp60;
    s32 sp7C;
    s32 sp8C;
    M2C_UNK sp90;
    M2C_UNK spB0;
    s128 spF0;
    s128 sp130;
    s32 sp138;
    f32 sp13C;
    s32 sp148;
    f32 sp14C;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f20;
    f32 temp_f2;
    f32 temp_f2_2;
    s128 temp_v1;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;

    temp_v0 = M2C_FIELD(arg0, void **, 0x20);
    if (temp_v0 != NULL) {
        temp_s0 = M2C_FIELD(temp_v0, void **, 0x118);
        temp_s0_2 = (temp_s0 == NULL) ? temp_v0 : temp_s0;
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf2 */);
        temp_v1 = M2C_FIELD(PmatLoWorld(temp_s0_2), s128 *, 0x10);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf4, $vf1, $vf2x */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($v0) */);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf3, $vf2x */);
        sp50 = temp_v1;
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0xa0($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x30($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x40($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x20($sp) */);
        PosLoWorld(temp_s0_2, temp_v1);
        __as__6VECTORG9VU_VECTOR(&sp90, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */));
        sp60 = sp30;
        M2C_FIELD(&sp60, s128 *, 0x10) = sp40;
        temp_f20 = (f32) M2C_FIELD(arg0, s32 *, 0) / (f32) M2C_FIELD(arg0, s32 *, 4);
        M2C_FIELD(&sp60, s128 *, 0x20) = sp50;
        sp8C = 0;
        sp7C = 0;
        unksp6C = 0;
        M2C_FIELD(&sp60, f32 *, 0x3C) = 1.0f;
        temp_f0 = tanf(M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), f32 *, 0x11C) * 0.5f);
        temp_v0_2 = M2C_FIELD(arg0, void **, 0x20);
        BuildSimpleProjectionMatrix__FffffffP7MATRIX4(&spB0, (f32) M2C_FIELD(arg0, s32 *, 0) / (temp_f0 * temp_f20 * 4096.0f), (f32) M2C_FIELD(arg0, s32 *, 4) / (temp_f0 * 4096.0f), 0, 0, M2C_FIELD(temp_v0_2, f32 *, 0x120), M2C_FIELD(temp_v0_2, f32 *, 0x124));
        CombineEyeLookAtProj(&sp60, &spB0, &spF0);
        temp_v0_3 = M2C_FIELD(arg0, void **, 0x20);
        temp_f2 = M2C_FIELD(temp_v0_3, f32 *, 0x124);
        temp_f1 = M2C_FIELD(temp_v0_3, f32 *, 0x120);
        M2C_ERROR(/* unknown instruction: ldl $a2, 0x7($t1) */);
        M2C_ERROR(/* unknown instruction: ldr $a2, ($t1) */);
        M2C_ERROR(/* unknown instruction: sdl $a2, 0x137($sp) */);
        M2C_ERROR(/* unknown instruction: sdr $a2, 0x130($sp) */);
        sp138 = M2C_FIELD(&D_002C1F00, s32 *, 8);
        temp_f1_2 = (temp_f1 + temp_f2) / (temp_f1 - temp_f2);
        temp_f2_2 = 1.0f - temp_f1_2;
        sp13C = 1.0f / (M2C_FIELD(temp_v0_3, f32 *, 0x120) * temp_f2_2);
        M2C_ERROR(/* unknown instruction: ldl $v1, 0x7($t0) */);
        M2C_ERROR(/* unknown instruction: ldr $v1, ($t0) */);
        M2C_ERROR(/* unknown instruction: sdl $v1, 0x147($sp) */);
        M2C_ERROR(/* unknown instruction: sdr $v1, 0x140($sp) */);
        sp148 = M2C_FIELD(&D_002C1F10, s32 *, 8);
        sp14C = -temp_f1_2 / (M2C_FIELD(temp_v0_3, f32 *, 0x120) * temp_f2_2);
        AddDmaCnt__4DMAS(arg1, &D_002C1F10, M2C_FIELD(&D_002C1F10, s32 *, 8), M2C_FIELD(&D_002C1F00, s32 *, 8));
        AddVifFlush__4VIFS(arg1);
        AddVifDirect__4VIFSiP2QWi(arg1, M2C_FIELD(arg0, s32 *, 0x10), M2C_FIELD(arg0, s32 *, 0x14), 0);
        AddVifFlusha__4VIFS(arg1);
        AddVifBaseOffset__4VIFSii(arg1, 0, 0);
        AddVifUnpack__4VIFS3UPKiPvi(arg1, 0xC, 4, &spF0);
        AddVifUnpack__4VIFS3UPKiPvi(arg1, 0xC, 4, &sp60);
        AddVifUnpack__4VIFS3UPKiPvi(arg1, 0xC, 2, &sp130);
        AddVifBaseOffset__4VIFSii(arg1, 0x32, 0x1E7);
        EndDmaCnt__4DMAS(arg1);
    }
}
