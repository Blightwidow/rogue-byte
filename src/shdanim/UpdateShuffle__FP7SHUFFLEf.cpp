#include "sly2.h"
struct SHUFFLE { char pad[0x1C]; int cframe; char pad2[8]; unsigned short iframe; char pad3[10]; char sl[1]; char pad4[0x1B]; float tmin, tmax, left; };
extern "C" int FIsSlEmpty(void *);
extern "C" int NRandInRange(int, int);
extern "C" void SetSaiIframe(SHUFFLE *, int);
extern "C" float GRandInRange(float, float);
extern float g_2dded4;
void UpdateShuffle__FP7SHUFFLEf(SHUFFLE *s, float dt)
{
    if (FIsSlEmpty(s->sl)) return;
    int c = s->cframe;
    if (c < 2) return;
    float left;
    float zero = 0.0f;
    float cur = s->left;
    asm volatile("nop" : : "f" (zero));
    if (zero < cur) {
        left = cur - g_2dded4;
    } else {
        int d = NRandInRange(1, c - 1);
        SetSaiIframe(s, (s->iframe + d) % s->cframe);
        left = GRandInRange(s->tmin, s->tmax);
    }
    s->left = left;
}
