#include "m2c_macros.h"

void **PvAllocStackImpl__Fi(void *, s32, s32);      /* extern */
extern void *B_003E0714;

void func_001B44D8(s32 *arg0, void ***arg1) {
    char sp[0x400];
    s32 temp_v0;
    s32 var_a1;
    s32 var_a3;
    s32 var_v0;
    s32 var_v1;
    void **temp_v0_2;
    void **var_a2;
    void *temp_v1;
    void *var_a0;
    void *var_a0_2;

    var_v1 = 0;
    var_a0 = B_003E0714;
    if (var_a0 != NULL) {
        do {
            temp_v0 = M2C_FIELD(var_a0, s32 *, 0xE0);
            var_a0 = M2C_FIELD(var_a0, void **, 0x20);
            var_v1 += temp_v0;
        } while (var_a0 != NULL);
    }
    temp_v0_2 = PvAllocStackImpl__Fi(sp, var_v1 * 4, 0x10);
    var_a0_2 = B_003E0714;
    var_a2 = temp_v0_2;
    if (var_a0_2 != NULL) {
        var_v0 = M2C_FIELD(var_a0_2, s32 *, 0xE0);
loop_4:
        var_a1 = 0;
        if (var_v0 > 0) {
            var_a3 = 0;
            do {
                temp_v1 = M2C_FIELD(var_a0_2, s32 *, 0xE4) + var_a3;
                if (!(M2C_FIELD(temp_v1, s64 *, 0x10) & (0x8000 << 0x21))) {
                    *var_a2 = temp_v1;
                    var_a2 += 4;
                }
                var_a1 += 1;
                var_a3 += 0xB0;
            } while (var_a1 < M2C_FIELD(var_a0_2, s32 *, 0xE0));
        }
        var_a0_2 = M2C_FIELD(var_a0_2, void **, 0x20);
        if (var_a0_2 != NULL) {
            var_v0 = M2C_FIELD(var_a0_2, s32 *, 0xE0);
            goto loop_4;
        }
    }
    *arg0 = (s32) (var_a2 - temp_v0_2) >> 2;
    *arg1 = temp_v0_2;
}
