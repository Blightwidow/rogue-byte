// SPDX-License-Identifier: GPL-3.0-or-later
extern "C" {
struct RGBA4_1C8CC0 { char c[4]; };
struct CPROG_1C8CC0 {
    int field0; int field4; int field8; int fieldC; char byte10; char pad0[0x50 - 0x11];
    int field50; RGBA4_1C8CC0 color0; RGBA4_1C8CC0 color1; RGBA4_1C8CC0 color2; RGBA4_1C8CC0 color3;
};
CPROG_1C8CC0 *__5CProgP4RGBAN31(CPROG_1C8CC0 *prog, const RGBA4_1C8CC0 *rgba0, const RGBA4_1C8CC0 *rgba1, const RGBA4_1C8CC0 *rgba2, const RGBA4_1C8CC0 *rgba3)
{
    prog->color0 = *rgba0;
    prog->color1 = *rgba1;
    prog->color2 = *rgba2;
    prog->color3 = *rgba3;
    prog->field0 = 0;
    prog->field50 = 0;
    prog->fieldC = 0;
    prog->field8 = 0;
    prog->field4 = 0;
    prog->byte10 = 0;
    return prog;
}
}
