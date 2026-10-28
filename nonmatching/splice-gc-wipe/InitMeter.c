#include "m2c_macros.h"

s32 FIsBasicDerivedFrom(void *, M2C_UNK);           /* extern */
s32 GetJtPower(void *);                             /* extern */
void *PloFindSwObject_thunk(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
void *PpoSwFocusBase(M2C_UNK *);                    /* extern */
M2C_UNK SeekBlotLabel(void *, M2C_UNK, f32);        /* extern */
M2C_UNK func_00213B00(void *, M2C_UNK);             /* extern */
extern M2C_UNK B_003DD490;

void InitMeter(void *arg0) {
    f32 temp_f0;
    f32 temp_f0_2;
    s32 var_a0;
    s32 var_a1;
    s32 var_a2;
    s32 var_v0;
    s32 var_v1;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a2;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;

    temp_v0 = PloFindSwObject_thunk(&B_003DD490, 0x405, 0x36B, 0);
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
    M2C_FIELD(arg0, void **, 0x34) = NULL;
    M2C_FIELD(arg0, void **, 0x38) = temp_v0;
    temp_v0_2 = PpoSwFocusBase(&B_003DD490);
    if ((temp_v0_2 != NULL) && (FIsBasicDerivedFrom(temp_v0_2, 0x34) != 0)) {
        M2C_FIELD(arg0, void **, 0x34) = temp_v0_2;
    }
    temp_a0 = M2C_FIELD(arg0, void **, 0x34);
    if (temp_a0 != NULL) {
        temp_f0 = (f32) *M2C_FIELD(temp_a0, s32 **, 0xE00) / (f32) M2C_FIELD(temp_a0, s32 *, 0xDFC);
        M2C_FIELD(arg0, f32 *, 0x20) = temp_f0;
        M2C_FIELD(arg0, f32 *, 0x24) = temp_f0;
        temp_a0_2 = M2C_FIELD(arg0, void **, 0x34);
        temp_f0_2 = (f32) GetJtPower(temp_a0) / (f32) M2C_FIELD(temp_a0_2, s32 *, 0x1300);
        M2C_FIELD(arg0, f32 *, 0x28) = temp_f0_2;
        M2C_FIELD(arg0, f32 *, 0x2C) = temp_f0_2;
        var_v0 = 0x347;
        if (FIsBasicDerivedFrom(temp_a0_2, 0x37) != 0) {
            var_v1 = 0x348;
            var_a0 = 0x349;
            var_a1 = 0x34A;
            var_a2 = 0x34B;
        } else {
            var_v0 = 0x342;
            if (FIsBasicDerivedFrom(M2C_FIELD(arg0, void **, 0x34), 0x36) != 0) {
                var_v1 = 0x343;
                var_a0 = 0x344;
                var_a1 = 0x345;
                var_a2 = 0x346;
            } else {
                var_v0 = 0x33D;
                var_v1 = 0x33E;
                var_a0 = 0x33F;
                var_a1 = 0x340;
                var_a2 = 0x341;
            }
        }
        M2C_FIELD(arg0, s32 *, 0x3C) = var_v0;
        M2C_FIELD(arg0, s32 *, 0x40) = var_v1;
        M2C_FIELD(arg0, s32 *, 0x44) = var_a0;
        M2C_FIELD(arg0, s32 *, 0x48) = var_a1;
        M2C_FIELD(arg0, s32 *, 0x4C) = var_a2;
        temp_a2 = M2C_FIELD(arg0, void **, 0x38);
        if (temp_a2 != NULL) {
            temp_v0_3 = M2C_FIELD(temp_a2, void **, 0xC);
            M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *, s32, void *), 0x18C)(temp_a2 + M2C_FIELD(temp_v0_3, s16 *, 0x188), M2C_FIELD(arg0, s32 *, 0x3C), temp_a2);
            func_00213B00(M2C_FIELD(arg0, void **, 0x38), 0x34F);
            func_00213B00(M2C_FIELD(arg0, void **, 0x38), 0x350);
            SeekBlotLabel(M2C_FIELD(arg0, void **, 0x38), 0x34F, 1.0f - M2C_FIELD(arg0, f32 *, 0x20));
            SeekBlotLabel(M2C_FIELD(arg0, void **, 0x38), 0x350, 1.0f - M2C_FIELD(arg0, f32 *, 0x28));
        }
    } else {
        M2C_FIELD(arg0, f32 *, 0x28) = 0.0f;
        M2C_FIELD(arg0, f32 *, 0x24) = 0.0f;
        M2C_FIELD(arg0, f32 *, 0x20) = 0.0f;
        M2C_FIELD(arg0, f32 *, 0x2C) = 0.0f;
    }
}
