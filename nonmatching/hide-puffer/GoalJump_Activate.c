#include "m2c_macros.h"

M2C_UNK BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(); /* extern */
M2C_UNK FFindSurfaceAlongUp(); /* extern */
s32 FIsBasicDerivedFrom();           /* extern */
M2C_UNK FindCrvClosestPointAll(); /* extern */
M2C_UNK GetJtPipeGoalMat__FP2JTP4PIPEfP7MATRIX3(); /* extern */
s32 GrfsgsFromSgs();                         /* extern */
M2C_UNK LoadRotateMatrixRad();     /* extern */
f32 *PmatLoWorld();                           /* extern */
s128 PosLoWorld();                    /* extern */
f32 RadNormalize__Ff();                          /* extern */
M2C_UNK SetJumperTarget();              /* extern */
f32 atan2f();                               /* extern */
M2C_UNK func_00174950();                      /* extern */
M2C_UNK func_0017A468();                /* extern */
M2C_UNK func_001EEFC0();                      /* extern */
M2C_UNK func_00209818();                 /* extern */
M2C_UNK func_00209840();              /* extern */
extern s128 g_2a2dc0;
extern M2C_UNK g_2be6b8;
extern s64 g_2dfb70;
extern s32 g_2dfb78;

void GoalJump_Activate(void *arg0) {
    M2C_UNK sp20;
    M2C_UNK sp30;
    M2C_UNK sp70;
    char sp[0x400];
    M2C_UNK sp0;
    M2C_UNK sp4;
    s128 sp10;
    f32 sp40;
    s128 sp50;
    s128 sp60;
    f32 *temp_s0_3;
    f32 var_f12;
    f32 var_f13;
    f32 var_f20;
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_s2_2;
    s32 temp_v0;
    s32 temp_v0_3;
    s32 temp_v1_2;
    s32 var_s1;
    s64 temp_v0_2;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a0_3;
    void *temp_a1;
    void *temp_a1_2;
    void *temp_s0_2;
    void *temp_s0_4;
    void *temp_v1;

    if (g_2dfb78 == 0) {
        temp_s0 = GrfsgsFromSgs(0x1B);
        temp_s2 = GrfsgsFromSgs(0x27);
        temp_s1 = GrfsgsFromSgs(0x28);
        temp_v0 = GrfsgsFromSgs(0x29);
        g_2dfb78 = 1;
        g_2dfb70 = temp_s0 | temp_s2 | temp_s1 | temp_v0;
    }
    temp_a1 = M2C_FIELD(arg0, void **, 0x10);
    temp_v0_2 = M2C_FIELD(temp_a1, s64 *, 0x2C0);
    temp_s2_2 = temp_v0_2 & g_2dfb70;
    M2C_FIELD(temp_a1, s64 *, 0x2C0) = (s64) (temp_v0_2 & ~g_2dfb70);
    temp_a0 = M2C_FIELD(arg0, void **, 0x60);
    var_s1 = 0;
    if (temp_a0 != NULL) {
        if (FIsBasicDerivedFrom(temp_a0, 0xA) != 0) {
            temp_s0_2 = M2C_FIELD(arg0, void **, 0x60);
            PosLoWorld(M2C_FIELD(arg0, void **, 0x10));
            FindCrvClosestPointAll(temp_s0_2, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */), 0, arg0 + 0x50);
            var_f12 = sp4;
            var_f13 = sp0;
        } else {
            M2C_FIELD(arg0, s128 *, 0x50) = PosLoWorld(M2C_FIELD(arg0, void **, 0x60));
            temp_s0_3 = PmatLoWorld(M2C_FIELD(arg0, void **, 0x60));
            var_f12 = M2C_FIELD(temp_s0_3, f32 *, 4);
            var_f13 = *PmatLoWorld(M2C_FIELD(arg0, void **, 0x60));
        }
        var_f20 = atan2f(var_f12, var_f13);
        if (FIsBasicDerivedFrom(M2C_FIELD(arg0, void **, 0x60), 0xD) == 0) {
            if (FIsBasicDerivedFrom(M2C_FIELD(arg0, void **, 0x60), 0x27) == 0) {
                if (FIsBasicDerivedFrom(M2C_FIELD(arg0, void **, 0x60), 0xB) == 0) {
                    if (FIsBasicDerivedFrom(M2C_FIELD(arg0, void **, 0x60), 0x13) != 0) {
                        if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x60), s32 *, 0x124) == 3) {
                            temp_v0_3 = GrfsgsFromSgs(0x28);
                            M2C_FIELD(arg0, s32 *, 0x6C) = 1;
                            var_s1 = 0 | temp_v0_3;
                            BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(sp, *PmatLoWorld(M2C_FIELD(arg0, void **, 0x60)), g_2a2dc0);
                            M2C_FIELD(arg0, s128 *, 0x70) = (s128) sp0;
                            M2C_FIELD(arg0, s128 *, 0x80) = sp10;
                            M2C_FIELD(arg0, s128 *, 0x90) = sp20;
                            func_0017A468(arg0, (s128) sp0);
                        } else {
                            goto block_24;
                        }
                    } else {
block_24:
                        FFindSurfaceAlongUp(arg0 + 0x50, 1, 0, M2C_FIELD(&g_2be6b8, f32 *, 4), M2C_FIELD(&g_2be6b8, f32 *, 0));
                        M2C_FIELD(arg0, void **, 0x60) = NULL;
                    }
                } else {
                    var_s1 = 0 | GrfsgsFromSgs(0x27);
                    M2C_FIELD(arg0, s32 *, 0x6C) = 1;
                    GetJtPipeGoalMat__FP2JTP4PIPEfP7MATRIX3(M2C_FIELD(arg0, void **, 0x60), M2C_FIELD(arg0, s32 *, 0x64), arg0 + 0x70, sp40);
                    func_0017A468(arg0);
                }
            } else {
                var_s1 = 0 | GrfsgsFromSgs(0x29);
            }
        } else {
            var_s1 = 0 | GrfsgsFromSgs(0x1B);
            if (M2C_FIELD(arg0, s32 *, 0x64) == 0) {
                var_f20 = RadNormalize__Ff(var_f20 + 3.1415927f);
            }
            M2C_FIELD(arg0, s32 *, 0x6C) = 1;
            LoadRotateMatrixRad(&sp10, g_2a2dc0, var_f20);
            M2C_FIELD(arg0, s128 *, 0x70) = sp10;
            M2C_FIELD(arg0, s128 *, 0x80) = sp20;
            M2C_FIELD(arg0, s128 *, 0x90) = sp30;
        }
    }
    temp_v1 = M2C_FIELD(arg0, void **, 0x10);
    M2C_FIELD(temp_v1, s64 *, 0x2C0) = (s64) (M2C_FIELD(temp_v1, s64 *, 0x2C0) | var_s1);
    func_00174950(arg0);
    temp_a1_2 = M2C_FIELD(arg0, void **, 0x10);
    M2C_FIELD(temp_a1_2, s64 *, 0x2C0) = (s64) (M2C_FIELD(temp_a1_2, s64 *, 0x2C0) & ~var_s1);
    temp_a0_2 = M2C_FIELD(arg0, void **, 0x10);
    M2C_FIELD(temp_a0_2, s64 *, 0x2C0) = (s64) (M2C_FIELD(temp_a0_2, s64 *, 0x2C0) | temp_s2_2);
    if (M2C_FIELD(arg0, void **, 0x40) != NULL) {
        temp_a0_3 = M2C_FIELD(arg0, void **, 0x10);
        temp_v1_2 = M2C_FIELD(temp_a0_3, s32 *, 0xF80);
        switch (temp_v1_2) {                        /* irregular */
        case 3:
            /* fallthrough */
        default:
            sp50 = M2C_FIELD(arg0, s128 *, 0x50);
            PosLoWorld(M2C_FIELD(arg0, void **, 0x10), temp_a1_2);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x50($sp) */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
            temp_s0_4 = M2C_FIELD(arg0, void **, 0x10) + 0xFD0;
            func_00209818(temp_s0_4, atan2f(M2C_ERROR(/* unknown instruction: prot3w $v1, $v0 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */)));
            break;
        case 2:
            sp60 = M2C_FIELD(arg0, s128 *, 0x50);
            PosLoWorld(temp_a0_3, temp_a1_2);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x60($sp) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf1, $vf2 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x70($sp) */);
            BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(sp, *PmatLoWorld(M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), void **, 0xF84)), sp70);
            func_00209840(M2C_FIELD(arg0, void **, 0x10) + 0xFD0, sp);
            break;
        }
        M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x40), void **, 8), s32 *, 0x60) = (s32) M2C_FIELD(arg0, s32 *, 0x68);
        M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x40), void **, 8), void **, 0x58) = (void *) M2C_FIELD(arg0, void **, 0x60);
        M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x40), void **, 8), s32 *, 0x5C) = (s32) M2C_FIELD(arg0, s32 *, 0x64);
        SetJumperTarget(M2C_FIELD(M2C_FIELD(arg0, void **, 0x40), void **, 8), M2C_FIELD(arg0, s128 *, 0x50));
    }
    func_001EEFC0(arg0);
}
