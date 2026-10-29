#include "m2c_macros.h"
extern "C" {
void *func_001236D8(s32 *arg0, void *arg1, f32 *arg2) {
    *(s32 *)&arg0[1] = (s32)arg2[1];
    arg0[0] = 0x15;
    return arg0;
}
}
