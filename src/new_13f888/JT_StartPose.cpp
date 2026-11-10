#include "sly2.h"
#include "jt.h"
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
        pjt->SetMode(iPose);
        RetractSmaRef(&pjt->field_0x1034);
        ApplyAsegToHandle(plo, pjt, grfapl, &pjt->field_0x1030, 0.0f, 1.0f);
    } else if (FIsBasicDerivedFrom(plo, 0x6F)) {
        pjt->SetMode(iPose);
        RetractAsegaHandle(&pjt->field_0x1030);
        func_001F1448(plo, pjt, -1, grfapl, &pjt->field_0x1034);
    }
}
