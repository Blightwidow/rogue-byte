#include "sly2.h"
struct CRef { int tagk; int n; CRef &operator=(const CRef &); };
struct CPair { int pad0; int pad4; CRef ref; CPair *next; };
struct CProc { int pad0; int pad4; int frame; int cArg; int fRest; int pad14; CPair *body; };
struct CMeth { int pad0; int pad4; int ctx; int fn; };
extern "C" void CRef_Destruct(CRef *);
extern "C" void CRef_ConstructPair(CRef *, CPair *);
extern "C" CRef *func_001205B8(CRef *, CRef *, CRef *);
extern "C" CRef *bevy_splice_bif_ref_equal(CRef *pref, CRef *refA, CRef *refB)
{
    int f;
    if (refA->tagk != refB->tagk) {
        f = 0;
    } else {
        switch (refA->tagk) {
        case 0x1F: {
            CPair *pairA = (CPair *)refA->n;
            CPair *pairB = (CPair *)refB->n;
            if (pairA == pairB) {
                f = 1;
            } else if ((pairA->next == 0) != (pairB->next == 0)) {
                f = 0;
            } else {
                CRef result;
                result.tagk = -1;
                {
                    CRef car;
                    func_001205B8(&car, &pairA->ref, &pairB->ref);
                    result = car;
                    CRef_Destruct(&car);
                }
                if (result.n == 0) {
                    f = 0;
                } else if (pairA->next == 0) {
                    f = 1;
                } else {
                    CRef tailA;
                    CRef tailB;
                    CRef tail;
                    CRef_ConstructPair(&tailA, pairA->next);
                    CRef_ConstructPair(&tailB, pairB->next);
                    func_001205B8(&tail, &tailA, &tailB);
                    result = tail;
                    CRef_Destruct(&tail);
                    f = result.n;
                    CRef_Destruct(&tailB);
                    CRef_Destruct(&tailA);
                }
                CRef_Destruct(&result);
            }
            break;
        }
        case 0x20: {
            CProc *procA = (CProc *)refA->n;
            CProc *procB = (CProc *)refB->n;
            if (procA == procB) {
                f = 1;
            } else if (f = 0, procA->cArg == procB->cArg && procA->fRest == procB->fRest && procA->frame == procB->frame) {
                CRef bodyA;
                CRef bodyB;
                CRef bodies;
                CRef_ConstructPair(&bodyA, procA->body);
                CRef_ConstructPair(&bodyB, procB->body);
                func_001205B8(&bodies, &bodyA, &bodyB);
                f = bodies.n;
                CRef_Destruct(&bodies);
                CRef_Destruct(&bodyB);
                CRef_Destruct(&bodyA);
            }
            break;
        }
        case 0x15: case 0x17: case 0x18: case 0x19: case 0x21:
            if (refA->n == refB->n) f = 1; else f = 0;
            break;
        case 0x22: {
            CMeth *methA = (CMeth *)refA->n;
            CMeth *methB = (CMeth *)refB->n;
            if (methA == methB) {
                f = 1;
            } else if (f = 0, methA->ctx == methB->ctx) {
                f = methA->fn == methB->fn;
            }
            break;
        }
        case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
        case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19: case 20:
        case 0x24:
            f = 1;
            break;
        default:
            break;
        }
    }
    pref->n = f;
    pref->tagk = 0x17;
    return pref;
}
