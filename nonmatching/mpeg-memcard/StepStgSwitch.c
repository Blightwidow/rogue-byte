#include "m2c_macros.h"

void *PloFindSwObject_thunk(M2C_UNK *, M2C_UNK, s32, void *); /* extern */
M2C_UNK func_001F6978(void *, s32, void *);         /* extern */
M2C_UNK func_001F69F8(void *, s32, void *);         /* extern */
M2C_UNK func_001F6AC8(void *, s32, void *);         /* extern */
M2C_UNK func_001F6B48(void *, s32, void *);         /* extern */
extern M2C_UNK B_003DD490;

void StepStgSwitch(void *arg0, s32 arg1) {
    M2C_UNK (*var_v1_2)(void *);
    M2C_UNK (*var_v1_3)(void *);
    s16 var_a0_2;
    s16 var_a0_3;
    s32 *temp_v1;
    s32 temp_v0;
    s32 temp_v0_4;
    s32 var_a0;
    s32 var_a1;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_s4;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v1;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_s3;
    void *temp_s3_2;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_5;
    void *temp_v0_6;
    void *var_a2;
    void *var_a2_2;

    var_s4 = M2C_FIELD(arg0, s32 *, 0x15C);
    switch (arg1) {                                 /* switch 1; irregular */
    case -1:                                        /* switch 1 */
        break;
    case 1545:                                      /* switch 1 */
        var_s4 = 0;
        break;
    case 1546:                                      /* switch 1 */
        var_s4 = M2C_FIELD(arg0, s32 *, 0x160);
        break;
    default:                                        /* switch 1 */
        temp_v0 = M2C_FIELD(arg0, s32 *, 0x160);
        var_a0 = 0;
        if (temp_v0 > 0) {
            temp_v1 = M2C_FIELD(arg0, s32 **, 0x164);
            if (*temp_v1 == arg1) {
                var_s4 = 0;
            } else {
loop_8:
                var_a0 += 1;
                if (var_a0 < temp_v0) {
                    if (*((var_a0 * 0x10) + temp_v1) == arg1) {
                        var_s4 = var_a0;
                    } else {
                        goto loop_8;
                    }
                }
            }
        }
        break;
    }
    var_a1 = M2C_FIELD(arg0, s32 *, 0x15C);
    if (M2C_FIELD(arg0, s32 *, 0x15C) != var_s4) {
        if (M2C_FIELD(arg0, s32 *, 0x15C) < var_s4) {
            var_v1 = var_a1 + 1;
            do {
                M2C_FIELD(arg0, s32 *, 0x15C) = var_v1;
                temp_s3 = M2C_FIELD(arg0, s32 **, 0x164) + (var_a1 * 0x10);
                var_s2 = 0;
                if (M2C_FIELD(temp_s3, s32 *, 8) > 0) {
                    do {
                        temp_s0 = M2C_FIELD(temp_s3, s32 *, 0xC) + (var_s2 * 8);
                        var_a2 = NULL;
                        if ((0xC3 >> M2C_FIELD(temp_s0, u32 *, 0)) & 1) {
                            var_a2 = PloFindSwObject_thunk(&B_003DD490, 1, M2C_FIELD(temp_s0, s32 *, 4), arg0);
                            if (var_a2 != NULL) {
                                goto block_18;
                            }
                        } else {
block_18:
                            switch (M2C_FIELD(temp_s0, u32 *, 0)) { /* switch 2 */
                            case 0:                 /* switch 2 */
                                temp_v0_2 = M2C_FIELD(var_a2, void **, 0xC);
                                var_a0_2 = M2C_FIELD(temp_v0_2, s16 *, 0x40);
                                var_v1_2 = M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *), 0x44);
block_22:
                                var_v1_2(var_a2 + var_a0_2);
                                break;
                            case 1:                 /* switch 2 */
                                temp_v0_3 = M2C_FIELD(var_a2, void **, 0xC);
                                var_a0_2 = M2C_FIELD(temp_v0_3, s16 *, 0x48);
                                var_v1_2 = M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *), 0x4C);
                                goto block_22;
                            case 2:                 /* switch 2 */
                                func_001F6978(arg0, M2C_FIELD(temp_s0, s32 *, 4), var_a2);
                                break;
                            case 3:                 /* switch 2 */
                                func_001F69F8(arg0, M2C_FIELD(temp_s0, s32 *, 4), var_a2);
                                break;
                            case 4:                 /* switch 2 */
                                func_001F6AC8(arg0, M2C_FIELD(temp_s0, s32 *, 4), var_a2);
                                break;
                            case 5:                 /* switch 2 */
                                func_001F6B48(arg0, M2C_FIELD(temp_s0, s32 *, 4), var_a2);
                                break;
                            }
                        }
                        var_s2 += 1;
                    } while (var_s2 < M2C_FIELD(temp_s3, s32 *, 8));
                }
                var_a1 = M2C_FIELD(arg0, s32 *, 0x15C);
                var_v1 = var_a1 + 1;
            } while (var_a1 < var_s4);
        } else if (var_s4 < M2C_FIELD(arg0, s32 *, 0x15C)) {
            var_v0 = M2C_FIELD(arg0, s32 *, 0x15C) - 1;
            do {
                M2C_FIELD(arg0, s32 *, 0x15C) = var_v0;
                temp_s3_2 = M2C_FIELD(arg0, s32 **, 0x164) + (var_v0 * 0x10);
                var_s2_2 = M2C_FIELD(temp_s3_2, s32 *, 8);
loop_45:
                var_v0_2 = var_s2_2;
loop_46:
                var_s2_2 -= 1;
                if (var_v0_2 > 0) {
                    temp_s0_2 = M2C_FIELD(temp_s3_2, s32 *, 0xC) + (var_s2_2 * 8);
                    var_a2_2 = NULL;
                    if ((0xC3 >> M2C_FIELD(temp_s0_2, u32 *, 0)) & 1) {
                        var_a2_2 = PloFindSwObject_thunk(&B_003DD490, 1, M2C_FIELD(temp_s0_2, s32 *, 4), arg0);
                        var_v0_2 = var_s2_2;
                        if (var_a2_2 != NULL) {
                            goto block_36;
                        }
                    } else {
block_36:
                        switch (M2C_FIELD(temp_s0_2, u32 *, 0)) { /* switch 3 */
                        case 0:                     /* switch 3 */
                            temp_v0_5 = M2C_FIELD(var_a2_2, void **, 0xC);
                            var_a0_3 = M2C_FIELD(temp_v0_5, s16 *, 0x48);
                            var_v1_3 = M2C_FIELD(temp_v0_5, M2C_UNK (**)(void *), 0x4C);
block_40:
                            var_v1_3(var_a2_2 + var_a0_3);
                            break;
                        case 1:                     /* switch 3 */
                            temp_v0_6 = M2C_FIELD(var_a2_2, void **, 0xC);
                            var_a0_3 = M2C_FIELD(temp_v0_6, s16 *, 0x40);
                            var_v1_3 = M2C_FIELD(temp_v0_6, M2C_UNK (**)(void *), 0x44);
                            goto block_40;
                        case 2:                     /* switch 3 */
                            func_001F69F8(arg0, M2C_FIELD(temp_s0_2, s32 *, 4), var_a2_2);
                            break;
                        case 3:                     /* switch 3 */
                            func_001F6978(arg0, M2C_FIELD(temp_s0_2, s32 *, 4), var_a2_2);
                            break;
                        case 4:                     /* switch 3 */
                            func_001F6B48(arg0, M2C_FIELD(temp_s0_2, s32 *, 4), var_a2_2);
                            break;
                        case 5:                     /* switch 3 */
                            func_001F6AC8(arg0, M2C_FIELD(temp_s0_2, s32 *, 4), var_a2_2);
                            break;
                        }
                        goto loop_45;
                    }
                    goto loop_46;
                }
                temp_v0_4 = M2C_FIELD(arg0, s32 *, 0x15C);
                var_v0 = temp_v0_4 - 1;
            } while (var_s4 < temp_v0_4);
        }
        M2C_FIELD(arg0, s32 *, 0x158) = 0;
    }
}
