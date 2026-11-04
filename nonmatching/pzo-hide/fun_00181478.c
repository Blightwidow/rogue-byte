#include "m2c_macros.h"

M2C_UNK PosLoWorld(s32);                            /* extern */
M2C_UNK UpdateSo();                                 /* extern */
s32 func_0017F550(void *);                          /* extern */
M2C_UNK func_001815E8(void *, M2C_UNK);             /* extern */
extern f32 g_2be880;
extern s32 g_2dfb80;

void func_00181478(void *arg0) {
    s32 temp_s1;
    s32 var_v0;

    UpdateSo();
    do {
        temp_s1 = M2C_FIELD(arg0, s32 *, 0x1C0);
        switch (temp_s1) {                          /* irregular */
        case 0:
            if (g_2dfb80 != 0) {
                PosLoWorld(g_2dfb80);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
                PosLoWorld(M2C_FIELD(arg0, s32 *, 0x1CC));
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
                var_v0 = 1;
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                if (!(M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */) < g_2be880)) {
                    var_v0 = 0;
                }
                if (var_v0 != 0) {
                    M2C_FIELD(arg0, s32 *, 0x1C8) = (s32) g_2dfb80;
                    func_001815E8(arg0, 1);
                }
            }
            break;
        case 1:
            if (func_0017F550(arg0) != 0) {
                func_001815E8(arg0, 2);
            }
            break;
        }
    } while (M2C_FIELD(arg0, s32 *, 0x1C0) != temp_s1);
}
