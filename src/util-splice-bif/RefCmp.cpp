#include "sly2.h"
struct CRef { int tagk; union { int n; float g; }; };
extern "C" CRef *RefCmp(CRef *prefReturn, const CRef *aref, int cmpk, int unused, int nUnknownResult)
{
    float agOperand[2];
    for (int iOperand = 0; iOperand < 2; ++iOperand) {
        if (aref[iOperand].tagk == 0x16)
            agOperand[iOperand] = aref[iOperand].g;
        else
            agOperand[iOperand] = (float)aref[iOperand].n;
    }
    int fResult;
    switch (cmpk) {
    case 0:
        fResult = agOperand[0] < agOperand[1];
        break;
    case 1:
        fResult = agOperand[0] <= agOperand[1];
        break;
    case 2:
        fResult = agOperand[0] > agOperand[1];
        break;
    case 3:
        fResult = agOperand[0] >= agOperand[1];
        break;
    default:
        fResult = nUnknownResult;
    }
    prefReturn->n = fResult;
    prefReturn->tagk = 0x17;
    return prefReturn;
}
