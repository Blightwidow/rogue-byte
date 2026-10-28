#include "m2c_macros.h"

M2C_UNK vprintf(s64 *);                             /* extern */

void printf(s64 arg1, s64 arg2, s64 arg3, f32 fparg0, f32 fparg2, f32 fparg4, f32 fparg6) {
    f32 sp48;
    f32 sp4C;
    f32 sp50;
    f32 sp54;
    s64 sp58;
    s64 sp60;
    s64 sp68;
    s64 sp70;
    s64 sp78;
    s64 sp80;
    s64 sp88;

    sp58 = arg1;
    sp60 = arg2;
    sp68 = arg3;
    sp70 = M2C_ERROR(/* Read from unset register $t0 */);
    sp78 = M2C_ERROR(/* Read from unset register $t1 */);
    sp80 = M2C_ERROR(/* Read from unset register $t2 */);
    sp88 = M2C_ERROR(/* Read from unset register $t3 */);
    sp48 = fparg0;
    sp4C = fparg2;
    sp50 = fparg4;
    sp54 = fparg6;
    vprintf(&sp58);
}
