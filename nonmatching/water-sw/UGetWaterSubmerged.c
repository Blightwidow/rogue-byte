#include "m2c_macros.h"

M2C_UNK CStackFrame_Construct(M2C_UNK *);           /* extern */
M2C_UNK CStackFrame_Destructor(M2C_UNK *, M2C_UNK); /* extern */
s32 ClsgClipEdgeToObjects(s128, s128, s32, s32);    /* extern */
s32 CpartCollectAlo(void *, M2C_UNK *, M2C_UNK, s32); /* extern */
s32 FFloatsNear__Ffff(s128, s128, M2C_UNK);         /* extern */
s32 FIsBasicDerivedFrom(void *, M2C_UNK);           /* extern */
s128 PosLoWorld(void *);                            /* extern */
s32 PvAllocStackImpl__Fi(s32 *, M2C_UNK);           /* extern */
extern M2C_UNK func_00229D60;
extern s128 g_2a2dc0;
extern s128 g_2a2dd0;

f32 UGetWaterSubmerged(void *arg0, void *arg1, s128 *arg2, s128 *arg3) {
    M2C_UNK sp50;
    M2C_UNK sp70;
    M2C_UNK sp80;
    M2C_UNK sp84;
    M2C_UNK unksp18;
    M2C_UNK unksp8;
    s128 sp0;
    s128 sp10;
    M2C_UNK sp20;
    s32 sp30;
    M2C_UNK sp40;
    f32 var_f0;
    s128 temp_v0;
    s32 temp_v0_2;
    s32 var_s3;

    temp_v0 = PosLoWorld(arg1);
    sp0 = temp_v0;
    sp10 = temp_v0;
    if (FIsBasicDerivedFrom(arg1, 0x33) != 0) {
        unksp8 += M2C_FIELD(arg1, f32 *, 0x248);
        if (M2C_FIELD(arg1, s32 *, 0x208) != 0) {
            var_f0 = M2C_ERROR(/* unknown instruction: max.s $f0, $f0, $f1 */);
            goto block_4;
        }
    } else {
        var_f0 = M2C_FIELD(M2C_FIELD(arg1, void **, 0xEC), f32 *, 8);
block_4:
        unksp8 = var_f0;
    }
    unksp18 = M2C_FIELD(M2C_FIELD(arg1, void **, 0xEC), f32 *, 0x18);
    CStackFrame_Construct(&sp20);
    sp30 = M2C_FIELD(arg0, s32 *, 0xE0) * 4;
    M2C_FIELD(&sp30, s32 *, 4) = 0x10;
    temp_v0_2 = PvAllocStackImpl__Fi(&sp30, 0x10);
    if (ClsgClipEdgeToObjects(sp0, sp10, CpartCollectAlo(arg0, &func_00229D60, 0, temp_v0_2), temp_v0_2) == 0) {
        if (arg3 != NULL) {
            *arg3 = g_2a2dc0;
        }
        CStackFrame_Destructor(&sp20, 2);
        return 0.0f;
    }
    if (arg2 != NULL) {
        *arg2 = sp50;
    }
    if (arg3 != NULL) {
        *arg3 = sp70;
        var_s3 = 0;
        if ((FFloatsNear__Ffff(g_2a2dd0, sp70, 0x38D1B717) != 0) && (FFloatsNear__Ffff(M2C_ERROR(/* unknown instruction: prot3w $v0, $s0 */), M2C_ERROR(/* unknown instruction: prot3w $v0, $s1 */), 0x38D1B717) != 0)) {
            var_s3 = FFloatsNear__Ffff(M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s0 */), M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s1 */), 0x38D1B717) != 0;
        }
        if (var_s3 != 0) {
            *arg3 = g_2a2dc0;
        }
    }
    CStackFrame_Destructor(&sp20, 2);
    return sp84 - sp80;
}
