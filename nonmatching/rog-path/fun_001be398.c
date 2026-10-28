#include "m2c_macros.h"

M2C_UNK AddPrimEnd__4GIFS();                  /* extern */
M2C_UNK AddPrimPack__4GIFSiiUl(); /* extern */
M2C_UNK AllocStatic__4DMASiP2QW(); /* extern */
s32 AllocZpr();                      /* extern */
M2C_UNK DMAS_DetachCopyPermanent(); /* extern */
s32 NLog2__FUi();              /* extern */
M2C_UNK PackAD__4GIFSll();      /* extern */
M2C_UNK PackXYZ__4GIFSiii(); /* extern */
M2C_UNK __4GIFS();                       /* extern */

void func_001BE398(void *arg0, void *arg1) {
    char sp[0x400];
    M2C_UNK sp30;
    s32 temp_s0;
    s32 temp_s6;
    s32 temp_s7;
    s32 temp_v0;
    s32 temp_v0_4;
    s32 var_s4;
    s64 temp_a1;
    u32 temp_v0_2;
    u32 temp_v0_3;
    u32 temp_v1;
    u32 temp_v1_2;

    M2C_FIELD(arg0, u32 *, 4) = 0x80U;
    M2C_FIELD(arg0, u32 *, 0) = 0x80U;
    temp_v0 = AllocZpr(arg1, 0x100);
    M2C_FIELD(arg0, s64 *, 8) = (s64) (((((M2C_FIELD(arg0, s64 *, 8) & ~0x3FFF) | (temp_v0 & 0x3FFF)) & 0xFFF03FFF) | 0x8000) & 0xFC0FFFFF);
    M2C_FIELD(arg0, s64 *, 8) = (s64) ((M2C_FIELD(arg0, s64 *, 8) & 0xC3FFFFFF) | ((NLog2__FUi(M2C_FIELD(arg0, u32 *, 0), 0xFFF03FFF, 0xFC0FFFFF) & 0xF) << 0x1A));
    temp_a1 = 0x8000 << 0x13;
    M2C_FIELD(arg0, s64 *, 8) = (s64) ((M2C_FIELD(arg0, s64 *, 8) & ((0x87FFFFFF * 8) | 7)) | ((NLog2__FUi(M2C_FIELD(arg0, u32 *, 4)) & 0xF) << 0x1E) | temp_a1);
    temp_s0 = (s32) (M2C_FIELD(arg1, s32 *, 8) - 0x100) >> 5;
    __4GIFS(sp, temp_a1);
    temp_v1 = M2C_FIELD(arg0, u32 *, 0);
    temp_v0_2 = M2C_FIELD(arg0, u32 *, 4);
    temp_s7 = 0x800 - ((s32) (temp_v1 + (temp_v1 >> 0x1F)) >> 1);
    temp_s6 = 0x800 - ((s32) (temp_v0_2 + (temp_v0_2 >> 0x1F)) >> 1);
    var_s4 = temp_s7;
    AllocStatic__4DMASiP2QW(sp, 0x40, &sp30, 0x800);
    AddPrimPack__4GIFSiiUl(sp, 0, 1, 0xE);
    temp_v1_2 = M2C_FIELD(arg0, u32 *, 0);
    temp_v0_3 = ((s32) temp_v1_2 > 0x40) ? temp_v1_2 : 0x40U;
    PackAD__4GIFSll(sp, 0x4C, (temp_v0 >> 5) | ((s64) ((s32) (((s32) temp_v0_3 > -1) ? temp_v0_3 : (temp_v0_3 + 0x3F)) >> 6) << 0x10));
    PackAD__4GIFSll(sp, 0x4E, temp_s0 | 0x30000000);
    PackAD__4GIFSll(sp, 0x18, (temp_s7 * 0x10) | ((temp_s6 * 0x10) << 0x20));
    PackAD__4GIFSll(sp, 0x40, ((M2C_FIELD(arg0, u32 *, 0) - 1) << 0x10) | ((M2C_FIELD(arg0, u32 *, 4) - 1) << 0x30));
    PackAD__4GIFSll(sp, 0x47, 0x30000);
    PackAD__4GIFSll(sp, 1, 0);
    AddPrimPack__4GIFSiiUl(sp, 6, 1, 5);
    if (var_s4 < (var_s4 + M2C_FIELD(arg0, u32 *, 0))) {
        do {
            PackXYZ__4GIFSiii(sp, var_s4 * 0x10, temp_s6 * 0x10, 0);
            temp_v0_4 = var_s4 + 0x20;
            var_s4 = temp_v0_4;
            PackXYZ__4GIFSiii(sp, temp_v0_4 * 0x10, (temp_s6 + M2C_FIELD(arg0, u32 *, 4)) * 0x10, 0);
        } while (var_s4 < (temp_s7 + M2C_FIELD(arg0, u32 *, 0)));
    }
    AddPrimEnd__4GIFS(sp);
    DMAS_DetachCopyPermanent(sp, arg0 + 0x10, 0, arg0 + 0x14);
    AllocStatic__4DMASiP2QW(sp, 0x40, &sp30);
    AddPrimPack__4GIFSiiUl(sp, 0, 1, 0xE);
    PackAD__4GIFSll(sp, 6, M2C_FIELD(arg0, s64 *, 8));
    PackAD__4GIFSll(sp, 0x14, 0x60);
    PackAD__4GIFSll(sp, 8, 5);
    AddPrimEnd__4GIFS(sp);
    DMAS_DetachCopyPermanent(sp, arg0 + 0x18, 0, arg0 + 0x1C);
}
