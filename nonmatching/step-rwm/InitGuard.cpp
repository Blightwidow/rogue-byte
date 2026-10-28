/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct SO { char pad0[0x40]; int tagged; };
extern "C" {
extern const float RO_FLT_002A8600;
extern const float RO_FLT_002A8604;
extern int D_002C3CF0;
void InitStep(void *);
void func_00205E70(void);
void *PloNew(int, int, int, int);
void func_001A6CA8(void *, int);
void ResetGuardAnimrefArrays(void *);
void func_00209768(void *, void *);
#define I(off) (*(int *)((char *)p + (off)))
#define F(off) (*(float *)((char *)p + (off)))
void InitGuard(void *p)
{
    InitStep(p);
    func_00205E70();
    void *sensor = PloNew(0x10, 0, 0x288, -1);
    I(0xF64) = (int)sensor;
    func_001A6CA8(sensor, 2);
    SO *so = (SO *)I(0xF64);
    int tagged = so->tagged;
    if ((tagged ^ 1) & 1) {
        *(int *)tagged &= ~2;
    } else {
        so->tagged = tagged & ~2;
    }
    float fa = 0.78539824f;
    float fb = 1.308997f;
    F(0xF50) = -fa;
    F(0xF54) = fa;
    F(0xF58) = -fb;
    F(0xF5C) = fb;
    F(0x318) = 1200.0f;
    F(0x320) = 450.0f;
    F(0x324) = 300.0f;
    F(0x328) = 600.0f;
    F(0x2D0) = RO_FLT_002A8600;
    F(0x370) = -100.0f;
    F(0x374) = 350.0f;
    F(0x378) = 1000.0f;
    F(0x380) = -800.0f;
    F(0x384) = 800.0f;
    F(0x388) = 3000.0f;
    F(0xE7C) = 16.0f;
    F(0xE80) = 20.0f;
    I(0xE84) = 50;
    F(0xE6C) = 5.5f;
    F(0xE70) = 6.5f;
    I(0x354) = 0x29FF7E;
    F(0xF48) = 300.0f;
    F(0xF4C) = 1200.0f;
    F(0x314) = 800.0f;
    F(0x31C) = 300.0f;
    F(0x2CC) = RO_FLT_002A8600;
    I(0x364) = 1;
    I(0x37C) = 1;
    I(0xE64) = 1;
    I(0xF40) = 1;
    I(0xE68) = -1;
    I(0xE78) = 0;
    I(0x350) = 0x20F800;
    unsigned long grf = *(unsigned long *)((char *)p + 0x148);
    int cell = D_002C3CF0;
    float lowest = RO_FLT_002A8604;
    grf = (grf & 0xFFFFFFFFFFF0FFFFUL) | 0x20000UL;
    I(0x358) = 0xF800;
    F(0x360) = -10.0f;
    I(0x4A0) = 1;
    F(0x260) = 1.5f;
    *(unsigned long *)((char *)p + 0x148) = grf;
    I(0x3F0) = -200;
    I(0xFBC) = -1;
    F(0xFF4) = lowest;
    I(0x1000) = cell;
    I(0x3D8) = -1;
    I(0xF80) = -1;
    I(0x3FC) = -1;
    ResetGuardAnimrefArrays(p);
    func_00209768((char *)p + 0xFD0, p);
}
}
