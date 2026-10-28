#include "m2c_macros.h"

M2C_UNK func_001F5078(void *);                      /* extern */

void RemoveSoXa__FP2SOP2XA(void *arg0, void *arg1) {
    void *temp_v0;
    void *temp_v0_2;
    void *var_a2;
    void *var_v1;

    temp_v0 = M2C_FIELD(arg0, void **, 0x138);
    var_a2 = arg0 + 0x138;
    if (temp_v0 != NULL) {
        if (temp_v0 != arg1) {
            var_v1 = M2C_FIELD(arg0, void **, 0x138);
loop_5:
            temp_v0_2 = M2C_FIELD(var_v1, void **, 8);
            var_a2 = var_v1 + 8;
            if (temp_v0_2 != NULL) {
                if (temp_v0_2 != arg1) {
                    var_v1 = M2C_FIELD(var_v1, void **, 8);
                    goto loop_5;
                }
                M2C_FIELD(var_v1, void **, 8) = (void *) M2C_FIELD(arg1, void **, 8);
                goto block_10;
            }
        } else {
            M2C_FIELD(arg0, void **, 0x138) = (void *) M2C_FIELD(arg1, void **, 8);
block_10:
            M2C_FIELD(arg1, void **, 8) = NULL;
        }
    }
    func_001F5078(var_a2);
}
