#include "m2c_macros.h"

s32 AsgsFromGrfsgs(s64, void *);                    /* extern */
M2C_UNK func_00200F58(s32, s32, M2C_UNK, void *);   /* extern */

s32 func_00209A88(s32 arg0, void *arg1) {
    char sp[0x400];
    func_00200F58(arg0, AsgsFromGrfsgs(M2C_FIELD(arg1, s64 *, 0x2C0), sp), 0x1010, sp);
    return arg0;
}
