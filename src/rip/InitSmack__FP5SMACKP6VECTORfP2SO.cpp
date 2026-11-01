/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct SO; struct CM; struct RIP;
struct VEC3_1D04E8 { float x, y, z; };
struct SMACKI_1D04E8 { char pad0[0x20]; float vmin[3]; char pad1[4]; float vmax[3]; char pad2[0x50 - 0x3C]; QW scale; };
struct SMACK_1D04E8 { char pad0[0x18]; float lifetime; char pad1[0x20 - 0x1C]; QW scale; QW alpha; char pad2[0x90 - 0x40]; VEC3_1D04E8 v; char pad3[0xF0 - 0x9C]; SMACKI_1D04E8 *table; char pad4[0x100 - 0xF4]; QW screen; };
extern "C" float GRandInRange(float, float);
extern "C" QW ConvertCmWorldToScreen(CM *, QW);
extern "C" void InitRip__FP3RIPP6VECTORfP2SO(RIP *, QW, float, SO *);
extern CM B_002DDF40;
extern QW D_002BBB50;
extern float D_002C2000;
static inline void SetVec_1D04E8(VEC3_1D04E8 *p, float x, float y, float z) { p->x = x; p->y = y; p->z = z; }
extern "C" void InitSmack__FP5SMACKP6VECTORfP2SO(SMACK_1D04E8 *smack, QW pos, float scale, SO *so)
{
    InitRip__FP3RIPP6VECTORfP2SO((RIP *)smack, pos, scale, so);
    SMACKI_1D04E8 *table = smack->table;
    smack->screen = ConvertCmWorldToScreen(&B_002DDF40, pos);
    float vx = GRandInRange(table->vmin[0], table->vmax[0]);
    float vy = GRandInRange(table->vmin[1], table->vmax[1]);
    float vz = GRandInRange(table->vmin[2], table->vmax[2]);
    SetVec_1D04E8(&smack->v, vx, vy, vz);
    smack->lifetime = D_002C2000;

    smack->alpha = D_002BBB50;
    smack->scale = table->scale;
}
