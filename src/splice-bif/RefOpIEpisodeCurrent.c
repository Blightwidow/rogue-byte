#include "types.h"

typedef struct RefCellS32 { s32 tag; s32 value; } RefCellS32;

s32 IEpisodeCurrent();                              /* extern */

RefCellS32 *RefOpIEpisodeCurrent(RefCellS32 *ref) {
    ref->value = IEpisodeCurrent();
    ref->tag = 0x15;
    return ref;
}
