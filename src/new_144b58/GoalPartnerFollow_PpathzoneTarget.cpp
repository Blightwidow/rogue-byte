#include "m2c_macros.h"
extern "C" {

s32 FIsBasicDerivedFrom(void *, M2C_UNK);           /* extern */
s128 PosLoWorld(void *);                         /* extern */
s32 PpathzoneFindPos(s128, M2C_UNK);             /* extern */

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
    var_v0 = PpathzoneFindPos(PosLoWorld(M2C_FIELD(arg0, void **, 0x30)), 1);
    return var_v0;
}
}
