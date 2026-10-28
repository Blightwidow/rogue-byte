#include "m2c_macros.h"

M2C_UNK AddDmaRefs__4DMASiP2QW(void *, s32, s32);   /* extern */
M2C_UNK AddToIdTableA_1ed470(void *);               /* extern */
M2C_UNK AddToIdTableB_1ed560(void *);               /* extern */
s32 AllocZpr(void *, u16);                          /* extern */
M2C_UNK BuildBmpGifs__FP3BMPiP4GIFS(void *, s32, void *); /* extern */
M2C_UNK BuildBmpTex0__FP3BMPi(void *, s32);         /* extern */
M2C_UNK BuildClutGifs__FP4CLUTiP4GIFS(void *, s32, void *); /* extern */
M2C_UNK BuildClutTex2__FP4CLUTi(void *, s32);       /* extern */
void *PidFindInIdTableA_1ed4e0(s32);                /* extern */
void *PidFindInIdTableB_1ed5d0(s32);                /* extern */
extern s32 B_003DCFF0;
extern s32 B_003DCFF4;
extern s32 B_003DCFF8;
extern s32 B_003DCFFC;

s32 FBuildUploadBitmapGifs__FiP3GSBP4GIFS(s32 arg0, void *arg1, void *arg2) {
    s32 sp0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_7;
    s32 temp_v0_8;
    s32 var_s4;
    s32 var_s4_2;
    s32 var_s5;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_v0_3;
    void *temp_v0_6;

    sp0 = 0;
    if (arg2 != NULL) {
        sp0 = M2C_FIELD(arg2, s32 *, 0xC);
    }
    var_s4 = 0;
    if (B_003DCFF8 > 0) {
        temp_v0 = B_003DCFFC;
        do {
            temp_s0 = temp_v0 + (var_s4 << 5);
            temp_v0_2 = B_003DCFF8;
            if (arg0 == M2C_FIELD(temp_s0, u8 *, 4)) {
                temp_v0_3 = PidFindInIdTableB_1ed5d0(M2C_FIELD(temp_s0, s32 *, 0));
                if (temp_v0_3 == NULL) {
                    temp_v0_4 = AllocZpr(arg1, M2C_FIELD(temp_s0, u16 *, 0xA));
                    BuildClutTex2__FP4CLUTi(temp_s0, temp_v0_4);
                    if ((arg2 != NULL) && (M2C_FIELD(arg1, s32 *, 8) >= M2C_FIELD(arg1, s32 *, 4))) {
                        BuildClutGifs__FP4CLUTiP4GIFS(temp_s0, temp_v0_4, arg2);
                        AddDmaRefs__4DMASiP2QW(arg2, M2C_FIELD(temp_s0, s32 *, 0x10), M2C_FIELD(temp_s0, s32 *, 0xC));
                    }
                    AddToIdTableB_1ed560(temp_s0);
                } else {
                    M2C_FIELD(temp_s0, s64 *, 0x18) = (s64) M2C_FIELD(temp_v0_3, s64 *, 0x18);
                }
            }
            var_s4 += 1;
        } while (var_s4 < temp_v0_2);
    }
    var_s4_2 = 0;
    if (B_003DCFF0 > 0) {
        var_s5 = 0;
        do {
            temp_s0_2 = B_003DCFF4 + var_s5;
            temp_v0_5 = B_003DCFF0;
            if (arg0 == M2C_FIELD(temp_s0_2, u8 *, 4)) {
                temp_v0_6 = PidFindInIdTableA_1ed4e0(M2C_FIELD(temp_s0_2, s32 *, 0));
                if (temp_v0_6 == NULL) {
                    if (M2C_FIELD(temp_s0_2, u8 *, 0xC) == 0) {
                        temp_v0_7 = M2C_FIELD(arg1, s32 *, 4) & 0x1F;
                        if (temp_v0_7 != 0) {
                            AllocZpr(arg1, 0x20 - temp_v0_7);
                        }
                    }
                    temp_v0_8 = AllocZpr(arg1, M2C_FIELD(temp_s0_2, u16 *, 0xE));
                    BuildBmpTex0__FP3BMPi(temp_s0_2, temp_v0_8);
                    if ((arg2 != NULL) && (M2C_FIELD(arg1, s32 *, 8) >= M2C_FIELD(arg1, s32 *, 4))) {
                        BuildBmpGifs__FP3BMPiP4GIFS(temp_s0_2, temp_v0_8, arg2);
                        AddDmaRefs__4DMASiP2QW(arg2, M2C_FIELD(temp_s0_2, s32 *, 0x18), M2C_FIELD(temp_s0_2, s32 *, 0x14));
                    }
                    AddToIdTableA_1ed470(temp_s0_2);
                } else {
                    M2C_FIELD(temp_s0_2, s64 *, 0x20) = (s64) M2C_FIELD(temp_v0_6, s64 *, 0x20);
                }
            }
            var_s4_2 += 1;
            var_s5 += 0x28;
        } while (var_s4_2 < temp_v0_5);
    }
    if (arg2 != NULL) {
        return M2C_FIELD(arg2, s32 *, 0xC) != sp0;
    }
    return 0;
}
