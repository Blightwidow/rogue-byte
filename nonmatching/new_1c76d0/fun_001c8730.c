#include "m2c_macros.h"

M2C_UNK DecrementSwBinocCount(M2C_UNK *);           /* extern */
M2C_UNK DecrementSwShowCount(M2C_UNK *);            /* extern */
M2C_UNK IncrementSwBinocCount(M2C_UNK *);           /* extern */
M2C_UNK IncrementSwShowCount(M2C_UNK *);            /* extern */
M2C_UNK SetGadgetAcquired(s32, M2C_UNK);            /* extern */
M2C_UNK StartJsg(s32, void *);                      /* extern */
s32 StartStream(M2C_UNK *, s32, M2C_UNK);           /* extern */
M2C_UNK StopJsg(s32);                               /* extern */
M2C_UNK StopStream(M2C_UNK *);                      /* extern */
M2C_UNK func_001C8918(void *, M2C_UNK);             /* extern */
extern M2C_UNK B_003DD040;
extern M2C_UNK B_003DD490;
extern f32 g_2dded0;

void func_001C8730(void *arg0, s32 arg1) {
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_v1;
    void *temp_a2;
    void *temp_v0;
    void *temp_v0_2;

    if (arg1 != M2C_FIELD(arg0, s32 *, 0x180)) {
        if (M2C_FIELD(arg0, s32 *, 0x1A4) != 0) {
            StopStream(&B_003DD040);
            M2C_FIELD(arg0, s32 *, 0x1A4) = 0;
        }
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x19C);
        if (temp_a0 != 0) {
            StopJsg(temp_a0);
        }
        temp_v1 = M2C_FIELD(arg0, s32 *, 0x180);
        switch (temp_v1) {                          /* switch 1; irregular */
        case 0:                                     /* switch 1 */
            if (M2C_FIELD(arg0, void **, 0x190) != NULL) {
                IncrementSwBinocCount(&B_003DD490);
            }
            break;
        case 3:                                     /* switch 1 */
            temp_a0_2 = M2C_FIELD(arg0, s32 *, 0x200);
            if (temp_a0_2 != -1) {
                SetGadgetAcquired(temp_a0_2, 1);
            }
            temp_a1 = M2C_FIELD(arg0, s32 *, 0x1FC);
            if (temp_a1 != 0) {
                M2C_FIELD(arg0, s32 *, 0x1A4) = StartStream(&B_003DD040, temp_a1, 1);
            }
            break;
        case 2:                                     /* switch 1 */
            func_001C8918(arg0, -1);
            DecrementSwShowCount(&B_003DD490);
            break;
        }
        M2C_FIELD(arg0, s32 *, 0x180) = arg1;
        M2C_FIELD(arg0, f32 *, 0x184) = (f32) g_2dded0;
        switch (arg1) {                             /* switch 2 */
        case 2:                                     /* switch 2 */
            M2C_FIELD(arg0, s32 *, 0x194) = 5;
            func_001C8918(arg0, 1);
            IncrementSwShowCount(&B_003DD490);
            temp_a1_2 = M2C_FIELD(arg0, s32 *, 0x1F4);
            if (temp_a1_2 != 0) {
                M2C_FIELD(arg0, s32 *, 0x1A4) = StartStream(&B_003DD040, temp_a1_2, 0);
            }
        default:                                    /* switch 2 */
block_29:
            temp_a0_3 = M2C_FIELD((arg0 + (M2C_FIELD(arg0, s32 *, 0x180) * 4)), s32 *, 0x20C);
            M2C_FIELD(arg0, s32 *, 0x19C) = temp_a0_3;
            if (temp_a0_3 != 0) {
                StartJsg(temp_a0_3, M2C_FIELD(arg0, void **, 0x190));
            }
            break;
        case 1:                                     /* switch 2 */
            temp_v0 = M2C_FIELD(arg0, void **, 0xC);
            M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK), 0x27C)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x278), 1);
            goto block_29;
        case 0:                                     /* switch 2 */
        case 5:                                     /* switch 2 */
            temp_a2 = M2C_FIELD(arg0, void **, 0x190);
            if (temp_a2 != NULL) {
                temp_v0_2 = M2C_FIELD(temp_a2, void **, 0xC);
                M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, M2C_UNK, void *), 0x27C)(temp_a2 + M2C_FIELD(temp_v0_2, s16 *, 0x278), 1, temp_a2);
                M2C_FIELD(arg0, void **, 0x190) = NULL;
                DecrementSwBinocCount(&B_003DD490);
            }
            goto block_29;
        }
    }
}
