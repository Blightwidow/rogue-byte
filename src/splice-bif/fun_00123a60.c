#include "types.h"

typedef struct RefCellS32 { s32 tag; s32 value; } RefCellS32;

s32 func_00210A98();                                /* extern */

RefCellS32 *func_00123A60(RefCellS32 *ref) {
    ref->value = func_00210A98();
    ref->tag = 0x15;
    return ref;
}
