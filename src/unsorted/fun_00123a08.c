#include "types.h"

typedef struct RefCell { s32 tag; f32 value; } RefCell;

extern f32 g_2dded0;

RefCell *func_00123A08(RefCell *arg0) {
    arg0->value = g_2dded0;
    arg0->tag = 0x16;
    return arg0;
}
