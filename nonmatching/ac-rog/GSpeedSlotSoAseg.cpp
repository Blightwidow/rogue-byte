#include "sly2.h"
typedef int QW __attribute__((mode(TI)));
struct VT { char pad[0x18]; short delta; short index; void (*fn)(void *, QW *, int, void *, float, float); };
struct CURVE { VT *vt; };
struct CHN { char p0[4]; CURVE *curve; };
struct ASEGA { char p0[0x74]; float speed; float scale; };
extern "C" CHN *PchnFindAseg(ASEGA *, void *, int, int);
extern "C" void GSpeedSlotSoAseg(void *plo, ASEGA *asega, float *out)
{
    if (asega) {
        CHN *chn = PchnFindAseg(asega, plo, 1, 1);
        if (chn) {
            QW first;
            QW second;
            CURVE *curve = chn->curve;
            curve->vt->fn((char *)curve + curve->vt->delta, &first, 0, curve, 0.0f, 1.0f);
            curve = chn->curve;
            curve->vt->fn((char *)curve + curve->vt->delta, &second, 0, curve, asega->speed, 1.0f);
            float delta = __builtin_fabsf(*(float *)&second - *(float *)&first);
            *out = delta / asega->speed * asega->scale;
        }
    }
}
