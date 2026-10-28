#include "m2c_macros.h"

M2C_UNK vsprintf(s64 *);                            /* extern */

void sprintf(s64 arg2, s64 arg3, f32 fparg0, f32 fparg2, f32 fparg4, f32 fparg6) {
    f32 sp40;
    f32 sp44;
    f32 sp48;
    f32 sp4C;
    s64 sp50;
    s64 sp58;
    s64 sp60;
    s64 sp68;
    s64 sp70;
    s64 sp78;

    sp50 = arg2;
    sp58 = arg3;
    sp60 = M2C_ERROR(/* Read from unset register $t0 */);
    sp68 = M2C_ERROR(/* Read from unset register $t1 */);
    sp70 = M2C_ERROR(/* Read from unset register $t2 */);
    sp78 = M2C_ERROR(/* Read from unset register $t3 */);
    sp40 = fparg0;
    sp44 = fparg2;
    sp48 = fparg4;
    sp4C = fparg6;
    vsprintf(&sp50);
}
