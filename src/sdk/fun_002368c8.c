#include "types.h"

s32 func_00235B08(s32, s32, s32, s32, void *);

s32 func_002368C8(s32 arg0, s32 arg1, s32 *arg2, s32 arg3, ...) {
    void *args;
    s32 result;

    args = (char *)__builtin_next_arg(arg3) - 0x20;
    result = func_00235B08(arg0, arg1, *arg2, arg3, args);
    *arg2 -= result;
    return result;
}
