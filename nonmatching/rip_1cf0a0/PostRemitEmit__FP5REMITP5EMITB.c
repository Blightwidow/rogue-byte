#include "m2c_macros.h"

s32 PloFindSwObject_thunk(M2C_UNK *, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_001CE9B8();                            /* extern */
extern M2C_UNK B_003DD490;

void PostRemitEmit__FP5REMITP5EMITB(void *arg0, void *arg1) {
    func_001CE9B8();
    M2C_FIELD(arg0, s32 *, 0xF0) = PloFindSwObject_thunk(&B_003DD490, 4, M2C_FIELD(arg1, s32 *, 0xF0), *M2C_FIELD(arg1, s32 **, 8));
    M2C_FIELD(arg0, f32 *, 0xF4) = (f32) M2C_FIELD(arg1, f32 *, 0xF4);
}
