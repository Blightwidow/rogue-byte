#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
int TriggerRsmg(void *, int, int, void *, int);
extern int B_003DD490;
typedef void (*Fn6)(void *, int, int, int, int, int);

void func_00181780(s8 *arg0) {
    TriggerRsmg(&B_003DD490, M2C_FIELD(arg0, s32 *, 0x200), (int)(arg0 + 0x204), arg0, 1);
    s8 *vtable = M2C_FIELD(arg0, s8 **, 0xC);
    s16 offset = M2C_FIELD(vtable, s16 *, 0x18);
    Fn6 method = M2C_FIELD(vtable, Fn6 *, 0x1C);
    method(arg0 + offset, 5, 0, 0, 0, 0);
}
}
