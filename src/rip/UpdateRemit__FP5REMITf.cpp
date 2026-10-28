#include "sly2.h"
struct RIP;
extern "C" void UpdateRip__FP3RIPf(RIP *, float);
extern float g_2dded4;
struct EXPLSO { int grf; char pad[0x1C]; QW pos; QW tail; };
struct EVT { char pad[0x198]; short delta; short index; void (*fn)(char *, EXPLSO *); };
struct EXPLS { char pad[0xC]; EVT *vt; };
struct REMIT { char pad0[0x70]; QW pos; char pad1[0xF0 - 0x80]; EXPLS *expls; float rate; float count; };

void UpdateRemit__FP5REMITf(REMIT *remit, float dt)
{
    UpdateRip__FP3RIPf((RIP *)remit, dt);
    if (remit->expls != 0) {
        remit->count = remit->count + g_2dded4 * remit->rate;
        float count = remit->count;
        if (count >= 1.0f) {
            do {
                EXPLSO explso;
                explso.grf = 4;
                explso.pos = remit->pos;
                EXPLS *expls = remit->expls;
                expls->vt->fn((char *)expls + expls->vt->delta, &explso);
                count = remit->count - 1.0f;
                remit->count = count;
            } while (count >= 1.0f);
        }
    }
}
