#include "types.h"
extern "C" {
typedef struct SPRITEENTRY {
    char pad0[8];
    s16 field_0x8;
    char pad1[0xE];
} SPRITEENTRY;

typedef struct SPRITEBANK {
    char pad0[4];
    SPRITEENTRY *field_0x4;
    SPRITEENTRY *field_0x8;
} SPRITEBANK;

s32 QueueSpriteInstanceSlots(SPRITEENTRY *, s32, s32);

void func_002185F8(SPRITEBANK *arg0, s32 arg1, s32 arg2) {
    s16 temp_v0;

    temp_v0 = arg0->field_0x8[arg1].field_0x8;
    if (temp_v0 >= 0) {
        QueueSpriteInstanceSlots(&arg0->field_0x4[temp_v0], arg1, arg2);
    }
}

}
