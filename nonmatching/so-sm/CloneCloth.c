#include "m2c_macros.h"

f32 CStackFrame_Construct();               /* extern */
M2C_UNK CStackFrame_Destructor(); /* extern */
M2C_UNK CloneBspc__FP4GEOMP4BSPCT0T1(); /* extern */
M2C_UNK CloneGeom(); /* extern */
M2C_UNK CopyAb__FPvT0Ui();             /* extern */
M2C_UNK InvertMatrix4Affine();     /* extern */
s32 PvAllocStackClearImpl__Fi(); /* extern */
M2C_UNK __ml__FRC7MATRIX4T0(); /* extern */

void CloneCloth(void *arg0, s32 arg1, s32 arg2, void *arg3) {
    char sp[0x400];
    M2C_UNK sp90;
    M2C_UNK spA0;
    M2C_UNK spB0;
    s32 sp40;
    s32 sp44;
    M2C_UNK sp60;
    s32 sp70;
    s128 sp80;
    M2C_UNK spC0;
    s32 *sp100;
    s128 *sp104;
    M2C_UNK *sp108;
    f32 var_f0;
    f32 var_f1;
    s32 *temp_s3;
    s32 *temp_s5;
    s32 temp_s0;
    s32 temp_s2;
    s32 temp_v0;
    s32 var_v0;
    void *temp_s4;

    var_f0 = CStackFrame_Construct(&sp60);
    sp100 = &sp40;
    sp104 = &sp80;
    sp108 = &spC0;
    M2C_FIELD(arg3, s32 *, 0) = arg1;
    var_f1 = 0.0f;
    M2C_FIELD(arg3, s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 4);
    M2C_FIELD(arg3, s32 *, 0xC) = (s32) M2C_FIELD(arg0, s32 *, 0xC);
    M2C_FIELD(arg3, s32 *, 0x1C) = (s32) M2C_FIELD(arg0, s32 *, 0x1C);
    var_v0 = M2C_FIELD(arg0, s32 *, 0x78);
    if (var_v0 > 0) {
        do {
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v1) */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
            var_f0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $a3, $vf1 */);
            if (var_f1 < var_f0) {
                var_f1 = var_f0;
            }
            var_v0 -= 1;
        } while (var_v0 != 0);
    }
    M2C_ERROR(/* unknown instruction: c1 0x10004 */);
    M2C_FIELD(arg3, f32 *, 8) = var_f0;
    temp_s4 = arg1 + 0x40;
    M2C_ERROR(/* unknown instruction: ldl $t0, 0x7f($s6) */);
    M2C_ERROR(/* unknown instruction: ldr $t0, 0x78($s6) */);
    M2C_ERROR(/* unknown instruction: ldl $v0, 0x87($s6) */);
    M2C_ERROR(/* unknown instruction: ldr $v0, 0x80($s6) */);
    M2C_ERROR(/* unknown instruction: ldl $a2, 0x8f($s6) */);
    M2C_ERROR(/* unknown instruction: ldr $a2, 0x88($s6) */);
    M2C_ERROR(/* unknown instruction: sdl $t0, 0x47($sp) */);
    M2C_ERROR(/* unknown instruction: sdr $t0, 0x40($sp) */);
    M2C_ERROR(/* unknown instruction: sdl $v0, 0x4f($sp) */);
    M2C_ERROR(/* unknown instruction: sdr $v0, 0x48($sp) */);
    M2C_ERROR(/* unknown instruction: sdl $a2, 0x57($sp) */);
    temp_s3 = arg3 + 0x78;
    temp_s5 = arg3 + 0x90;
    sp70 = (sp40 + arg2) * 0x10;
    M2C_FIELD(&sp70, s32 *, 4) = 0x10;
    temp_v0 = PvAllocStackClearImpl__Fi(&sp70, &sp70, M2C_ERROR(/* unknown instruction: sdr $a2, 0x50($sp) */));
    temp_s0 = M2C_FIELD(arg0, s32 *, 0x1C);
    temp_s2 = temp_s0 * 0x10;
    CopyAb__FPvT0Ui(temp_v0, sp44, temp_s2);
    CopyAb__FPvT0Ui(temp_v0 + ((temp_s0 + arg2) * 0x10), sp44 + temp_s2, (sp40 - temp_s0) * 0x10);
    sp44 = temp_v0;
    sp40 += arg2;
    InvertMatrix4Affine(sp108, temp_s4);
    __ml__FRC7MATRIX4T0(sp104, sp108, M2C_FIELD(arg0, s32 *, 0) + 0x40);
    CloneGeom(sp100, sp, temp_s3, sp90, sp80, sp90, spA0, spB0);
    CloneGeom(temp_s3, temp_s4, temp_s5);
    CloneBspc__FP4GEOMP4BSPCT0T1(arg0 + 0x68, arg0 + 0x90, arg3 + 0x68, temp_s5);
    CStackFrame_Destructor(&sp60, 2);
}
