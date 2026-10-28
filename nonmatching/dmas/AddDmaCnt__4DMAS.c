#include "m2c_macros.h"

M2C_UNK EndDmaCnt__4DMAS();                         /* extern */

void AddDmaCnt__4DMAS(void *arg0) {
    s64 *temp_v1;

    EndDmaCnt__4DMAS();
    temp_v1 = M2C_FIELD(arg0, s64 **, 0xC);
    M2C_FIELD(arg0, s64 **, 8) = temp_v1;
    M2C_FIELD(arg0, s64 **, 0xC) = (s64 *) (temp_v1 + 0x10);
    *temp_v1 = 0x10000000;
    M2C_FIELD(M2C_FIELD(arg0, s64 **, 8), s64 *, 8) = 0;
}
