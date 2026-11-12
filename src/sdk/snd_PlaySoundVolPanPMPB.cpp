#include "sly2.h"

typedef struct SPlaySoundArgs {
    int a0;
    int a1;
    int a2;
    int a3;
    int t0;
    int t1;
} SPlaySoundArgs;

extern "C" void func_002325E0(unsigned, unsigned, SPlaySoundArgs *);

extern "C" void snd_PlaySoundVolPanPMPB(int a0, int a1, int a2, int a3, int t0, int t1)
{
    SPlaySoundArgs s;
    s.a0 = a0;
    s.a1 = a1;
    s.a2 = a2;
    s.a3 = a3;
    s.t0 = t0;
    s.t1 = t1;
    func_002325E0(0x3B, 0x18, &s);
}
