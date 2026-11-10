#include "types.h"
extern "C" {
typedef struct FADE {
    char pad[0x40];
    s32 field_0x40;
} FADE;
s32 InitLo();
s32 func_001A6CA8(FADE *, s32);
void InitFade(FADE *fade) {
    s32 flags;
    InitLo();
    func_001A6CA8(fade, 1);
    flags = fade->field_0x40;
    if ((flags ^ 1) & 1) {
        *(s32 *)flags = (s32) (*(s32 *)flags | 0xA);
        return;
    }
    fade->field_0x40 = (s32) (flags | 0xA);
}
}
