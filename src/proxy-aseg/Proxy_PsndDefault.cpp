#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK AddProxySnd(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, f32, f32); /* extern */

s32 Proxy_PsndDefault(s8 *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0xE0) == 0) {
        M2C_FIELD(arg0, s32 *, 0xE0) = M2C_FIELD(arg0, s32 *, 0xE8) + M2C_FIELD(arg0, s32 *, 0xE4) * 0x14;
        AddProxySnd(arg0, -1, 0x12C, 0xBB8, 1.0f, 0.0f);
    }
    return M2C_FIELD(arg0, s32 *, 0xE0);
}
}
