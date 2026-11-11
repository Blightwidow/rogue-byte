#include "types.h"

typedef struct RefCellS32 { s32 tag; s32 value; } RefCellS32;

s32 IdCurrentLevel();                               /* extern */

RefCellS32 *RefOpIdCurrentLevel(RefCellS32 *ref) {
    ref->value = IdCurrentLevel();
    ref->tag = 0x15;
    return ref;
}
