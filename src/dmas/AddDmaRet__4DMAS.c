#include "m2c_macros.h"

M2C_UNK EndDmaCnt__4DMAS();                         /* extern */

void AddDmaRet__4DMAS(void *arg0) {
    void *temp_v1;

    EndDmaCnt__4DMAS();
    temp_v1 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(arg0, void **, 0xC) = (void *) (temp_v1 + 0x10);
    M2C_FIELD(temp_v1, s64 *, 0) = 0x60000000;
    M2C_FIELD(temp_v1, s64 *, 8) = 0;
}
