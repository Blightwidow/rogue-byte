#include "m2c_macros.h"

M2C_UNK func_001A58D0(void *, s32, M2C_UNK);        /* extern */

void func_001C48C0(void *arg0) {
    s32 var_s2;
    void **var_s1;
    void *var_a0;

    var_s2 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x4778) > 0) {
        var_s1 = arg0 + 0x477C;
        var_a0 = M2C_FIELD(arg0, void **, 0x477C);
loop_2:
        var_s2 += 1;
        var_s1 += 4;
        *M2C_FIELD(M2C_FIELD(var_a0, void **, 0xE4), s32 **, 8) = M2C_FIELD(arg0, s32 *, 0x3EFC);
        func_001A58D0(var_a0, M2C_FIELD(arg0, s32 *, 0x3EFC), 0);
        if (var_s2 < M2C_FIELD(arg0, s32 *, 0x4778)) {
            var_a0 = *var_s1;
            goto loop_2;
        }
    }
}
