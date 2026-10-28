#include "m2c_macros.h"

M2C_UNK AddDmaCnt__4DMAS(void *);                   /* extern */
M2C_UNK AddDmaEnd__4DMAS(void *);                   /* extern */
M2C_UNK AddDmaRefs__4DMASiP2QW(void *, M2C_UNK, s32); /* extern */
M2C_UNK AddImage__4GIFSi(void *, M2C_UNK);          /* extern */
M2C_UNK AddPrimEnd__4GIFS(void *);                  /* extern */
M2C_UNK AddPrimPack__4GIFSiiUl(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK AllocStatic__4DMASiP2QW(void *, M2C_UNK, s32); /* extern */
M2C_UNK Detach__4DMASPiPP2QW(void *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK PackAD__4GIFSll(void *, M2C_UNK, s64);      /* extern */
M2C_UNK __4GIFS(void *, s32, s32, M2C_UNK);         /* extern */

void BuildMpegGifs__FP2QWP11sceIpuRGB32iiiii(void *arg0) {
    char sp[0x400];
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_a2_3;
    s32 temp_s5;
    s32 temp_s6;
    s32 var_s0;
    s32 var_s2;
    s64 temp_a2_2;
    s64 var_a2;

    temp_a1 = M2C_FIELD(arg0, s32 *, 0x11C);
    temp_a2 = M2C_FIELD(arg0, s32 *, 0x118);
    var_s2 = M2C_FIELD(arg0, s32 *, 0x110) + 0x285A80;
    temp_s6 = (s32) ((temp_a2 > -1) ? temp_a2 : (temp_a2 + 0xF)) >> 4;
    temp_s5 = (s32) ((temp_a1 > -1) ? temp_a1 : (temp_a1 + 0xF)) >> 4;
    __4GIFS(sp, temp_a1, temp_a2, 0x285A80);
    AllocStatic__4DMASiP2QW(sp, 0x22D6, M2C_FIELD(arg0, s32 *, 0x110) + 0x3F8E80);
    AddDmaCnt__4DMAS(sp);
    AddPrimPack__4GIFSiiUl(sp, 0, 1, 0xE);
    PackAD__4GIFSll(sp, 0x50, 0xC180 << 0x24);
    PackAD__4GIFSll(sp, 0x52, (0x8000 << 0x15) | 0x10);
    var_a2 = 0;
    if (temp_s6 > 0) {
        var_s0 = 0;
        do {
            if (temp_s5 > 0) {
                do {
                    AddPrimPack__4GIFSiiUl(sp, 0, 1, 0xE);
                    temp_a2_2 = (var_a2 << 0x24) | ((var_s0 * 0x10) << 0x30);
                    var_s0 += 1;
                    PackAD__4GIFSll(sp, 0x51, temp_a2_2);
                    PackAD__4GIFSll(sp, 0x53, 0);
                    AddImage__4GIFSi(sp, 0x40);
                    temp_a2_3 = var_s2 & 0x0FFFFFFF;
                    var_s2 += 0x400;
                    AddDmaRefs__4DMASiP2QW(sp, 0x40, temp_a2_3);
                } while (var_s0 < temp_s5);
            }
            var_a2 += 1;
            var_s0 = 0;
        } while (var_a2 < temp_s6);
    }
    AddPrimPack__4GIFSiiUl(sp, 0, 1, 0xE);
    PackAD__4GIFSll(sp, 0x3F, 0);
    PackAD__4GIFSll(sp, 0x61, 0);
    AddPrimEnd__4GIFS(sp);
    AddDmaEnd__4DMAS(sp);
    Detach__4DMASPiPP2QW(sp, 0, 0);
}
