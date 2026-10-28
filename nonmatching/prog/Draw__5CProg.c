#include "m2c_macros.h"

M2C_UNK AddDmaCnt__4DMAS();                /* extern */
M2C_UNK AddDmaEnd__4DMAS();                /* extern */
M2C_UNK AddPrimEnd__4GIFS();               /* extern */
M2C_UNK AllocStatic__4DMASiP2QW(); /* extern */
M2C_UNK BlastAqwGifsBothFrames__FP2QW();      /* extern */
M2C_UNK Detach__4DMASPiPP2QW(); /* extern */
M2C_UNK EndDmaCnt__4DMAS();                /* extern */
M2C_UNK FillScreenRect__FiiiiffffP4GIFS(); /* extern */
f32 GTrunc__Ff();                   /* extern */
M2C_UNK __4GIFS();                         /* extern */

void Draw__5CProg(void *arg0) {
    char sp[0x400];
    M2C_UNK sp4000;
    M2C_UNK sp4030;
    M2C_UNK sp4040;
    M2C_UNK temp_a0;
    f32 temp_f0;
    f32 temp_f21;
    f32 temp_f22;
    f32 temp_s3;
    f32 temp_s4;
    s32 temp_v0;
    s32 temp_v1;
    s32 var_v0;

    __4GIFS(&sp4000);
    AllocStatic__4DMASiP2QW(&sp4000, 0x400, sp);
    AddDmaCnt__4DMAS(&sp4000);
    temp_v0 = M2C_FIELD(arg0, s32 *, 8);
    temp_f0 = (f32) temp_v0;
    temp_a0 = M2C_UNALIGNED32(M2C_FIELD(arg0, M2C_UNK *, 0x54));
    sp4030 = temp_a0;
    temp_s4 = temp_f0;
    temp_s3 = (f32) (temp_v0 - M2C_FIELD(arg0, s32 *, 0xC)) / temp_f0;
    temp_f21 = GTrunc__Ff(temp_a0, 0x43CE745D) * 1.1f;
    FillScreenRect__FiiiiffffP4GIFS(&sp4030, &sp4000, 10.0f, temp_f21, (f32) (M2C_BITWISE(s32, temp_s3) + 0xA), (GTrunc__Ff(0x43CE745D) * 1.1f) + 6.6000004f);
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x50);
    if (temp_v1 <= 0) {
        sp4030 = M2C_UNALIGNED32(M2C_FIELD(arg0, M2C_UNK *, 0x58));
        var_v0 = M2C_BITWISE(s32, temp_s3) + 0xA;
    } else {
        var_v0 = M2C_BITWISE(s32, temp_s3) + 0xA;
        if (temp_v1 == 1) {
            sp4030 = M2C_UNALIGNED32(M2C_FIELD(arg0, M2C_UNK *, 0x5C));
            var_v0 = M2C_BITWISE(s32, temp_s3) + 0xA;
        } else {
            sp4030 = M2C_UNALIGNED32(M2C_FIELD(arg0, M2C_UNK *, 0x60));
        }
    }
    sp4040 = M2C_UNALIGNED32(sp4030);
    temp_f22 = GTrunc__Ff(0x43CE745D) * 1.1f;
    FillScreenRect__FiiiiffffP4GIFS(&sp4040, &sp4000, (f32) var_v0, temp_f22, (f32) (M2C_BITWISE(s32, temp_s4) + 0xA), (GTrunc__Ff(0x43CE745D) * 1.1f) + 6.6000004f);
    AddPrimEnd__4GIFS(&sp4000);
    AddDmaEnd__4DMAS(&sp4000);
    EndDmaCnt__4DMAS(&sp4000);
    Detach__4DMASPiPP2QW(&sp4000, 0, 0);
    BlastAqwGifsBothFrames__FP2QW(sp);
}
