#include "m2c_macros.h"

void *PvAllocSlotheapImpl(M2C_UNK *);               /* extern */
extern M2C_UNK B_004521E8;

void *CRef_ConstructSmp(void *arg0, void *arg1) {
    void *temp_v0;

    M2C_FIELD(arg0, s32 *, 0) = 0x1E;
    temp_v0 = PvAllocSlotheapImpl(&B_004521E8);
    M2C_FIELD(temp_v0, s32 *, 0xC) = 0;
    M2C_FIELD(arg0, void **, 4) = temp_v0;
    M2C_FIELD(temp_v0, s32 *, 0xC) = (s32) (M2C_FIELD(temp_v0, s32 *, 0xC) + 1);
    M2C_ERROR(/* unknown instruction: ldl $v1, 0x7($s1) */);
    M2C_ERROR(/* unknown instruction: ldr $v1, ($s1) */);
    M2C_ERROR(/* unknown instruction: sdl $v1, 0x7($a0) */);
    M2C_ERROR(/* unknown instruction: sdr $v1, ($a0) */);
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 8) = (s32) M2C_FIELD(arg1, s32 *, 8);
    return arg0;
}
