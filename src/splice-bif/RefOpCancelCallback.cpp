#include "types.h"

extern "C" {
struct RefCell { s32 tag; s32 value; };

void CancelSwTimedCall(void *, s32);
void SetTag__4CRef4TAGK(s32, s32);
extern s32 B_003DD490;

s32 RefOpCancelCallback(s32 arg0, s32 arg1, RefCell *arg2) {
    CancelSwTimedCall(&B_003DD490, arg2->value);
    SetTag__4CRef4TAGK(arg0, 0x24);
    return arg0;
}
}
