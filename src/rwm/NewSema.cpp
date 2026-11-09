#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
extern "C" {
void CreateSema(s8 *);
void memset(s8 *, s32, s32);

void NewSema(s32 arg0, s32 arg1) {
    s8 sp[0x20] __attribute__((aligned(16)));
    memset(sp, 0, 0x18);
    M2C_FIELD(sp, s32 *, 8) = arg0;
    M2C_FIELD(sp, s32 *, 4) = arg1;
    CreateSema(sp);
}

}
