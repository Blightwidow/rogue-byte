#include "types.h"

extern "C" {
struct RefCell { s32 tag; s32 value; s32 field_0x8; s32 field_0xC; };

void CRef_ConstructBasic(s32, s32);
s32 NewEmitter(s32);
void SetEmitterUnpositioned(s32, s32);

s32 RefOpStartSound(s32 arg0, s32 arg1, RefCell *arg2) {
    s32 argument;
    s32 emitter;

    argument = arg2->field_0xC;
    emitter = NewEmitter(arg2->value);
    SetEmitterUnpositioned(emitter, argument);
    CRef_ConstructBasic(arg0, emitter);
    return arg0;
}
}
