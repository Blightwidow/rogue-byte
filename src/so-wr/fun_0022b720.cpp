#include "types.h"
#include "lo.h"

struct ALO : LO {
    f32 field_0x50;
    char pad54[8];
    s32 field_0x5C;
    char pad60[0x6E0 - 0x60];
    s32 field_0x6E0;
    char pad6E4[0x8F0 - 0x6E4];
    char field_0x8F0[0xA0];
};

extern "C" {
void InitLo(LO *);
void InitSl(char *, s32);
void func_001A6CA8(ALO *, s32);
void func_0022B720(ALO *alo) {
    s32 flags;
    InitLo(alo);
    alo->field_0x5C = -1;
    alo->field_0x6E0 = -1;
    alo->field_0x50 = -1.0f;
    InitSl(alo->field_0x8F0, 0xA0);
    func_001A6CA8(alo, 1);
    flags = (s32)alo->grfSw;
    if ((flags ^ 1) & 1) {
        *(s32 *)flags = *(s32 *)flags | 2;
        return;
    }
    alo->grfSw = (u32)(flags | 2);
}
}
