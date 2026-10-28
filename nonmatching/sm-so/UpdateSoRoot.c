#include "m2c_macros.h"

M2C_UNK AddSoGeomsToOxa(void *);                    /* extern */
M2C_UNK RemoveSoGeomsFromOxa(void *);               /* extern */
M2C_UNK func_001A5B80();                            /* extern */

void UpdateSoRoot(void *arg0, s32 arg1, void *arg2) {
    s64 temp_v1;
    s64 temp_v1_2;
    s64 temp_v1_3;
    void *temp_v0;
    void *var_a0;
    void *var_a2;
    void *var_s0;
    void *var_s0_2;

    func_001A5B80();
    var_s0 = M2C_FIELD(arg0, void **, 0x64);
    if (var_s0 != NULL) {
        do {
            temp_v0 = M2C_FIELD(var_s0, void **, 0xC);
            M2C_FIELD(temp_v0, M2C_UNK (**)(void *, s32, void *), 0x6C)(var_s0 + M2C_FIELD(temp_v0, s16 *, 0x68), arg1, arg2);
            var_s0 = M2C_FIELD(var_s0, void **, 0x24);
        } while (var_s0 != NULL);
    }
    if (M2C_FIELD(arg0, s32 *, 0xE0) != 0) {
        temp_v1 = 0x8000 << 0x29;
        if (!(M2C_FIELD(arg0, s64 *, 0x28) & temp_v1)) {
            var_a2 = arg2;
            if (arg0 != arg1) {
                var_s0_2 = M2C_FIELD(arg0, void **, 0x10);
loop_6:
                if (!(M2C_FIELD(var_s0_2, s64 *, 0x28) & temp_v1)) {
                    if (var_s0_2 != arg1) {
                        var_s0_2 = M2C_FIELD(var_s0_2, void **, 0x10);
                        goto loop_6;
                    }
                    var_a2 = arg2;
                    goto block_11;
                }
            } else {
block_11:
                var_a0 = M2C_FIELD(arg0, void **, 0x10);
                if (var_a2 != NULL) {
                    temp_v1_2 = 0x8000 << 0x29;
                    if (!(M2C_FIELD(var_a2, s64 *, 0x28) & temp_v1_2)) {
loop_13:
                        var_a2 = M2C_FIELD(var_a2, void **, 0x10);
                        if (var_a2 != NULL) {
                            if (!(M2C_FIELD(var_a2, s64 *, 0x28) & temp_v1_2)) {
                                goto loop_13;
                            }
                        }
                    }
                }
                if (var_a0 != NULL) {
                    temp_v1_3 = 0x8000 << 0x29;
                    if (!(M2C_FIELD(var_a0, s64 *, 0x28) & temp_v1_3)) {
                        var_a0 = M2C_FIELD(var_a0, void **, 0x10);
loop_18:
                        if (var_a0 != NULL) {
                            if (!(M2C_FIELD(var_a0, s64 *, 0x28) & temp_v1_3)) {
                                var_a0 = M2C_FIELD(var_a0, void **, 0x10);
                                goto loop_18;
                            }
                        }
                    }
                }
                if ((var_a2 == NULL) && (var_a0 == NULL)) {
                    RemoveSoGeomsFromOxa(arg0);
                    AddSoGeomsToOxa(arg0);
                }
            }
        }
    }
}
