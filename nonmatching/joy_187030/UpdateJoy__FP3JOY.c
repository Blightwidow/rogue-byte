#include "m2c_macros.h"

s32 FReadJoy__FP3JOY(void *);                       /* extern */
M2C_UNK SetJoyJoys__FP3JOY4JOYS4JOYK(void *, s32, s32); /* extern */
M2C_UNK UpdateRumble__FP6RUMBLE(void *, s32);       /* extern */
s32 func_00243388(s32, s32);                        /* extern */
M2C_UNK memset(void *, M2C_UNK, M2C_UNK);           /* extern */
s32 scePadEnterPressMode(s32, s32);                 /* extern */
s32 scePadGetState(s32, s32);                       /* extern */
s32 scePadInfoAct(s32, s32, M2C_UNK, M2C_UNK);      /* extern */
s32 scePadInfoMode(s32, s32, M2C_UNK, M2C_UNK);     /* extern */
s32 scePadInfoPressMode(s32, s32);                  /* extern */
s32 scePadSetActAlign(s32, s32, void *);            /* extern */
s32 scePadSetMainMode(s32, s32, M2C_UNK, M2C_UNK);  /* extern */
extern f32 g_2ddf0c;

void UpdateJoy__FP3JOY(void *arg0) {
    char sp[0x400];
    M2C_UNK subroutine_arg0;
    s32 temp_a1;
    s32 temp_s1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v1;
    s32 var_a0;
    s32 var_a1;
    s32 var_s1;
    s32 var_s2;
    s32 var_s3;
    s8 *var_v0;
    s8 var_v1;

    var_s1 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x100C) != 0) {
        var_a0 = func_00243388(M2C_FIELD(arg0, s32 *, 0x1000), M2C_FIELD(arg0, s32 *, 0x1004));
        if ((var_a0 == 6) || (var_a0 == 2)) {
            var_s1 = 1;
        }
        temp_a1 = M2C_FIELD(arg0, s32 *, 0x1010);
        if (M2C_FIELD(arg0, s32 *, 0x100C) != 3) {
            if (temp_a1 != 0) {
                if ((g_2ddf0c - M2C_FIELD(arg0, f32 *, 0x1014)) >= 2.0f) {
                    var_a0 = 0;
                }
                goto block_8;
            }
        } else {
block_8:
            if ((temp_a1 != 0) && (var_a0 == 0)) {
                SetJoyJoys__FP3JOY4JOYS4JOYK(arg0, 1, 0);
            }
        }
        if (var_s1 != 0) {
            var_s2 = M2C_FIELD(arg0, s32 *, 0x100C);
            var_s3 = M2C_FIELD(arg0, s32 *, 0x1010);
            switch (var_s2) {                       /* switch 1; irregular */
            case 1:                                 /* switch 1 */
                if (var_s3 != var_s2) {
                    switch (var_s3) {               /* switch 2; irregular */
                    case 0:                         /* switch 2 */
                        temp_v0 = scePadInfoMode(M2C_FIELD(arg0, s32 *, 0x1000), M2C_FIELD(arg0, s32 *, 0x1004), 1, 0);
                        if ((temp_v0 != 0) && ((temp_v0_2 = scePadInfoMode(M2C_FIELD(arg0, s32 *, 0x1000), M2C_FIELD(arg0, s32 *, 0x1004), 2, 0), temp_s1 = (temp_v0_2 >= 1) ? temp_v0_2 : temp_v0, (temp_s1 == 4)) || (temp_s1 == 7))) {
                            var_s3 = 1;
                            var_s2 = (temp_v0_2 != 0) ? 1 : 3;
                        }
                        break;
                    case 2:                         /* switch 2 */
                        temp_v0_3 = scePadInfoAct(M2C_FIELD(arg0, s32 *, 0x1000), M2C_FIELD(arg0, s32 *, 0x1004), -1, 0);
                        if (temp_v0_3 != var_s3) {
                            var_s2 = 3;
                        } else if (scePadInfoAct(M2C_FIELD(arg0, s32 *, 0x1000), M2C_FIELD(arg0, s32 *, 0x1004), 0, 1) != var_s2) {
                            var_s2 = 3;
                        } else if (scePadInfoAct(M2C_FIELD(arg0, s32 *, 0x1000), M2C_FIELD(arg0, s32 *, 0x1004), 0, 2) != var_s3) {
                            var_s2 = 3;
                        } else if (scePadInfoAct(M2C_FIELD(arg0, s32 *, 0x1000), M2C_FIELD(arg0, s32 *, 0x1004), 0, 3) != 0) {
                            var_s2 = 3;
                        } else if (scePadInfoAct(M2C_FIELD(arg0, s32 *, 0x1000), M2C_FIELD(arg0, s32 *, 0x1004), 1, 1) != var_s2) {
                            var_s2 = 3;
                        } else if (scePadInfoAct(M2C_FIELD(arg0, s32 *, 0x1000), M2C_FIELD(arg0, s32 *, 0x1004), 1, 2) != var_s2) {
                            var_s2 = 3;
                        } else if (scePadInfoAct(M2C_FIELD(arg0, s32 *, 0x1000), M2C_FIELD(arg0, s32 *, 0x1004), 1, 3) != var_s2) {
                            var_s2 = 3;
                        } else {
                            memset(sp, 0xFF, 6);
                            var_v1 = 0;
                            var_v0 = &subroutine_arg0;
                            do {
                                *var_v0 = var_v1;
                                var_v1 += 1;
                                var_v0 = sp + var_v1;
                            } while (var_v1 < temp_v0_3);
                            var_s2 = ((scePadSetActAlign(M2C_FIELD(arg0, s32 *, 0x1000), M2C_FIELD(arg0, s32 *, 0x1004), sp) ^ 1) == 0) ? 2 : var_s2;
                        }
                        break;
                    case 3:                         /* switch 2 */
                        if (scePadInfoPressMode(M2C_FIELD(arg0, s32 *, 0x1000), M2C_FIELD(arg0, s32 *, 0x1004)) == var_s2) {
                            var_s2 = ((scePadEnterPressMode(M2C_FIELD(arg0, s32 *, 0x1000), M2C_FIELD(arg0, s32 *, 0x1004)) ^ 1) == 0) ? 2 : var_s2;
                        } else {
block_57:
                            var_s2 = 3;
                        }
                        break;
                    }
                } else {
                    var_s2 = ((scePadSetMainMode(M2C_FIELD(arg0, s32 *, 0x1000), M2C_FIELD(arg0, s32 *, 0x1004), 1, 3) ^ 1) != 0) ? var_s3 : 2;
block_82:
                }
            default:                                /* switch 1 */
block_83:
                var_a1 = var_s2;
                break;
            case 2:                                 /* switch 1 */
                temp_v0_4 = scePadGetState(M2C_FIELD(arg0, s32 *, 0x1000), M2C_FIELD(arg0, s32 *, 0x1004));
                if (temp_v0_4 != 1) {
                    if (temp_v0_4 < 2) {
                        var_s3 = 0;
                        if (temp_v0_4 != 0) {

                        } else {
                            temp_v1 = M2C_FIELD(arg0, s32 *, 0x1010);
                            if (temp_v1 != var_s2) {
                                if (temp_v1 < 3) {
                                    var_s3 = 0;
                                    if (temp_v1 != 1) {

                                    } else {
                                        var_s3 = 2;
                                        goto block_72;
                                    }
                                } else {
                                    var_s3 = 0;
                                    if (temp_v1 != 3) {

                                    } else {
                                        var_s3 = 4;
                                        goto block_57;
                                    }
                                }
                            } else {
                                var_s3 = 3;
                                goto block_72;
                            }
                        }
                    } else if (temp_v0_4 != var_s2) {
                        var_s3 = 0;
                    }
                } else {
block_72:
                    var_s2 = 1;
                }
                goto block_83;
            case 3:                                 /* switch 1 */
                if (FReadJoy__FP3JOY(arg0) == 0) {
                    var_s2 = 1;
                    var_s3 = 0;
                    goto block_82;
                }
                if (M2C_FIELD(arg0, s32 *, 0x10E8) != 0) {
                    var_a1 = var_s2;
                    if (M2C_FIELD(arg0, s32 *, 0x1010) >= 3) {
                        UpdateRumble__FP6RUMBLE(arg0 + 0x10CC, var_a1);
                        goto block_82;
                    }
                } else {
                    goto block_83;
                }
                break;
            }
            SetJoyJoys__FP3JOY4JOYS4JOYK(arg0, var_a1, var_s3);
        }
    }
}
