#include "m2c_macros.h"

s32 ClsgClipEdgeToBsp(s32, M2C_UNK);                /* extern */
s32 ClsgClipEdgeToSphere__FP6VECTORfT0T0iP3LSG(s128, M2C_UNK, M2C_UNK, M2C_UNK, f32); /* extern */

s32 ClsgClipEdgeToObjectPruned(void *arg0, s32 arg1) {
    if (arg1 != 0) {
        return ClsgClipEdgeToBsp(arg1, 0x7FFFFFFF);
    }
    if (M2C_FIELD(arg0, s64 *, 0x10) & (0x8000 << 0x22)) {
        return ClsgClipEdgeToSphere__FP6VECTORfT0T0iP3LSG(M2C_FIELD(M2C_FIELD(arg0, void **, 0), s128 *, 0x70), M2C_ERROR(/* unknown instruction: por $a1, $zero, $a2 */), M2C_ERROR(/* unknown instruction: por $a2, $zero, $a3 */), M2C_ERROR(/* Read from unset register $t0 */), M2C_FIELD(arg0, f32 *, 8));
    }
    return 0;
}
