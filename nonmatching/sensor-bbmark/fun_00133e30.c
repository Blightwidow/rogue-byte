#include "m2c_macros.h"

void func_00133E30(void *arg0) {
    void *temp_a1;
    void *temp_v0;

    if (M2C_FIELD(arg0, void **, 0x3D28) != NULL) {
        do {
            temp_a1 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x3D28), void **, 0x60);
            temp_v0 = M2C_FIELD(temp_a1, void **, 0xC);
            M2C_FIELD(temp_v0, M2C_UNK (**)(void *, void *), 0x18C)(temp_a1 + M2C_FIELD(temp_v0, s16 *, 0x188), temp_a1);
        } while (M2C_FIELD(arg0, void **, 0x3D28) != NULL);
    }
}
