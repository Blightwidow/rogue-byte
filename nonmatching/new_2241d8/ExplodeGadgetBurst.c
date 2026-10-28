#include "m2c_macros.h"

M2C_UNK AddGadgetBurstWkr(void *, s32, s32, s128, s32 *, M2C_UNK *); /* extern */
M2C_UNK CStackFrame_Construct(M2C_UNK *);           /* extern */
M2C_UNK CStackFrame_Destructor(M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK IntersectSwBoundingSphere(M2C_UNK *, s128, M2C_UNK *, s32, f32); /* extern */
M2C_UNK LimitVectorLength__FP6VECTORfT0(M2C_UNK, f32); /* extern */
M2C_UNK PaloAbsorbWkr(M2C_UNK *);                   /* extern */
void *PhitfxSpawn(s32, s128, void *);               /* extern */
M2C_UNK SetVectorSphere__FP6VECTORfff(f32, f32, f32); /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK D_002C4368;
extern M2C_UNK D_FLT_002C4338;
extern M2C_UNK FFilterOxaBasic;

void ExplodeGadgetBurst(void *arg0, s32 arg1, s32 arg2, s128 arg3, f32 fparg0) {
    M2C_UNK sp10;
    M2C_UNK sp20;
    s32 spC20;
    s32 spC24;
    s32 spC28;
    s32 spC2C;
    s32 spC30;
    s128 spC40;
    M2C_UNK *var_s0_2;
    f32 temp_f12;
    s32 **temp_a0;
    s32 *temp_s0;
    s32 temp_s1;
    s32 var_s0;
    s32 var_s1;
    s32 var_s2;
    u32 var_v1;

    spC40 = arg3;
    spC30 = arg2;
    spC2C = arg1;
    CStackFrame_Construct(&sp10);
    IntersectSwBoundingSphere(&B_003DD490, spC40, &FFilterOxaBasic, M2C_FIELD(arg0, s32 *, 0xEC), fparg0);
    spC28 = 0;
    var_v1 = 0;
    do {
        temp_s1 = var_v1 * 4;
        var_s2 = 0;
        if (*(temp_s1 + &D_002C4368) > 0) {
            do {
                temp_s0 = temp_s1 + &D_002C4368;
                temp_f12 = (2.0f * (f32) var_s2 * 3.1415927f) / (f32) *temp_s0;
                var_s2 += 1;
                SetVectorSphere__FP6VECTORfff(temp_f12, *(temp_s1 + &D_FLT_002C4338), fparg0);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xc40($sp) */);
                M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf1, $vf2 */);
                M2C_ERROR(/* unknown instruction: qmfc2.ni $t0, $vf1 */);
                AddGadgetBurstWkr(arg0, spC2C, spC30, spC40, &spC28, &sp20);
            } while (var_s2 < *temp_s0);
        }
        var_v1 += 1;
    } while (var_v1 < 0xBU);
    var_s0 = 0;
    if (spC20 > 0) {
        do {
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0xc40($sp) */);
            temp_a0 = (var_s0 * 4) + spC24;
            var_s0 += 1;
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x70($v1) */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf1, $vf2 */);
            LimitVectorLength__FP6VECTORfT0(M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf2 */), fparg0);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xc40($sp) */);
            M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf1, $vf2 */);
            M2C_ERROR(/* unknown instruction: qmfc2.ni $t0, $vf1 */);
            AddGadgetBurstWkr(arg0, spC2C, spC30, spC40, &spC28, &sp20);
        } while (var_s0 < spC20);
    }
    var_s1 = 0;
    if (spC28 > 0) {
        var_s0_2 = &sp20;
        do {
            var_s1 += 1;
            PaloAbsorbWkr(var_s0_2);
            var_s0_2 += 0x60;
        } while (var_s1 < spC28);
    }
    M2C_FIELD(PhitfxSpawn(M2C_FIELD(&B_003DD490, s32 *, 0x402C), spC40, arg0), s32 *, 0x54) = 1;
    CStackFrame_Destructor(&sp10, 2);
}
