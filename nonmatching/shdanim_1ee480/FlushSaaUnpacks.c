#include "m2c_macros.h"

M2C_UNK func_001EC718(void *);                      /* extern */
extern void *B_003E159C;

void FlushSaaUnpacks(void) {
    void *var_s0;
    void *var_s1;

    var_s1 = B_003E159C;
    if (var_s1 != NULL) {
        do {
            if (M2C_FIELD(var_s1, s32 *, 0x2C) != 0) {
                var_s0 = M2C_FIELD(var_s1, void **, 0x34);
                M2C_FIELD(var_s1, s32 *, 0x2C) = 0;
                if (var_s0 != NULL) {
                    do {
                        func_001EC718(var_s0);
                        var_s0 = M2C_FIELD(var_s0, void **, 0x10);
                    } while (var_s0 != NULL);
                }
            }
            var_s1 = M2C_FIELD(var_s1, void **, 0x40);
        } while (var_s1 != NULL);
    }
}
