#include "m2c_macros.h"

void CroutDecomp__FiPfT1(s32 arg0, f32 *arg1, f32 *arg2) {
    f32 *temp_v1;
    f32 *var_a0;
    f32 *var_v0;
    f32 *var_v0_2;
    f32 *var_v0_3;
    f32 *var_v0_4;
    f32 *var_v0_5;
    f32 *var_v1;
    f32 *var_v1_2;
    f32 *var_v1_3;
    f32 *var_v1_5;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 var_f3;
    f32 var_f3_2;
    f32 var_f3_3;
    s32 *var_v1_4;
    s32 temp_t4;
    s32 temp_t6;
    s32 temp_t7;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v0_7;
    s32 temp_v1_2;
    s32 var_a3;
    s32 var_a3_2;
    s32 var_a3_3;
    s32 var_a3_4;
    s32 var_t0;
    s32 var_t0_2;
    s32 var_t0_3;
    s32 var_t1;
    s32 var_t1_2;
    s32 var_t1_3;
    void *temp_v1_3;

    if (arg0 != 0) {
        temp_t7 = arg0 - 1;
        if (arg0 > 0) {
            var_v1 = arg2;
            var_v0 = arg1;
            var_t0 = arg0;
            do {
                temp_f0 = *var_v0;
                var_t0 -= 1;
                var_v0 += 4;
                *var_v1 = temp_f0;
                var_v1 += 4;
            } while (var_t0 != 0);
        }
        var_t1 = 1;
        if (fabsf(*arg2) < 1e-8f) {
            var_v0_2 = arg2;
            if (arg0 > 0) {
                var_t1_2 = arg0;
                do {
                    *var_v0_2 = 0.0f;
                    var_t1_2 -= 1;
                    var_v0_2 += arg0 * 4;
                } while (var_t1_2 != 0);
                goto block_12;
            }
        } else {
            temp_v0 = arg0 * 4;
            if (arg0 > 1) {
                var_t1_3 = arg0 - 1;
                var_v1_2 = temp_v0 + arg2;
                var_v0_3 = temp_v0 + arg1;
                do {
                    temp_f0_2 = *var_v0_3;
                    var_t1_3 -= 1;
                    var_v0_3 += temp_v0;
                    *var_v1_2 = temp_f0_2 / *arg2;
                    var_v1_2 += temp_v0;
                } while (var_t1_3 != 0);
            }
block_12:
            var_t1 = 1;
        }
        var_t0_2 = 1;
        if (temp_t7 > 1) {
            do {
                temp_t6 = var_t1 + 1;
                if (var_t1 < arg0) {
                    temp_t4 = var_t1 * arg0;
                    do {
                        var_f3 = 0.0f;
                        if (var_t1 > 0) {
                            var_v1_3 = (temp_t4 * 4) + arg2;
                            var_v0_4 = (var_t0_2 * 4) + arg2;
                            var_a3 = var_t1;
                            do {
                                temp_f0_3 = *var_v0_4;
                                var_a3 -= 1;
                                temp_f1 = *var_v1_3;
                                var_v0_4 += arg0 * 4;
                                var_v1_3 += 4;
                                var_f3 += temp_f0_3 * temp_f1;
                            } while (var_a3 != 0);
                        }
                        temp_v0_2 = (temp_t4 + var_t0_2) * 4;
                        var_t0_2 += 1;
                        *(temp_v0_2 + arg2) = *(temp_v0_2 + arg1) - var_f3;
                    } while (var_t0_2 < arg0);
                }
                temp_v1 = (((var_t1 * arg0) + var_t1) * 4) + arg2;
                if (fabsf(*temp_v1) < 1e-8f) {
                    temp_v0_3 = var_t1 * 4;
                    if (var_t1 < arg0) {
                        var_a3_2 = arg0 - var_t1;
                        var_v1_4 = (temp_v0_3 * arg0) + (temp_v0_3 + arg2);
                        do {
                            *var_v1_4 = 0;
                            var_a3_2 -= 1;
                            var_v1_4 += arg0 * 4;
                        } while (var_a3_2 != 0);
                    }
                } else {
                    var_a3_3 = temp_t6;
                    if (var_a3_3 < arg0) {
                        do {
                            var_f3_2 = 0.0f;
                            if (var_t1 > 0) {
                                var_v1_5 = (var_t1 * 4) + arg2;
                                var_t0_3 = var_t1;
                                var_v0_5 = (var_a3_3 * arg0 * 4) + arg2;
                                do {
                                    temp_f0_4 = *var_v1_5;
                                    var_t0_3 -= 1;
                                    temp_f1_2 = *var_v0_5;
                                    var_v1_5 += arg0 * 4;
                                    var_v0_5 += 4;
                                    var_f3_2 += temp_f0_4 * temp_f1_2;
                                } while (var_t0_3 != 0);
                            }
                            temp_v1_2 = var_a3_3 * arg0;
                            var_a3_3 += 1;
                            temp_v0_4 = (temp_v1_2 + var_t1) * 4;
                            *(temp_v0_4 + arg2) = (*(temp_v0_4 + arg1) - var_f3_2) / *temp_v1;
                        } while (var_a3_3 < arg0);
                    }
                }
                var_t1 = temp_t6;
                var_t0_2 = var_t1;
            } while (var_t1 < temp_t7);
        }
        var_f3_3 = 0.0f;
        var_a3_4 = 0;
        if (temp_t7 > 0) {
            temp_v0_5 = arg0 * 4;
            var_a0 = temp_v0_5 + (arg2 - 4);
            do {
                temp_f1_3 = *var_a0;
                var_a0 += temp_v0_5;
                temp_v0_6 = ((temp_t7 * arg0) + var_a3_4) * 4;
                var_a3_4 += 1;
                var_f3_3 += temp_f1_3 * *(temp_v0_6 + arg2);
            } while (var_a3_4 < temp_t7);
        }
        temp_v0_7 = ((temp_t7 * arg0) + arg0) * 4;
        temp_v1_3 = temp_v0_7 + arg2;
        temp_f0_5 = M2C_FIELD((temp_v0_7 + arg1), f32 *, -4) - var_f3_3;
        M2C_FIELD(temp_v1_3, f32 *, -4) = temp_f0_5;
        if (fabsf(temp_f0_5) < 1e-8f) {
            M2C_FIELD(temp_v1_3, f32 *, -4) = 0.0f;
        }
    }
}
