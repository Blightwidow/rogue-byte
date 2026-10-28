#include "m2c_macros.h"

M2C_UNK CarryThrow_Launch(void *);                  /* extern */
M2C_UNK HandleJtMessage();                          /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
M2C_UNK SetMurrayLiftState(void *, M2C_UNK);        /* extern */
M2C_UNK SetMurrayState(void *, M2C_UNK);            /* extern */
M2C_UNK SpawnSwHitFx(M2C_UNK *, M2C_UNK, M2C_UNK, void *); /* extern */
M2C_UNK ThrowMurrayObject(void *);                  /* extern */
M2C_UNK func_001B6DA8(void *, M2C_UNK);             /* extern */
M2C_UNK func_001B7AE8(void *);                      /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK D_FLT_002C0990;

void HandleMurrayMessage(void *arg0, s32 arg1, void *arg2) {
    f32 temp_f0;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;

    HandleJtMessage();
    switch (arg1) {                                 /* switch 1; irregular */
    case 9:                                         /* switch 1 */
        temp_v1 = M2C_FIELD(arg2, s32 *, 0);
        if ((temp_v1 == M2C_FIELD(arg0, s32 *, 0x1030)) || (temp_v1 == M2C_FIELD(arg0, s32 *, 0x190C))) {
            temp_v1_2 = M2C_FIELD(arg2, s32 *, 8);
            switch (temp_v1_2) {                    /* switch 2; irregular */
            case 0x1A4:                             /* switch 2 */
                func_001B6DA8(arg0, 1);
                break;
            case 0x1A5:                             /* switch 2 */
                PosLoWorld(arg0);
                SpawnSwHitFx(&B_003DD490, 0, M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */), arg0);
                break;
            case 0x1EB:                             /* switch 2 */
                temp_v1_3 = M2C_FIELD(arg0, s32 *, 0x13D0);
                switch (temp_v1_3) {                /* switch 3; irregular */
                case 7:                             /* switch 3 */
                    ThrowMurrayObject(arg0);
                    break;
                case 8:                             /* switch 3 */
                    func_001B7AE8(arg0);
                    break;
                case 15:                            /* switch 3 */
                    CarryThrow_Launch(arg0 + 0x1910);
                    break;
                }
                break;
            case 0x1C6:                             /* switch 2 */
                M2C_FIELD(arg0, s32 *, 0x1448) = 1;
                break;
            case 0x1C8:                             /* switch 2 */
                if (M2C_FIELD(arg0, s32 *, 0x1450) == 0) {
                    PosLoWorld(arg0);
                    SpawnSwHitFx(&B_003DD490, 0, M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */), arg0);
                    SetMurrayLiftState(arg0, 1);
                }
                break;
            case 0x1C7:                             /* switch 2 */
                if (M2C_FIELD(arg0, s32 *, 0x1450) == 1) {
                    SetMurrayLiftState(arg0, 2);
                }
                break;
            case 0x240:                             /* switch 2 */
                M2C_FIELD(arg0, s32 *, 0x1818) = 1;
                break;
            case 0x241:                             /* switch 2 */
                M2C_FIELD(arg0, s32 *, 0x181C) = 1;
                break;
            case 0x242:                             /* switch 2 */
                M2C_FIELD(arg0, s32 *, 0x1820) = 1;
                break;
            }
        } else {
            return;
        }
        break;
    case 10:                                        /* switch 1 */
        if ((M2C_FIELD(arg2, s32 *, 0) == M2C_FIELD(arg0, s32 *, 0x1034)) && (M2C_FIELD(arg0, s32 *, 0x13D0) == 6)) {
            temp_v1_4 = M2C_FIELD(arg2, s32 *, 8);
            if (temp_v1_4 != M2C_FIELD(arg2, s32 *, 4)) {
                switch (temp_v1_4) {                /* switch 4; irregular */
                case 0x1D0:                         /* switch 4 */
                    /* fallthrough */
                case 0x1CA:                         /* switch 4 */
                    SetMurrayState(arg0, 0);
                    break;
                default:                            /* switch 4 */
                    temp_f0 = *((M2C_FIELD(arg0, s32 *, 0x1534) * 4) + &D_FLT_002C0990);
                    M2C_FIELD(arg0, f32 *, 0x1528) = temp_f0;
                    M2C_FIELD(arg0, f32 *, 0x1524) = temp_f0;
                    M2C_FIELD(arg0, f32 *, 0x152C) = temp_f0;
                    break;
                }
            }
        }
        break;
    }
}
