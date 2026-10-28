#include "sly2.h"
struct BASIC {
    char pad0[0xC];
    virtual void v0(); virtual void v1(); virtual void v2(int, int, int, int, int);
    virtual void v3();
};
struct SMA : BASIC {
    char pad1[0x14];
    int psm; char pad2[8]; int asega;
};
extern "C" int FSmaRetracted(SMA *);
extern "C" void RetractAsega(int);
extern "C" void RemoveDlEntry(int, SMA *);
extern char B_003E126C[];

void RetractSma(SMA *sma)
{
    if (FSmaRetracted(sma) == 0) {
        int a = sma->asega;
        if (a != 0) {
            sma->asega = 0;
            RetractAsega(a);
        }
        RemoveDlEntry(sma->psm + 0x68, sma);
        RemoveDlEntry((int)B_003E126C, sma);
        sma->v2(3, 0, 0, 0, 0);
        sma->v1();
    }
}
