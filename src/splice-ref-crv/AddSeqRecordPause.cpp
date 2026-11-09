#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
extern "C" {
s8 *PjsgeAllocJsg(s32, s32, s32);

void AddSeqRecordPause(s32 arg0, s32 arg1, s32 arg2, f32 fparg0) {
    s8 *temp_v0;
    f32 savedValue;

    savedValue = fparg0;
    temp_v0 = PjsgeAllocJsg(arg0, 0x23, 0);
    M2C_FIELD(temp_v0, f32 *, 0x10) = savedValue;
    M2C_FIELD(temp_v0, s32 *, 0x14) = arg1;
    M2C_FIELD(temp_v0, s32 *, 0x18) = arg2;
}

}
