// SPDX-License-Identifier: GPL-3.0-or-later
typedef signed char s8;
#define FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
extern "C" void AddLaserBeam(s8 *owner, int a, int w0, int b, int w1, float x0, float y0, float z0, float x1, float y1, float z1)
{
    int count = FIELD(owner, int *, 0x198);
    if (count < 0x40) {
        s8 *beam = (s8 *)(FIELD(owner, int *, 0x19C) + (count * 0x150));
        FIELD(beam, float *, 0x18) = x0;
        s8 *start = beam + 0x18;
        FIELD(beam, int *, 0) = a;
        FIELD(start, int *, 0xC) = w0;
        FIELD(start, float *, 4) = y0;
        FIELD(start, float *, 8) = z0;
        s8 *beam2 = (s8 *)(FIELD(owner, int *, 0x19C) + (FIELD(owner, int *, 0x198) * 0x150));
        FIELD(beam2, float *, 0xB8) = x1;
        s8 *end = beam2 + 0xB8;
        FIELD(beam2, int *, 0xA0) = b;
        FIELD(end, int *, 0xC) = w1;
        FIELD(end, float *, 4) = y1;
        FIELD(end, float *, 8) = z1;
        FIELD(owner, int *, 0x198) = FIELD(owner, int *, 0x198) + 1;
    }
}
