#include "m2c_macros.h"

M2C_UNK FindCrvClosestPointFromU(void *, s128, M2C_UNK, void *, f32); /* extern */
M2C_UNK GetPathPosFromS(void *, void *, M2C_UNK, f32); /* extern */
M2C_UNK PmatLoWorld(void *);                        /* extern */
s128 PosLoWorld(void *);                            /* extern */
f32 SMaxCrv(void *);                                /* extern */
f32 SMinCrv(void *);                                /* extern */

void func_00193DE8(void *arg0) {
    char sp[0x400];
    s128 sp0;
    s128 sp10;
    M2C_UNK var_s2;
    f32 temp_f20;
    f32 temp_v0;
    s32 temp_v1;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a1;
    void *temp_s1;
    void *temp_t0;
    void *temp_v0_2;
    void *temp_v1_2;

    temp_v1 = M2C_FIELD(arg0, s32 *, 8);
    switch (temp_v1) {                              /* irregular */
    case 4:
        temp_a0 = M2C_FIELD(arg0, void **, 0);
        sp0 = PosLoWorld(M2C_FIELD(arg0, void **, 0x14));
        temp_t0 = M2C_FIELD(temp_a0, void **, 0xC);
        M2C_FIELD(temp_t0, M2C_UNK (**)(void *, M2C_UNK, void *, M2C_UNK), 0x294)(temp_a0 + M2C_FIELD(temp_t0, s16 *, 0x290), 0x23, M2C_FIELD(arg0, void **, 0x14), M2C_ERROR(/* unknown instruction: por $a3, $zero, $v0 */));
        return;
    case 3:
        temp_s1 = M2C_FIELD(arg0, void **, 0x14);
        var_s2 = 0x22;
        FindCrvClosestPointFromU(temp_s1, *M2C_FIELD(M2C_FIELD(arg0, void **, 0), s128 **, 0x218), 0, sp, M2C_FIELD(arg0, f32 *, 0x1C));
        if ((M2C_FIELD(temp_s1, s32 *, 0x1BC) == 0) && (M2C_FIELD(temp_s1, s32 *, 0xE4) == 0)) {
            temp_a1 = M2C_FIELD(arg0, void **, 0);
            temp_v1_2 = M2C_FIELD(temp_a1, void **, 0xC);
            M2C_FIELD(temp_v1_2, M2C_UNK (**)(void *, void *), 0x10C)(temp_a1 + M2C_FIELD(temp_v1_2, s16 *, 0x108), temp_a1);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf2, $vf1 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf3, $vf1z */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x20($sp) */);
            temp_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
            PmatLoWorld(M2C_FIELD(arg0, void **, 0));
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($v0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x20($v0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, ($v0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x190($v1) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf2x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf2y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf2, $vf5, $vf2z */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf2, $vf1 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
            temp_f20 = -M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */);
            if ((temp_v0 < -2.0f) || (temp_f20 < 2.0f)) {
                if (M2C_FIELD(arg0, f32 *, 0x20) < (SMinCrv(temp_s1) + 50.0f)) {
                    var_s2 = 0x2A;
                    GetPathPosFromS(temp_s1, sp, 0, SMinCrv(temp_s1) + 50.0f);
                } else {
                    goto block_10;
                }
            } else {
block_10:
                if (((temp_v0 > 2.0f) || (temp_f20 > -2.0f)) && ((SMaxCrv(temp_s1) - 50.0f) < M2C_FIELD(arg0, f32 *, 0x20))) {
                    var_s2 = 0x2A;
                    GetPathPosFromS(temp_s1, sp, 0, SMaxCrv(temp_s1) - 50.0f);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($sp) */);
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf1, $vf2x */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x30($sp) */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
                }
            }
        }
        temp_a0_2 = M2C_FIELD(arg0, void **, 0);
        temp_v0_2 = M2C_FIELD(temp_a0_2, void **, 0xC);
        M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, M2C_UNK, void *, s128), 0x294)(temp_a0_2 + M2C_FIELD(temp_v0_2, s16 *, 0x290), var_s2, temp_s1, sp0);
        return;
    }
}
