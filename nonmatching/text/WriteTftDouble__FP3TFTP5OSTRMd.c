#include "m2c_macros.h"

s32 CbWrite__5OSTRMPvi(s32, s8 *, s32);             /* extern */
s32 CchAchFromDouble__FPciP3TFTd(s8 *, M2C_UNK, void *, s32); /* extern */
M2C_UNK UpperizePchz__FPc(s8 *);                    /* extern */
s32 __subdf3(M2C_UNK, s32);                         /* extern */
s32 dpcmp(s32, M2C_UNK);                            /* extern */
s32 strlen(u16 *);                                  /* extern */
extern u16 RO_002A9460;
extern u16 RO_002A9468;
extern u16 RO_002A9470;

void WriteTftDouble__FP3TFTP5OSTRMd(void *arg0, s32 arg1, s32 arg2) {
    char sp[0x400];
    s8 sp1C0;                                       /* compiler-managed */
    s8 sp1D0;
    s32 temp_a0;
    s32 temp_s1;
    s32 temp_s4;
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a1;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s3;
    s32 var_s5;
    s32 var_s7;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    u16 var_v1;

    var_s3 = arg2;
    var_s7 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x1C) == 0) {
        if (M2C_FIELD(arg0, s32 *, 0x14) == 0) {
            var_v0 = 6;
            goto block_6;
        }
        goto block_4;
    }
    if (M2C_FIELD(arg0, s32 *, 0x14) != 0) {
block_4:
        if (M2C_FIELD(arg0, u8 *, 0x2C) == 0x67) {
            var_v0 = 1;
block_6:
            M2C_FIELD(arg0, s32 *, 0x1C) = var_v0;
        }
    }
    temp_s1 = dpcmp(var_s3, 0) <= -1;
    if (temp_s1 != 0) {
        var_s3 = __subdf3(0, var_s3);
    }
    sp1C0 = 0;
    if (temp_s1 != 0) {
        var_v1 = RO_002A9460;
        goto block_15;
    }
    if (M2C_FIELD(arg0, s32 *, 4) != 0) {
        var_v1 = RO_002A9468;
        goto block_15;
    }
    if (M2C_FIELD(arg0, s32 *, 8) != 0) {
        var_v1 = RO_002A9470;
block_15:
        sp1C0 = var_v1;
    }
    temp_s4 = strlen(&sp1C0);
    temp_v0 = CchAchFromDouble__FPciP3TFTd(sp, 0x1B5, arg0, var_s3);
    sp[temp_v0] = 0;
    if (M2C_FIELD(arg0, s32 *, 0x30) != 0) {
        UpperizePchz__FPc(sp);
    }
    temp_a0 = M2C_FIELD(arg0, s32 *, 0x18);
    temp_v1 = temp_s4 + temp_v0;
    var_a1 = 0;
    var_s5 = 0;
    if (temp_v1 < temp_a0) {
        temp_v1_2 = temp_a0 - temp_v1;
        if (M2C_FIELD(arg0, s32 *, 0) != 0) {
            var_s5 = temp_v1_2;
        } else if (M2C_FIELD(arg0, s32 *, 0x10) == 0) {
            var_a1 = temp_v1_2;
        } else if (temp_v0 == 0) {
            var_a1 = temp_v1_2;
        } else {
            var_s7 = temp_v1_2;
        }
    }
    var_s0 = var_a1;
    sp1D0 = 0x20;
    var_v0_2 = var_s0;
loop_29:
    var_s0 -= 1;
    if (var_v0_2 > 0) {
        var_v0_2 = var_s0;
        if (CbWrite__5OSTRMPvi(arg1, &sp1D0, 1) == 1) {
            goto loop_29;
        }
    }
    var_s0_2 = var_s7;
    CbWrite__5OSTRMPvi(arg1, (s8 *) &sp1C0, temp_s4);
    sp1D0 = 0x30;
    var_v0_3 = var_s0_2;
loop_32:
    var_s0_2 -= 1;
    if (var_v0_3 > 0) {
        var_v0_3 = var_s0_2;
        if (CbWrite__5OSTRMPvi(arg1, &sp1D0, 1) == 1) {
            goto loop_32;
        }
    }
    var_s0_3 = var_s5;
    CbWrite__5OSTRMPvi(arg1, sp, temp_v0);
    sp1D0 = 0x20;
    var_v0_4 = var_s0_3;
loop_35:
    var_s0_3 -= 1;
    if (var_v0_4 > 0) {
        var_v0_4 = var_s0_3;
        if (CbWrite__5OSTRMPvi(arg1, &sp1D0, 1) == 1) {
            goto loop_35;
        }
    }
}
