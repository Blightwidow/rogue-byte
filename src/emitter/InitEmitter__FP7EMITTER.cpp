#include "sly2.h"
struct EMITTER { char pad0[0x40]; unsigned tagged; char pad1[0xAC]; int unkF0; int unkF4; float unkF8; float unkFC; char pad2[0x18]; int unk118; char dl[0x2C]; float unk148; };
extern "C" void InitXfm(EMITTER *);
extern "C" void InitDl__FP2DLi(void *, int);
extern "C" void func_001A6CA8(EMITTER *, int);

void InitEmitter(EMITTER *pemitter)
{
    InitXfm(pemitter);
    pemitter->unkF4 = -1;
    pemitter->unkF0 = -1;
    pemitter->unk118 = -1;
    pemitter->unkFC = 10.0f;
    pemitter->unkF8 = 10.0f;
    pemitter->unk148 = -1.0f;
    InitDl__FP2DLi(pemitter->dl, 0x128);
    func_001A6CA8(pemitter, 0);
    unsigned tagged = pemitter->tagged;
    if (((tagged ^ 1) & 1) != 0) {
        unsigned *pu = (unsigned *)tagged;
        *pu = *pu | 2;
    } else {
        pemitter->tagged = tagged | 2;
    }
}
