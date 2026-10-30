#include "m2c_macros.h"
extern "C" {

void *PvAllocSwImpl__Fi(void *);          /* extern */

void func_0012FDE8(void *arg0, s32 arg1, f32 fparg0, f32 fparg1) {
    char sp[0x10];
    void *temp_v0;

    temp_v0 = PvAllocSwImpl__Fi(sp);
    M2C_FIELD(temp_v0, s32 *, 8) = arg1;
    M2C_FIELD(arg0, void **, 0xB0) = temp_v0;
    M2C_FIELD(temp_v0, f32 *, 4) = fparg1;
    M2C_FIELD(temp_v0, f32 *, 0) = fparg0;
}
}
