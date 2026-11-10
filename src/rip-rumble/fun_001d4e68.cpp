#include "types.h"
#define NULL 0
extern "C" {
struct SoObject {
    char pad0[0x40];
    s32 field_0x40;
    char pad44[0x150 - 0x44];
    s32 field_0x150;
    char pad154[0x15C - 0x154];
    s32 field_0x15C;
};
s32 InitSo();
void func_001D4E68(SoObject *object) {
    s32 flags;
    InitSo();
    flags = object->field_0x40;
    object->field_0x15C = 0x1E;
    object->field_0x150 = -1;
    if ((flags ^ 1) & 1) {
        *(s32 *)flags = (s32) (*(s32 *)flags | 2);
        return;
    }
    object->field_0x40 = (s32) (flags | 2);
}
}
