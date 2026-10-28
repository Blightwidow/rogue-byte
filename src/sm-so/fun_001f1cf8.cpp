#include "sly2.h"
struct JOB { char pad[0x54]; int state; };
struct LO { char pad[0x230]; JOB *pjob; };
struct GUARDACT { int oid; int unk4; int nArg; int unkC; };
struct RIGOBJ { int unk; };
struct GUARD {
    char pad0[0x484]; int cguardact; int iguardactCur; int fActionDone; int unk490; RIGOBJ *prig;
};
extern "C" LO *PloFindSwObject_thunk(void *, int, int, RIGOBJ *);
extern "C" int FIsBasicDerivedFrom(void *, int);
extern "C" int SetPrizeSpewerObject(RIGOBJ *, void *, int, int);
extern "C" void func_001F1900(GUARD *);
extern "C" char B_003DD490;

void func_001F1CF8(GUARD *pguard)
{
    pguard->fActionDone = 0;
    for (int iguardact = pguard->iguardactCur; iguardact < pguard->cguardact; iguardact = ++pguard->iguardactCur) {
        GUARDACT *pguardact = (GUARDACT *)((char *)pguard + 0x404 + (iguardact << 4));
        LO *plo = PloFindSwObject_thunk(&B_003DD490, 4, pguardact->oid, pguard->prig);
        if (plo == 0)
            continue;
        int nArg = pguardact->nArg;
        int oidKind = 0x2B0;
        if (FIsBasicDerivedFrom(plo, 0x5C)) {
            JOB *pjob = plo->pjob;
            if (pjob) {
                int nJobState = pjob->state;
                if ((unsigned)(nJobState + 1) < 2) {
                    pguard->fActionDone = 1;
                    break;
                }
                if (nJobState != 1)
                    continue;
            }
            oidKind = 0x2B1;
        }
        int result = SetPrizeSpewerObject(pguard->prig, plo, nArg, oidKind);
        if (result == 1)
            pguard->fActionDone = result;
        break;
    }
    func_001F1900(pguard);
}
