#include "sly2.h"
struct ASEGA { char pad[0x1C]; float t; char pad2[0x20]; float svt; };
struct VTC { char pad[0x18]; short delta; short index; void (*fn)(void *, float, float, void *, void *); };
struct CURVE { VTC *vt; };
struct ACT { char pad[0x1C]; CURVE *pacp; int unk20; ASEGA *pasega; };
extern "C" void FWrapAsegaTime(ASEGA *, float *, float *);
extern "C" void func_0012CF30(ACT *, void *, void *);
void GetActsegPositionGoal(ACT *pact, void *ppos, void *pvel, float dt)
{
    if (pact->pacp) {
        float tLocal[2];
        ASEGA *pasega = pact->pasega;
        float svt = pasega->svt;
        tLocal[0] = pasega->t + dt * svt;
        tLocal[1] = svt;
        FWrapAsegaTime(pasega, &tLocal[0], &tLocal[1]);
        CURVE *pacp = pact->pacp;
        VTC *vt = pacp->vt;
        float t0 = tLocal[0], t1 = tLocal[1];
        vt->fn((char *)pacp + vt->delta, t0, t1, ppos, pvel);
    } else {
        func_0012CF30(pact, ppos, pvel);
    }
}
