#include "sly2.h"
struct VT { char pad[0x2C0]; short delta; short index; void (*fn)(void *, int); };
struct JT { char pad0[0xC]; VT *vptr; char pad1[0x1030 - 0x10]; void *handleAseg; void *refSm; };
struct SW;
extern "C" SW B_003DD490;
extern "C" void JT_EndPose(JT *);
extern "C" void *PloFindSwObject_thunk(SW *, int, int, void *);
extern "C" int FIsBasicDerivedFrom(void *, int);
extern "C" void RetractSmaRef(void *);
extern "C" void RetractAsegaHandle(void *);
extern "C" void ApplyAsegToHandle(void *, JT *, int, void *, float, float);
extern "C" void func_001F1448(void *, JT *, int, int, void *);

extern "C" void JT_StartPose(JT *pjt, int oid, int grfapl, int iPose)
{
    if (oid == -1) {
        JT_EndPose(pjt);
        return;
    }
    void *plo = PloFindSwObject_thunk(&B_003DD490, 1, oid, pjt);
    if (plo == 0) return;
    if (FIsBasicDerivedFrom(plo, 0x6D)) {
        VT *vt = pjt->vptr;
        vt->fn((char *)pjt + vt->delta, iPose);
        RetractSmaRef(&pjt->refSm);
        ApplyAsegToHandle(plo, pjt, grfapl, &pjt->handleAseg, 0.0f, 1.0f);
    } else if (FIsBasicDerivedFrom(plo, 0x6F)) {
        VT *vt = pjt->vptr;
        vt->fn((char *)pjt + vt->delta, iPose);
        RetractAsegaHandle(&pjt->handleAseg);
        func_001F1448(plo, pjt, -1, grfapl, &pjt->refSm);
    }
}
