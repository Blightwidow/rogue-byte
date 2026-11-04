#include "m2c_macros.h"

s32 FIsGuardInSgs(void *, M2C_UNK);                 /* extern */
s32 GrfsgsFromSgs(M2C_UNK);                         /* extern */
void *PalertFind(void *);                           /* extern */
s128 PosLoWorld(void *);                            /* extern */
extern M2C_UNK D_FLT_002BD300;
extern M2C_UNK D_FLT_002BD310;
extern M2C_UNK D_FLT_002BD320;

void *GoalPartnerFollow_PloFindEnemy(void *arg0) {
    void *sp0;
    s128 sp10;
    f32 temp_v1;
    f32 var_f20;
    f32 var_f20_2;
    f32 var_f21;
    s32 temp_fp;
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_s3;
    s32 temp_s4;
    s32 var_s6;
    s32 var_s6_2;
    void **var_s2;
    void **var_s2_2;
    void *temp_s1_2;
    void *temp_s1_3;
    void *temp_s3_2;
    void *temp_v0;

    var_s6 = 0;
    var_f21 = 3.4028235e38f;
    sp0 = NULL;
    PosLoWorld(M2C_FIELD(arg0, void **, 0x10));
    sp10 = PosLoWorld(M2C_FIELD(arg0, void **, 0x30));
    temp_s0 = GrfsgsFromSgs(7);
    temp_s4 = GrfsgsFromSgs(0x10);
    temp_s3 = GrfsgsFromSgs(0x16);
    temp_s2 = GrfsgsFromSgs(0x17);
    temp_s1 = GrfsgsFromSgs(0x2A);
    temp_s3_2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), void **, 0x1088);
    temp_fp = temp_s0 | temp_s4 | temp_s3 | temp_s2 | temp_s1 | GrfsgsFromSgs(0x2B);
    if (M2C_FIELD(temp_s3_2, s32 *, 0x28) > 0) {
        var_s2 = temp_s3_2 + 0x2C;
        do {
            temp_s1_2 = *var_s2;
            if (!(temp_fp & M2C_FIELD(temp_s1_2, s64 *, 0x2C0))) {
                PosLoWorld(temp_s1_2);
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($sp) */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf3 */);
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                var_f20 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */);
                if (temp_s1_2 == M2C_FIELD(arg0, s32 *, 0x90)) {
                    var_f20 = M2C_FIELD(&D_FLT_002BD300, f32 *, 0) + (var_f20 * (M2C_FIELD(&D_FLT_002BD300, f32 *, 4) + (var_f20 * M2C_FIELD(&D_FLT_002BD300, f32 *, 8))));
                }
                if (FIsGuardInSgs(temp_s1_2, 3) != 0) {
                    var_f20 = M2C_FIELD(&D_FLT_002BD320, f32 *, 0) + (var_f20 * (M2C_FIELD(&D_FLT_002BD320, f32 *, 4) + (var_f20 * M2C_FIELD(&D_FLT_002BD320, f32 *, 8))));
                }
                if (var_f20 < var_f21) {
                    sp0 = temp_s1_2;
                    var_f21 = var_f20;
                }
            }
            var_s6 += 1;
            var_s2 += 4;
        } while (var_s6 < M2C_FIELD(temp_s3_2, s32 *, 0x28));
    }
    temp_v0 = PalertFind(M2C_FIELD(arg0, void **, 0x30));
    var_s6_2 = 0;
    if ((temp_v0 != NULL) && (M2C_FIELD(temp_v0, s32 *, 0x28) > 0)) {
        var_s2_2 = temp_v0 + 0x2C;
        do {
            temp_s1_3 = *var_s2_2;
            if (!(temp_fp & M2C_FIELD(temp_s1_3, s64 *, 0x2C0))) {
                PosLoWorld(temp_s1_3);
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($sp) */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf3 */);
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                temp_v1 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */);
                var_f20_2 = M2C_FIELD(&D_FLT_002BD310, f32 *, 0) + (temp_v1 * (M2C_FIELD(&D_FLT_002BD310, f32 *, 4) + (temp_v1 * M2C_FIELD(&D_FLT_002BD310, f32 *, 8))));
                if (temp_s1_3 == M2C_FIELD(arg0, s32 *, 0x90)) {
                    var_f20_2 = M2C_FIELD(&D_FLT_002BD300, f32 *, 0) + (var_f20_2 * (M2C_FIELD(&D_FLT_002BD300, f32 *, 4) + (var_f20_2 * M2C_FIELD(&D_FLT_002BD300, f32 *, 8))));
                }
                if (FIsGuardInSgs(temp_s1_3, 3) != 0) {
                    var_f20_2 = M2C_FIELD(&D_FLT_002BD320, f32 *, 0) + (var_f20_2 * (M2C_FIELD(&D_FLT_002BD320, f32 *, 4) + (var_f20_2 * M2C_FIELD(&D_FLT_002BD320, f32 *, 8))));
                }
                if (var_f20_2 < var_f21) {
                    sp0 = temp_s1_3;
                    var_f21 = var_f20_2;
                }
            }
            var_s6_2 += 1;
            var_s2_2 += 4;
        } while (var_s6_2 < M2C_FIELD(temp_v0, s32 *, 0x28));
    }
    return sp0;
}
