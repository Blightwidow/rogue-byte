#include "m2c_macros.h"

M2C_UNK CBinaryFileStream_Destructor(M2C_UNK *, M2C_UNK); /* extern */
s32 CBinaryFileStream_FOpenLocation(M2C_UNK *, s32 *); /* extern */
M2C_UNK CBinaryInputStream_ConstructFromBuffer(M2C_UNK *, M2C_UNK, s32, M2C_UNK); /* extern */
M2C_UNK CStackFrame_Construct(void *);              /* extern */
M2C_UNK CStackFrame_Destructor(void *, M2C_UNK);    /* extern */
M2C_UNK Clear__13CFileLocation(s32 *);              /* extern */
M2C_UNK LoadMovieDictionary(void *, M2C_UNK *, void *, void *); /* extern */
M2C_UNK LoadMovieSprites(void *, M2C_UNK *, void *); /* extern */
s32 PvAllocStackImpl__Fi(s32 *);                    /* extern */
M2C_UNK SetBlotBlots(void *, M2C_UNK);              /* extern */
s32 U16Read__18CBinaryInputStream(M2C_UNK *);       /* extern */
s8 U8Read__18CBinaryInputStream(M2C_UNK *);         /* extern */
M2C_UNK func_001179D8(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
s32 func_00233470(s32 *, M2C_UNK *, M2C_UNK);       /* extern */
extern void *B_003E106C;
extern M2C_UNK B_003E1C70;
extern s32 g_2be538;

void PrepareBlotMovie(void *arg0) {
    char sp[0x400];
    M2C_UNK unksp11;
    M2C_UNK unksp12;
    M2C_UNK unksp13;
    s32 sp10;                                       /* compiler-managed */
    M2C_UNK sp20;
    s32 sp90;
    s32 sp94;
    s32 temp_a1_2;
    s32 temp_s2;
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_s2;
    s32 var_v0;
    void *temp_a0;
    void *temp_a1;
    void *var_a0;
    void *var_s0;
    void *var_s0_2;

    var_s2 = 0;
    var_s0 = B_003E106C;
    if (var_s0 != NULL) {
        var_a0 = M2C_FIELD(var_s0, void **, 0x40);
loop_2:
        temp_v0 = M2C_FIELD(var_a0, s32 *, 0x58);
        if ((temp_v0 != 0) && ((temp_v0 != 1) || ((g_2be538 - M2C_FIELD(var_a0, s32 *, 0x60)) < 2))) {
            temp_v1 = M2C_FIELD(var_s0, s32 *, 0x48);
            var_s2 = (var_s2 < temp_v1) ? temp_v1 : var_s2;
        }
        var_s0 = M2C_FIELD(var_s0, void **, 0x4C);
        if (var_s0 != NULL) {
            var_a0 = M2C_FIELD(var_s0, void **, 0x40);
            goto loop_2;
        }
    }
    var_s0_2 = B_003E106C;
    if (var_s0_2 != NULL) {
        do {
            temp_a0 = M2C_FIELD(var_s0_2, void **, 0x40);
            if ((M2C_FIELD(var_s0_2, s32 *, 0x44) >= var_s2) && (M2C_FIELD(temp_a0, s32 *, 0x58) != 0)) {
                SetBlotBlots(temp_a0, 0);
            }
            var_s0_2 = M2C_FIELD(var_s0_2, void **, 0x4C);
        } while (var_s0_2 != NULL);
    }
    M2C_FIELD(&B_003E1C70, s32 *, 0xC) = var_s2;
    CStackFrame_Construct(sp);
    sp10 = 0x10000;
    M2C_FIELD(&sp10, s32 *, 4) = 0x40;
    CBinaryInputStream_ConstructFromBuffer(&sp20, 0x10000, PvAllocStackImpl__Fi(&sp10), 0);
    M2C_FIELD(&sp90, s32 *, 8) = 2;
    Clear__13CFileLocation(&sp90);
    temp_a1 = M2C_FIELD(arg0, void **, 0xC0);
    if (temp_a1 != NULL) {
        temp_v1_2 = M2C_FIELD(temp_a1, s32 *, 4);
        temp_a1_2 = M2C_FIELD(temp_a1, s32 *, 0x3C);
        M2C_FIELD(&sp90, s32 *, 8) = 2;
        sp90 = (M2C_FIELD(temp_a1, s32 *, 0) ^ M2C_FIELD(temp_a1, s32 *, 0x34)) + 0xCA0;
        sp94 = temp_v1_2 ^ temp_a1_2;
        var_v0 = temp_v1_2 != temp_a1_2;
    } else {
        var_v0 = 0;
    }
    if ((var_v0 != 0) && (CBinaryFileStream_FOpenLocation(&sp20, &sp90) != 0)) {
        func_001179D8(&sp20, 0x4000, 0x70000000);
        sp10 = U8Read__18CBinaryInputStream(&sp20);
        unksp11 = U8Read__18CBinaryInputStream(&sp20);
        unksp12 = U8Read__18CBinaryInputStream(&sp20);
        unksp13 = U8Read__18CBinaryInputStream(&sp20);
        temp_s2 = U16Read__18CBinaryInputStream(&sp20);
        if (func_00233470(&sp10, "ZRB.", 4) == 0) {
            if (temp_s2 != 6) {
                goto block_24;
            }
            M2C_FIELD(M2C_FIELD(arg0, void **, 0xC0), s32 *, 0x44) = (s32) M2C_FIELD(&B_003E1C70, s32 *, 0xC);
            LoadMovieDictionary(arg0, &sp20, arg0, arg0 + 0x50);
            LoadMovieSprites(arg0, &sp20, arg0);
            M2C_FIELD(M2C_FIELD(arg0, void **, 0xC0), s32 *, 0x48) = (s32) M2C_FIELD(&B_003E1C70, s32 *, 0xC);
            CBinaryFileStream_Destructor(&sp20, 2);
            CStackFrame_Destructor(sp, 2);
            return;
        }
        goto block_25;
    }
block_24:
block_25:
    CBinaryFileStream_Destructor(&sp20, 2);
    CStackFrame_Destructor(sp, 2);
}
