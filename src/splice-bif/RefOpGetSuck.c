#include "types.h"

typedef struct RefCell { s32 tag; f32 value; } RefCell;

f32 GetSuck(void *);
extern s32 B_002DE578;

RefCell *RefOpGetSuck(RefCell *arg0) {
    arg0->value = GetSuck(&B_002DE578);
    arg0->tag = 0x16;
    return arg0;
}
