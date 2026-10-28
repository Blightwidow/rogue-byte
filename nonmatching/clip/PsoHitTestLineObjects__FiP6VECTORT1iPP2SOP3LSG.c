#include "m2c_macros.h"

s32 ClsgClipEdgeToObject(); /* extern */

s32 PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(s32 arg0, s32 arg3) {
    char sp[0x400];
    M2C_UNK sp40;
    f32 temp_f0;
    f32 var_f20;
    s32 temp_s0;
    s32 temp_v0;
    s32 var_s1;
    s32 var_s3;
    u8 *var_v0;
    s32 var_v1;
    void *temp_a0;
    void *temp_s2;
    void *var_v0_2;
    void *var_v1_2;

    var_s1 = 0;
    temp_s2 = M2C_ERROR(/* Read from unset register $t1 */);
    var_s3 = 0;
    M2C_ERROR(/* unknown instruction: por $s5, $zero, $a2 */);
    M2C_ERROR(/* unknown instruction: por $s6, $zero, $a1 */);
    var_f20 = 3.4028235e38f;
    if (arg3 > 0) {
        var_v0 = 0 * 4;
        do {
            temp_s0 = *(var_v0 + M2C_ERROR(/* Read from unset register $t0 */));
            temp_v0 = ClsgClipEdgeToObject(temp_s0, M2C_ERROR(/* unknown instruction: por $a1, $zero, $s6 */), M2C_ERROR(/* unknown instruction: por $a2, $zero, $s5 */), 2);
            var_v1 = 0;
            if ((temp_v0 > 0) && (sp40 == 0.0f)) {
                var_v1 = !(arg0 & 1) ? 0 : 1;
            }
            if (var_v1 < temp_v0) {
                var_v0_2 = (var_v1 * 0x60) + sp;
                temp_f0 = M2C_FIELD(var_v0_2, f32 *, 0x40);
                if (temp_f0 < var_f20) {
                    var_f20 = temp_f0;
                    var_s3 = temp_s0;
                    if (temp_s2 != NULL) {
                        var_v1_2 = temp_s2;
                        temp_a0 = var_v0_2 + 0x60;
                        do {
                            M2C_FIELD(var_v1_2, s128 *, 0) = (s128) M2C_FIELD(var_v0_2, s128 *, 0);
                            M2C_FIELD(var_v1_2, s128 *, 0x10) = (s128) M2C_FIELD(var_v0_2, s128 *, 0x10);
                            var_v0_2 += 0x20;
                            var_v1_2 += 0x20;
                        } while (var_v0_2 != temp_a0);
                    }
                }
            }
            var_s1 += 1;
            var_v0 = var_s1 * 4;
        } while (var_s1 < arg3);
    }
    return var_s3;
}
