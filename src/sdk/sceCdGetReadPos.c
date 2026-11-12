#include "types.h"

extern s32 D_002C67A0;
extern s32 D_002C7900;

s32 sceCdGetReadPos(void) {
    if (D_002C67A0 == 1) {
        return *(s32 *)((u32)&D_002C7900 | 0x20000000);
    }
    return 0;
}
