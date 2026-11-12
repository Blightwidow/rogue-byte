#include "types.h"
extern "C" {
typedef struct {
    char pad0[0x18];
    s64 f18;
    s64 f20;
    s32 f28;
    s32 f2C;
    s32 f30;
    s32 f34;
    s32 f38;
    s32 f3C;
    s32 f40;
    s32 f44;
    s32 f48;
    s32 f4C;
    s32 f50;
    s32 f54;
    s32 f58;
    s32 f5C;
    s32 f60;
} FRAME;
typedef struct {
    char pad0[0xB4];
    s32 fB4;
    s32 fB8;
    char padBC[0x40];
    s32 fFC;
    char pad100[0x4C];
    s32 f14C;
    char pad150[0x8];
    s32 f158;
    s32 f15C;
    s32 f160;
    char pad164[0x20];
    s32 f184;
    s32 f188;
    char pad18C[0x8];
    s32 f194;
    s32 f198;
    s32 f19C;
    s32 f1A0;
    s32 f1A4;
    s32 f1A8;
    s32 f1AC;
    s32 f1B0;
    s32 f1B4;
    s32 f1B8;
    char pad1BC[0xC];
    FRAME *f1C8;
    FRAME *f1CC;
    FRAME *f1D0;
    FRAME *f1D4;
    FRAME *f1D8;
    FRAME *f1DC;
    FRAME *f1E0;
    FRAME *f1E4;
    FRAME *f1E8;
    FRAME *f1EC;
    FRAME *f1F0;
    FRAME *f1F4;
    char pad1F8[0x640];
    s64 f838;
    s64 f840;
} SLOTS;

int func_0024AE90(SLOTS *obj, int arg1) {
    s32 temp_a0;
    s32 temp_t1;
    s32 temp_t2;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_t5;
    FRAME *temp_a0_2;
    FRAME *temp_a0_3;
    FRAME *temp_a2;
    FRAME *temp_v1;
    FRAME *temp_v1_2;
    FRAME *var_t0;
    FRAME *var_v0;
    FRAME *var_v1;
    temp_t1 = obj->f184;
    temp_t2 = obj->f160;
    int limit = (temp_t1 == 3) ? 2 : 4;
    var_t0 = 0;
    var_t5 = 0;
    if (temp_t2 == 3) {
        obj->f1D0 = obj->f1D4;
        obj->f1E0 = obj->f1E4;
        obj->f1F0 = obj->f1F4;
        if ((obj->fB4 + obj->fB8) >= (limit)) {
            obj->fFC = 0;
            obj->f1B8 = 0;
            obj->f1B4 = 0;
        }
        if (((obj->fFC != 0) || (obj->f1B8 != 0)) && (obj->f1B4 == 0)) {
            obj->f1C8->f28 = 0;
            obj->f1D8->f28 = 0;
            obj->f1E8->f28 = 0;
        }
        obj->fFC = 0;
        obj->f1B8 = 0;
        if (obj->f184 == 3) {
            var_a0 = 1;
            if (obj->f1C8->f28 == 1) {
                var_v1 = obj->f1CC;
                goto block_18;
            }
            if (obj->f1B4 != 0) {
                var_v1 = obj->f1CC;
                goto block_18;
            }
        } else {
            temp_a0 = obj->f1D8->f28;
            if (((temp_a0 == 1) && (obj->f1E8->f28 == temp_a0)) || (obj->f1B4 != 0)) {
                var_a0 = obj->f1DC->f28;
                if (var_a0 == 1) {
                    var_v1 = obj->f1EC;
block_18:
                    var_t5 = ((var_v1->f28 ^ 1) != 0) ? 0 : var_a0;
                }
            }
        }
    } else {
        if (arg1 == 0) {
            temp_a0_2 = obj->f1CC;
            obj->f1CC = obj->f1C8;
            temp_v1 = obj->f1DC;
            obj->f1DC = obj->f1D8;
            temp_a2 = obj->f1E8;
            obj->f1C8 = temp_a0_2;
            obj->f1D8 = temp_v1;
            obj->f1E8 = obj->f1EC;
            obj->f1EC = temp_a2;
        }
        temp_a0_3 = obj->f1DC;
        temp_v1_2 = obj->f1EC;
        obj->f1D0 = obj->f1CC;
        obj->f1E0 = temp_a0_3;
        obj->f1F0 = temp_v1_2;
        if (temp_t1 == 3) {
            if (temp_t2 == 2) {
                var_v0 = obj->f1C8;
                var_a0_2 = 1;
                goto block_29;
            }
            goto block_30;
        }
        if ((temp_t2 == 2) && ((arg1 == 0) || ((((temp_t1 ^ 1) != 0) ? temp_a0_3 : temp_v1_2)->f28 != 1))) {
            var_a0_2 = obj->f1D8->f28;
            if (var_a0_2 == 1) {
                var_v0 = obj->f1E8;
block_29:
                if (var_v0->f28 == var_a0_2) {
                    goto block_30;
                }
            }
        } else {
block_30:
            var_t5 = 1;
        }
    }
    switch (obj->f184) {        /* irregular */
    case 1:
        var_t0 = obj->f1E0;
        break;
    case 3:
        var_t0 = obj->f1D0;
        break;
    case 2:
        var_t0 = obj->f1F0;
        break;
    }
    var_t0->f28 = 0;
    var_t0->f18 = obj->f838;
    var_t0->f2C = obj->f160;
    var_t0->f20 = obj->f840;
    var_t0->f30 = obj->f184;
    var_t0->f34 = obj->f14C;
    var_t0->f38 = obj->f198;
    var_t0->f3C = obj->f188;
    var_t0->f40 = obj->f194;
    var_t0->f44 = obj->f19C;
    var_t0->f48 = obj->f1A0;
    var_t0->f4C = obj->f1A4;
    var_t0->f50 = obj->f1A8;
    var_t0->f54 = obj->f1AC;
    var_t0->f58 = obj->f1B0;
    var_t0->f5C = obj->f158;
    var_t0->f60 = obj->f15C;
    return var_t5;
}
}
