#include "sly2.h"
struct SM;
struct SMA {
    char pad1[0x24];
    SM *psm; char pad2[8]; int asega; int a34; int a38; char pad3[0xC]; int a48;
};
extern "C" int FSmaRetracted(SMA *);
extern "C" int IsmsFindSmOptional__FP2SM3OID(SM *, int);
extern "C" int PsmtChooseSmTowards(SM *, int, int, int, int);
extern "C" void SetSmaGoal__FP3SMA3OID(SMA *, int);

void SetSmaGoalIfReachable(SMA *sma, int oid)
{
    if (FSmaRetracted(sma) == 0) {
        if (oid != -1) {
            int ism = IsmsFindSmOptional__FP2SM3OID(sma->psm, oid);
            if (ism != -1) {
                int from;
                if (sma->asega == 0) from = sma->a34; else from = sma->a38;
                if (PsmtChooseSmTowards(sma->psm, sma->a48, from, ism, 0))
                    SetSmaGoal__FP3SMA3OID(sma, oid);
            }
        }
    }
}
