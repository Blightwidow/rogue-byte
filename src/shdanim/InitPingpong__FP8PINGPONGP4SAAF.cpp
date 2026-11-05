#include "sly2.h"
struct R2 { float a, b; };
struct PINGPONG { char pad0[0x1C]; int cframe; char pad1[0x30]; R2 dt; R2 pause; float sv, gframe, dtPause, dtReq; };
struct SAAF { char pad[0xC]; float a, b, c, d; unsigned short e; };
extern "C" void InitSaa(void *, void *);
extern "C" float GRandInRange(float, float);
extern "C" void InitPingpong__FP8PINGPONGP4SAAF(PINGPONG *pp, SAAF *saaf)
{
    InitSaa(pp, saaf);
    R2 *dt = &pp->dt;
    R2 *pause = &pp->pause;
    float a = saaf->a;
    float b = saaf->b;
    dt->a = a;
    dt->b = b;
    float c = saaf->c;
    float d = saaf->d;
    pause->a = c;
    pause->b = d;
    int frame = saaf->e;
    pp->gframe = (float)frame;
    float t = GRandInRange(dt->a, dt->b);
    int twice = pp->cframe << 1;
    pp->sv = (float)twice / t;
    float p = GRandInRange(pause->a, pause->b);
    pp->dtPause = p;
    pp->dtReq = p;
}
