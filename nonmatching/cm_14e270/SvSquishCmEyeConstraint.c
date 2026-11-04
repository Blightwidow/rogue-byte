#include "m2c_macros.h"

M2C_UNK GSmooth__FfffP3SMPPf(M2C_UNK *, f32 *, M2C_UNK, f32, f32); /* extern */
M2C_UNK func_002564B8(M2C_UNK *);                   /* extern */
extern f32 B_FLT_002DDEE0;
extern M2C_UNK D_002BD8E0;
extern f32 D_FLT_002BD8D8;

f32 SvSquishCmEyeConstraint(void *arg0, s128 arg2, void *arg3) {
    char sp[0x400];
    M2C_UNK sp10;
    f32 sp20;
    s128 sp30;
    s128 sp40;
    s128 sp50;

    sp50 = arg2;
    sp30 = M2C_FIELD(arg3, s128 *, 0x10);
    sp40 = M2C_FIELD(arg3, s128 *, 0);
    func_002564B8(sp);
    func_002564B8(&sp10);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x40($sp) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf3, $vf4 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf1, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
    M2C_ERROR(/* unknown instruction: vmaddaz.x $acc, $vf1, $vf2z */);
    M2C_ERROR(/* unknown instruction: vmsubw.x $vf2, $vf1, $vf3w */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
    GSmooth__FfffP3SMPPf(&D_002BD8E0, &sp20, M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */), M2C_FIELD(arg0, f32 *, 0x48) - D_FLT_002BD8D8, B_FLT_002DDEE0);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($s0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x50($sp) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf1 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    return M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) - sp20;
}
