#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define NULL 0
extern "C" {
void func_001F6A68(s8 *arg0) {
    for (s32 i = 0; i < M2C_FIELD(arg0, s32 *, 0xB8); i++) {
        s8 *e = M2C_FIELD(arg0, s8 **, 0xC0) + i * 0x28;
        s8 *o = M2C_FIELD(e, s8 **, 0x24);
        M2C_FIELD(e, s32 *, 0xC) |= 0x800;
        if (o != NULL) M2C_FIELD(o, u64 *, 0x10) |= ((u64)0x8000 << 0x23);
    }
}
}
