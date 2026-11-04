#include "m2c_macros.h"

M2C_UNK CStackFrame_Construct(M2C_UNK *);           /* extern */
M2C_UNK CStackFrame_Destructor(M2C_UNK *, M2C_UNK); /* extern */
s32 ClsgClipEdgeToObjects(s128, s128, s32, s32);    /* extern */
s32 CpartCollectAlo(void *, M2C_UNK *, M2C_UNK, s32); /* extern */
M2C_UNK PosLoWorld(s128);                           /* extern */
s32 PvAllocStackImpl__Fi(s32 *, M2C_UNK);           /* extern */
extern M2C_UNK func_00229D60;
extern s128 g_2a2dd0;

s32 FFindWaterSurface(void *arg0, void *arg1, s32 arg2) {
    M2C_UNK sp10;
    M2C_UNK sp20;
    f32 sp18;
    f32 sp28;
    M2C_UNK sp30;
    M2C_UNK sp630;
    s32 sp640;
    s32 temp_v0;

    PosLoWorld(g_2a2dd0);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf3, $vf1 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x20($sp) */);
    sp18 += M2C_FIELD(arg0, f32 *, 0x1098);
    sp28 += M2C_FIELD(arg0, f32 *, 0x109C);
    CStackFrame_Construct(&sp630);
    sp640 = M2C_FIELD(arg1, s32 *, 0xE0) * 4;
    M2C_FIELD(&sp640, s32 *, 4) = 0x10;
    temp_v0 = PvAllocStackImpl__Fi(&sp640, 0x10);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($sp) */);
    if (ClsgClipEdgeToObjects(sp20, sp10, CpartCollectAlo(arg1, &func_00229D60, 0, temp_v0), temp_v0) != 0) {
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($sp) */);
        M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf1, $vf2 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($s3) */);
        CStackFrame_Destructor(&sp630, 2);
        return 1;
    }
    CStackFrame_Destructor(&sp630, 2);
    return 0;
}
