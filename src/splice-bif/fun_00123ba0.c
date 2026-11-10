#include "types.h"

typedef struct RefCellS32 { s32 tag; s32 value; } RefCellS32;

s32 func_00210B68();                                /* extern */

RefCellS32 *func_00123BA0(RefCellS32 *ref) {
    ref->value = func_00210B68();
    ref->tag = 0x15;
    return ref;
}
