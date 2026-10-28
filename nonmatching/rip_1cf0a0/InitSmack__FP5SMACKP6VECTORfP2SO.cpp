#include "sly2.h"
struct SO; struct CM; struct RIP;
struct SMACKI { char pad0[0x20]; float vmin[3]; char pad1[4]; float vmax[3]; char pad2[0x50 - 0x3C]; QW scale; };
struct SMACK { char pad0[0x18]; float lifetime; char pad1[0x20 - 0x1C]; QW scale; QW alpha; char pad2[0x90 - 0x40]; float v[3]; char pad3[0xF0 - 0x9C]; SMACKI *table; char pad4[0x100 - 0xF4]; QW screen; };
extern "C" float GRandInRange(float, float);
extern "C" QW ConvertCmWorldToScreen(CM *, QW);
extern "C" void InitRip__FP3RIPP6VECTORfP2SO(RIP *, QW, float, SO *);
extern CM B_002DDF40;
extern QW D_002BBB50;
extern float D_002C2000;

void InitSmack__FP5SMACKP6VECTORfP2SO(SMACK *smack, QW pos, float scale, SO *so)
{
    InitRip__FP3RIPP6VECTORfP2SO((RIP *)smack, pos, scale, so);
    SMACKI *table = smack->table;
    smack->screen = ConvertCmWorldToScreen(&B_002DDF40, pos);
    float vx = GRandInRange(table->vmin[0], table->vmax[0]);
    float vy = GRandInRange(table->vmin[1], table->vmax[1]);
    float vz = GRandInRange(table->vmin[2], table->vmax[2]);
    smack->v[0] = vx;
    smack->v[1] = vy;
    smack->v[2] = vz;
    smack->lifetime = D_002C2000;
    smack->alpha = D_002BBB50;
    smack->scale = table->scale;
}
