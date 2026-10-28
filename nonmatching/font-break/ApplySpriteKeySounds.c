#include "m2c_macros.h"

void *NewEmitter(s32);                              /* extern */
M2C_UNK SetEmitterUnpositioned(void *, M2C_UNK);    /* extern */
M2C_UNK StartStream(M2C_UNK *, s32, M2C_UNK);       /* extern */
M2C_UNK StopAmb(s32, s32, M2C_UNK);                 /* extern */
M2C_UNK StopStream(M2C_UNK *);                      /* extern */
M2C_UNK VirtualRefPtr_Assign(void *, void *);       /* extern */
extern M2C_UNK B_003DD040;

void ApplySpriteKeySounds(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_a0_2;
    s32 temp_a1;
    s32 temp_v1;
    s32 var_s1;
    void *temp_a0;
    void *temp_s0;
    void *temp_s2;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v1_2;

    var_s1 = 0;
    temp_s2 = M2C_FIELD(arg0, s32 *, 4) + (arg1 << 5);
    if (M2C_FIELD(temp_s2, u8 *, 0x18) != 0) {
        do {
            temp_a0 = (var_s1 * 8) + M2C_FIELD(temp_s2, s32 *, 0x1C);
            temp_v1 = M2C_FIELD(temp_a0, s32 *, 0);
            switch (temp_v1) {                      /* irregular */
            case 0:
                temp_v0 = NewEmitter(M2C_FIELD(temp_a0, s32 *, 4));
                SetEmitterUnpositioned(temp_v0, 0);
                temp_v1_2 = M2C_FIELD(temp_v0, void **, 0xC);
                if (M2C_FIELD(temp_v1_2, s32 (**)(void *), 0x44)(temp_v0 + M2C_FIELD(temp_v1_2, s16 *, 0x40)) == 2) {
                    VirtualRefPtr_Assign((arg2 * 0x18) + M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 8) + 0x14, temp_v0);
                }
                break;
            case 1:
                temp_a1 = arg2 * 0x18;
                temp_v0_2 = temp_a1 + M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 8);
                if (M2C_FIELD(temp_v0_2, s32 *, 0x14) != 0) {
                    temp_s0 = temp_v0_2 + 0x14;
                    if (temp_s0 != NULL) {
                        temp_a0_2 = M2C_FIELD(temp_v0_2, s32 *, 0x14);
                        if (temp_a0_2 != 0) {
                            StopAmb(temp_a0_2, temp_a1, 0);
                            VirtualRefPtr_Assign(temp_s0, NULL);
                        }
                    }
                }
                break;
            case 2:
                StartStream(&B_003DD040, M2C_FIELD(temp_a0, s32 *, 4), 0);
                break;
            case 3:
                StopStream(&B_003DD040);
                break;
            }
            var_s1 += 1;
        } while (var_s1 < (s32) M2C_FIELD(temp_s2, u8 *, 0x18));
    }
}
