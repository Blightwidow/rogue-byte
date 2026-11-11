#include "types.h"
extern "C" {
struct RefCell { s32 tag; s32 value; };
struct RefCellF32 { s32 tag; f32 value; };
RefCell *func_00123668(RefCell *arg0, s8 *unused_arg1, RefCellF32 *arg2) {
    arg0->value = arg2->value;
    arg0->tag = 0x15;
    return arg0;
}
}
