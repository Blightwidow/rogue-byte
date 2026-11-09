#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001F4BA8 {
    /* 0x00 */ char pad0[0x10];
};                                                  /* size = 0x10 */
M2C_UNK RemoveDlEntry(M2C_UNK *, s8 *);   /* extern */
extern M2C_UNK B_003E11B8;
struct Dl4BA8 { char pad[0x70]; u64 flags; };
struct Obj4BA8 { char pad[0xEC]; Dl4BA8 *list; };
void func_001F4BA8(Obj4BA8 *self) {
    Dl4BA8 *list = self->list;
    if (list == NULL) return;
    s64 flags = list->flags;
    if ((flags & 1) == 0) return;
    list->flags = flags & ~(s64) 1;
    RemoveDlEntry(&B_003E11B8, (s8 *) self->list);
}
}
