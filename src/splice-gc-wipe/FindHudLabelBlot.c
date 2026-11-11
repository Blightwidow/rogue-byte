#include "types.h"

struct HudLabelBlot {
    char pad_0x0[0x28];
    void *field_0x28;
};

void *PloFindSwObject_thunk(s32 *, s32, s32, s32);
extern s32 B_003DD490;

void FindHudLabelBlot(struct HudLabelBlot *blot) {
    blot->field_0x28 = PloFindSwObject_thunk(&B_003DD490, 0x405, 0x371, 0);
}
