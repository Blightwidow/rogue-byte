#include "sly2.h"
struct CMpegAudio { char pad[4]; void Reset(); void Close(); };
struct CMpeg {
    char pad[0x10C];
    int a10c;
    char pad2[4];
    int a114;
    char pad3[0x180 - 0x118];
    char audio[0xC0];
    int a240;
    void Finish();
};
extern "C" void func_0024B590(void *);
extern "C" void func_0024B530(void *);
extern int g_2dedbc;
void CMpeg::Finish()
{
    a114 = 0;
    CMpegAudio *pa = (CMpegAudio *)audio;
    void *p = (char *)this + 0x118;
    a10c = 0;
    pa->Reset();
    pa->Close();
    func_0024B590(p);
    func_0024B530(p);
    while (a240 != 0) { asm volatile("" : : : "memory"); }
    g_2dedbc = 3;
}