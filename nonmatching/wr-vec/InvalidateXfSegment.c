#include "m2c_macros.h"

extern M2C_UNK D_002C44E0;

void InvalidateXfSegment(void *arg0, void *arg1) {
    s16 temp_v1;
    void *temp_v0;

    temp_v1 = M2C_FIELD(arg1, s16 *, 0x98);
    switch (temp_v1) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 13:
    case 14:
    case 15:
    case 16:
    case 20:
    case 21:
        break;
    default:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 17:
    case 18:
    case 19:
        M2C_FIELD(arg1, M2C_UNK **, 0x88) = &D_002C44E0;
        M2C_FIELD(arg1, f32 *, 0x80) = -3.4028235e38f;
        M2C_FIELD(arg1, f32 *, 0x84) = -3.4028235e38f;
        M2C_FIELD(arg1, M2C_UNK **, 0x8C) = &D_002C44E0;
        break;
    }
    M2C_FIELD(arg1, s16 *, 0x9A) = 0;
    temp_v0 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK, void *), 0x17C)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x178), 4, arg0);
}
