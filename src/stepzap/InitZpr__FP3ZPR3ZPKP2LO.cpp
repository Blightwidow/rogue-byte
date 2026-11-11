#include "types.h"
extern "C" {
struct ZPR {
    s32 field_0x0;
    s32 field_0x4;
    s32 field_0x8;
};

void *memset(void *, s32, s32);

void InitZpr__FP3ZPR3ZPKP2LO(ZPR *zpr, s32 arg1, s32 arg2) {
    memset(zpr, 0, 0x630);
    zpr->field_0x4 = arg1;
    zpr->field_0x0 = arg1;
    zpr->field_0x8 = arg2;
}

}
