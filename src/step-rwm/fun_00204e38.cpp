#include "sly2.h"
typedef int QW __attribute__((mode(TI)));
struct VT { char pad[0x18]; short delta; short index; void (*fn)(void *, float, float, QW *, QW *); };
struct CURVE { VT *vt; };
struct CHN { char p0[4]; CURVE *curve; };
struct ASEGA { char p0[0x14]; void *seg; char p1[0x40 - 0x18]; float rate; };
extern QW g_2a2dd0;
extern "C" int FAsegaGone(ASEGA *);
extern "C" CHN *PchnFindAseg(void *, void *, int, int);
extern "C" QW func_00204E38(float t, void *plo, ASEGA *asega)
{
    QW vel = g_2a2dd0;
    if (asega) {
        if (FAsegaGone(asega))
            return vel;
        CHN *chn = PchnFindAseg(asega->seg, plo, 1, 1);
        if (chn) {
            CURVE *curve = chn->curve;
            curve->vt->fn((char *)curve + curve->vt->delta, t, asega->rate, 0, &vel);
        }
    }
    return vel;
}
