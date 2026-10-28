#include "m2c_macros.h"

M2C_UNK RemoveDlEntry(M2C_UNK *, void *);           /* extern */
M2C_UNK func_001F4BA8();                            /* extern */
extern M2C_UNK B_003E11C4;

void func_001F4D50(void *arg0) {
    s64 temp_a1;
    void *temp_v1;

    func_001F4BA8();
    temp_v1 = M2C_FIELD(arg0, void **, 0xEC);
    if (temp_v1 != NULL) {
        temp_a1 = M2C_FIELD(temp_v1, s64 *, 0x70);
        if (temp_a1 & 2) {
            M2C_FIELD(temp_v1, s64 *, 0x70) = (s64) (temp_a1 & ~2);
            RemoveDlEntry(&B_003E11C4, M2C_FIELD(arg0, void **, 0xEC));
        }
    }
}
