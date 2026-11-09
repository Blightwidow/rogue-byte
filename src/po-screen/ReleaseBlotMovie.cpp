#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
void ClearSl(s8 *);

void ReleaseBlotMovie(s8 *arg0) {
    s8 *temp_v0;

    M2C_FIELD(arg0, s32 *, 0xF8) = 0;
    M2C_FIELD(arg0, s32 *, 0x50) = 0;
    M2C_FIELD(arg0, s32 *, 0x54) = 0;
    M2C_FIELD(arg0, s16 *, 0x80) = 0;
    M2C_FIELD(arg0, s32 *, 0x84) = 0;
    ClearSl(arg0 + 0xFC);
    temp_v0 = M2C_FIELD(arg0, s8 **, 0xC0);
    M2C_FIELD(temp_v0, s32 *, 0x44) = 0;
    M2C_FIELD(temp_v0, s32 *, 0x48) = 0;
}

}
