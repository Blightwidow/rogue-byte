#include "jt.h"
#include "types.h"
extern "C" {
s32 func_00143C78(JT *self) {
    if (self->field_0x204 != 0) return 0;
    s32 b = self->attachKind;
    if (b < 5) {
        if (b >= 3) return 4;
    }
    if (self->jmpState != -1) return 1;
    switch (self->zapState) {
    case -1: case 0: case 6: return 7;
    case 4: case 7: case 8: case 12: return 1;
    default: return 0;
    }
}
}
