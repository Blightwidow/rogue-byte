#include "m2c_macros.h"

M2C_UNK CSolveQuadratic__FfffPf(M2C_UNK *, f32);    /* extern */
s128 PosLoWorld(void *);                            /* extern */
extern M2C_UNK D_FLT_002BF8B0;
extern M2C_UNK D_FLT_002BF8C0;

s128 GetJmpLaunchVelocity(void **arg0, s32 arg1) {
    f32 saved_reg_f20;
    M2C_UNK unksp18;
    s128 sp10;
    M2C_UNK sp20;
    f32 temp_f21;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f27;
    f32 temp_f3;
    void *temp_a1;
    void *temp_a1_2;
    void *temp_v1;
    void *temp_v1_2;

    temp_a1 = *arg0;
    temp_v1 = M2C_FIELD(temp_a1, void **, 0xC);
    sp10 = M2C_FIELD(temp_v1, s128 (**)(void *, void *, s128), 0x10C)(temp_a1 + M2C_FIELD(temp_v1, s16 *, 0x108), temp_a1, PosLoWorld(*arg0));
    temp_f22 = M2C_FIELD(M2C_FIELD(*arg0, void **, 0xE8), f32 *, 0x88);
    switch (arg1) {                                 /* switch 1 */
        break;
    case 1:                                         /* switch 1 */
    case 7:                                         /* switch 1 */
    case 9:                                         /* switch 1 */
    case 13:                                        /* switch 1 */
    case 14:                                        /* switch 1 */
    case 15:                                        /* switch 1 */
        switch (arg1) {                             /* switch 2; irregular */
        case 9:                                     /* switch 2 */
            break;
        case 14:                                    /* switch 2 */
            break;
        case 13:                                    /* switch 2 */
            break;
        }
        M2C_ERROR(/* unknown instruction: max.s $f2, $f2, $f1 */);
        M2C_ERROR(/* unknown instruction: c1 0x20004 */);
        break;
    case 4:                                         /* switch 1 */
        temp_f3 = M2C_FIELD(&D_FLT_002BF8B0, f32 *, 0) + (unksp18 * (M2C_FIELD(&D_FLT_002BF8B0, f32 *, 4) + (unksp18 * M2C_FIELD(&D_FLT_002BF8B0, f32 *, 8))));
        if (temp_f3 < M2C_FIELD(&D_FLT_002BF8C0, f32 *, 0)) {

        } else if (M2C_FIELD(&D_FLT_002BF8C0, f32 *, 4) < temp_f3) {

        }
        break;
    case 6:                                         /* switch 1 */
        M2C_ERROR(/* unknown instruction: c1 0x504 */);
        temp_a1_2 = *arg0;
        temp_f27 = -saved_reg_f20;
        temp_v1_2 = M2C_FIELD(temp_a1_2, void **, 0xC);
        temp_f24 = temp_f27 / temp_f22;
        M2C_FIELD(temp_v1_2, M2C_UNK (**)(void *, void *), 0x10C)(temp_a1_2 + M2C_FIELD(temp_v1_2, s16 *, 0x108), temp_a1_2);
        M2C_ERROR(/* unknown instruction: pextuw $v1, $zero, $v0 */);
        temp_f21 = M2C_ERROR(/* unknown instruction: min.s $f21, $f20, $f21 */);
        M2C_ERROR(/* unknown instruction: c1 0x10344 */);
        CSolveQuadratic__FfffPf(&sp20, temp_f22 * 0.5f);
        if (temp_f21 > 0.0f) {
            M2C_ERROR(/* unknown instruction: c1 0x44 */);
        } else if (temp_f21 < temp_f27) {

        }
        break;
    default:                                        /* switch 1 */
        break;
    }
    unksp18 = M2C_ERROR(/* unknown instruction: max.s $f0, $f0, $f12 */);
    return sp10;
}
