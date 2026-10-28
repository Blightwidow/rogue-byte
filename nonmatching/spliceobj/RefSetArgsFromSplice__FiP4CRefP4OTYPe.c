#include "m2c_macros.h"

M2C_UNK RefSetPvsFromSplice__FiP4CRefP4OTYPPPv(s32); /* extern */

s32 RefSetArgsFromSplice__FiP4CRefP4OTYPe(s32 arg0, s32 arg1, f32 fparg0, f32 fparg2, f32 fparg4, f32 fparg6) {
    char sp[0x400];
    f32 spD0;
    f32 spD4;
    f32 spD8;
    f32 spDC;
    s64 spE0;
    s64 spE8;
    s64 spF0;
    s64 spF8;
    s32 *var_a0;
    s32 var_v1;
    s64 *var_t0;

    spE0 = M2C_ERROR(/* Read from unset register $t0 */);
    var_t0 = &spE0;
    spE8 = M2C_ERROR(/* Read from unset register $t1 */);
    spF0 = M2C_ERROR(/* Read from unset register $t2 */);
    spF8 = M2C_ERROR(/* Read from unset register $t3 */);
    spD0 = fparg0;
    spD4 = fparg2;
    spD8 = fparg4;
    spDC = fparg6;
    if (arg1 > 0) {
        var_a0 = sp;
        var_v1 = arg1;
        do {
            var_t0 += 8;
            var_v1 -= 1;
            *var_a0 = M2C_FIELD(var_t0, s32 *, -8);
            var_a0 += 4;
        } while (var_v1 != 0);
    }
    RefSetPvsFromSplice__FiP4CRefP4OTYPPPv(arg0);
    return arg0;
}
