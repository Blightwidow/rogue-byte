#include "m2c_macros.h"

M2C_UNK CheckReg__4GIFSii(M2C_UNK, M2C_UNK);        /* extern */

void PackSTQ__4GIFSfff(void *arg0, f32 fparg0, f32 fparg1, f32 fparg2) {
    void *temp_v0;

    CheckReg__4GIFSii(1, 2);
    temp_v0 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(arg0, void **, 0xC) = (void *) (temp_v0 + 0x10);
    M2C_FIELD(temp_v0, f32 *, 8) = fparg2;
    M2C_FIELD(temp_v0, f32 *, 0) = fparg0;
    M2C_FIELD(temp_v0, f32 *, 4) = fparg1;
}
