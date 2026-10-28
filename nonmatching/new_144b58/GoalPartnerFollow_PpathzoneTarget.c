#include "m2c_macros.h"

s32 FIsBasicDerivedFrom(void *, M2C_UNK);           /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
s32 PpathzoneFindPos(M2C_UNK, M2C_UNK);             /* extern */

s32 GoalPartnerFollow_PpathzoneTarget(void *arg0) {
    s32 var_v0;
    void *temp_a0;
    void *var_v1;

    if (FIsBasicDerivedFrom(M2C_FIELD(arg0, void **, 0x30), 0x30) != 0) {
        temp_a0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), void **, 0xE8);
        var_v1 = NULL;
        if (temp_a0 != NULL) {
            var_v1 = M2C_FIELD(temp_a0, void **, 0xDC);
        }
        var_v0 = 0;
        if (var_v1 != NULL) {
            return M2C_FIELD(var_v1, s32 *, 0x10);
        }
        /* Duplicate return node #6. Try simplifying control flow for better match */
        return var_v0;
    }
    PosLoWorld(M2C_FIELD(arg0, void **, 0x30));
    var_v0 = PpathzoneFindPos(M2C_ERROR(/* unknown instruction: por $a0, $zero, $v0 */), 1);
    return var_v0;
}
