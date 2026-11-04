#include "m2c_macros.h"

M2C_UNK AppendDlEntry(M2C_UNK *, void *);           /* extern */
M2C_UNK CStackFrame_Construct(void *, void **, s32); /* extern */
M2C_UNK CStackFrame_Destructor(void *, M2C_UNK);    /* extern */
M2C_UNK MeasureCrv(void *);                         /* extern */
M2C_UNK Obstacle_JoinGroup(void *, void *);         /* extern */
M2C_UNK Obstacle_SetConvexHull(void *, s32, s32);   /* extern */
void *PobstacleGroupAlloc();                        /* extern */
s32 PvAllocStackImpl__Fi(s32 *);                    /* extern */
M2C_UNK RemoveDlEntry(void **, void *);             /* extern */
s32 func_001BC2F8(void *);                          /* extern */
extern M2C_UNK B_003E1A40;
extern s32 *g_2dd2fc;

void MergeObstacles(s32 arg0, void **arg1, s32 arg2) {
    char sp[0x400];
    s32 sp10;                                       /* compiler-managed */
    void **sp14;
    s32 sp18;
    s32 *sp1C;
    s128 sp20;
    s128 sp30;
    s128 sp40;
    s128 sp50;
    void **sp60;
    s32 *sp64;
    s32 temp_s4;
    s32 temp_v0_4;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a1_2;
    s32 var_a2;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s3;
    s32 var_s4;
    s32 var_v1;
    void **temp_v0_5;
    void **var_a1;
    void *temp_s1;
    void *temp_s1_2;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_6;
    void *temp_v1;
    void *temp_v1_2;
    void *var_v0;

    var_a1 = arg1;
    var_a2 = arg2;
    var_s3 = 0;
    sp60 = var_a1;
    sp64 = &sp10;
    if (arg0 > 0) {
        var_a2 = arg0;
        do {
            temp_v0 = *var_a1;
            var_a1 += 4;
            var_a2 -= 1;
            var_s3 = var_s3 - 1 + M2C_FIELD(temp_v0, s32 *, 0xE8);
        } while (var_a2 != 0);
    }
    var_s0 = 0;
    CStackFrame_Construct(sp, var_a1, var_a2);
    sp10 = var_s3 * 0x10;
    M2C_FIELD(sp64, s32 *, 4) = 0x10;
    temp_s4 = PvAllocStackImpl__Fi(sp64);
    if (arg0 > 0) {
        do {
            temp_s1 = sp60[var_s0];
            temp_v1 = M2C_FIELD(temp_s1, void **, 0xC);
            temp_v0_2 = M2C_FIELD(temp_v1, void *(**)(void *), 0xFC)(temp_s1 + M2C_FIELD(temp_v1, s16 *, 0xF8));
            sp20 = M2C_FIELD(temp_v0_2, s128 *, 0);
            sp30 = M2C_FIELD(temp_v0_2, s128 *, 0x10);
            sp40 = M2C_FIELD(temp_v0_2, s128 *, 0x20);
            sp50 = M2C_FIELD(temp_v0_2, s128 *, 0x30);
            var_a1_2 = 0;
            if ((M2C_FIELD(temp_s1, s32 *, 0xE8) - 1) > 0) {
loop_7:
                M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x30($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf4, ($v0) */);
                var_a1_2 += 1;
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x40($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x50($sp) */);
                M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf4x */);
                M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf5, $vf4y */);
                M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf2, $vf4z */);
                M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf3, $vf1, $vf0w */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($a0) */);
                if (var_a1_2 < (M2C_FIELD(temp_s1, s32 *, 0xE8) - 1)) {
                    goto loop_7;
                }
            }
            var_s0 += 1;
        } while (var_s0 < arg0);
    }
    temp_v0_3 = PobstacleGroupAlloc();
    Obstacle_SetConvexHull(temp_v0_3, var_s3, temp_s4);
    var_a0 = M2C_FIELD(temp_v0_3, s32 *, 0xE8) - 2;
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($v0) */);
    if (var_a0 >= 0) {
        do {
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
            var_a0 -= 1;
            M2C_ERROR(/* unknown instruction: vadd.xyzw $vf2, $vf2, $vf1 */);
        } while (var_a0 >= 0);
    }
    temp_v1_2 = M2C_FIELD(temp_v0_3, void **, 0xC);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
    M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf2, $vf2, $q */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x70($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
    M2C_FIELD(temp_v1_2, M2C_UNK (**)(void *, M2C_UNK), 0xEC)(temp_v0_3 + M2C_FIELD(temp_v1_2, s16 *, 0xE8), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf2 */));
    var_a0_2 = M2C_FIELD(temp_v0_3, s32 *, 0xE8) - 1;
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x70($sp) */);
    if (var_a0_2 >= 0) {
        do {
            temp_v0_4 = var_a0_2 * 0x10;
            var_a0_2 -= 1;
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($v0) */);
        } while (var_a0_2 >= 0);
    }
    var_s0_2 = 0;
    if (arg0 > 0) {
        do {
            temp_s1_2 = sp60[var_s0_2];
            if (M2C_FIELD(temp_s1_2, s32 *, 0x1C0) != 0) {
                temp_v0_5 = temp_s1_2 + 0x1C4;
                sp14 = temp_v0_5;
                sp10 = temp_v0_5;
                var_s4 = var_s0_2 + 1;
                var_v1 = M2C_FIELD(temp_v0_5, s32 *, 8);
                sp18 = var_v1;
                sp1C = g_2dd2fc;
                g_2dd2fc = sp64;
                var_v0 = M2C_FIELD(temp_s1_2, void **, 0x1C4);
loop_21:
                sp14 = var_v0 + var_v1;
                if (var_v0 != NULL) {
                    RemoveDlEntry(temp_v0_5, var_v0);
                    M2C_FIELD(var_v0, s32 *, 0x1D8) = 0;
                    Obstacle_JoinGroup(var_v0, temp_v0_3);
                    var_v1 = sp18;
                    var_v0 = *sp14;
                    goto loop_21;
                }
                temp_v0_6 = M2C_FIELD(temp_s1_2, void **, 0xC);
                M2C_FIELD(temp_v0_6, M2C_UNK (**)(void *), 0x4C)(temp_s1_2 + M2C_FIELD(temp_v0_6, s16 *, 0x48));
                AppendDlEntry(&B_003E1A40, temp_s1_2);
                g_2dd2fc = sp1C;
            } else {
                Obstacle_JoinGroup(temp_s1_2, temp_v0_3);
                var_s4 = var_s0_2 + 1;
            }
            var_s0_2 = var_s4;
        } while (var_s0_2 < arg0);
    }
    M2C_FIELD(temp_v0_3, s32 *, 0xE4) = 1;
    MeasureCrv(temp_v0_3);
    M2C_FIELD(temp_v0_3, s32 *, 0x190) = func_001BC2F8(temp_v0_3);
    CStackFrame_Destructor(sp, 2);
}
