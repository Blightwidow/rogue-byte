#include "m2c_macros.h"

M2C_UNK AddSafePointOnGeom(void *, s32, s128, void *); /* extern */
M2C_UNK AddSafePointOnMember(s32, s32, f32);        /* extern */
s32 FIsBasicDerivedFrom(void *, M2C_UNK);           /* extern */
s128 PosLoWorld(void *);                            /* extern */
f32 atan2f(f32, f32);                               /* extern */

void func_001942F0(void *arg0) {
    M2C_UNK sp0;
    M2C_UNK sp4;
    s128 sp10;
    f32 var_f12;
    f32 var_f20;
    s32 temp_v1;
    void *temp_a1;
    void *temp_v1_2;

    temp_v1 = M2C_FIELD(arg0, s32 *, 8);
    switch (temp_v1) {                              /* irregular */
    case 0:
block_17:
        if (FIsBasicDerivedFrom(M2C_FIELD(arg0, void **, 0x14), 0xC) == 0) {
            if (FIsBasicDerivedFrom(M2C_FIELD(arg0, void **, 0x14), 0x26) == 0) {
                if (FIsBasicDerivedFrom(M2C_FIELD(arg0, void **, 0x14), 0x22) == 0) {
                    var_f20 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x14), f32 *, 0x184);
                    goto block_33;
                }
                temp_v1_2 = M2C_FIELD(arg0, void **, 0x14);
                if (M2C_FIELD(temp_v1_2, s32 *, 0xEC) == 0) {
                    var_f20 = M2C_FIELD(temp_v1_2, f32 *, 0x10C);
block_33:
                    sp10 = PosLoWorld(M2C_FIELD(arg0, void **, 0));
                    PosLoWorld(M2C_FIELD(arg0, void **, 0x14));
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($sp) */);
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
                    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf3 */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
                    var_f12 = atan2f(sp4, sp0) * var_f20;
                    goto block_34;
                }
            } else if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x14), s32 *, 0xEC) == 0) {
                var_f12 = 0.0f;
                goto block_34;
            }
        } else if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x14), s32 *, 0x19C) == 0) {
            var_f12 = M2C_FIELD(arg0, f32 *, 0x20);
block_34:
            AddSafePointOnMember(M2C_FIELD(arg0, void **, 0) + 0x9E0, M2C_FIELD(arg0, s32 *, 0x18), var_f12);
        }
        break;
    case 13:
        goto block_17;
    case 3:
        if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x14), s32 *, 0x19C) == 0) {
            var_f12 = M2C_FIELD(arg0, f32 *, 0x20);
            goto block_34;
        }
        break;
    case 4:
        if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x14), s32 *, 0xEC) == 0) {
            var_f12 = 0.0f;
            goto block_34;
        }
        break;
    default:
        temp_a1 = M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0x208);
        if ((temp_a1 != NULL) && (M2C_FIELD(temp_a1, f32 *, 0x88) > 0.7f)) {
            if (!(M2C_FIELD(M2C_FIELD(temp_a1, void **, 0x4C), s64 *, 0x148) & 0x20000000)) {
                if (M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0x108C) == 0) {
                    AddSafePointOnGeom(M2C_FIELD(arg0, void **, 0) + 0x9E0, M2C_FIELD(temp_a1, s32 *, 0x40), M2C_FIELD(temp_a1, s128 *, 0x60), M2C_FIELD(arg0, void **, 0));
                }
            }
        }
        break;
    }
}
