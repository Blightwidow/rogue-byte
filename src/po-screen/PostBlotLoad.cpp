#include "sly2.h"
struct VT { char pad[0x188]; short delta; short index; void (*fn)(void *, int); };
struct SWX { char pad[0x3BE8]; void *font; };
struct BLOT;
extern "C" void PostLoLoad(BLOT *);
extern "C" void *PloFindSwObject_thunk(void *, int, int, void *);
extern "C" void func_001A6CA8(BLOT *, int);
extern "C" SWX B_003DD490;
struct BLOT { char p[1]; };
#define F(type, off) (*(type *)((char *)blot + (off)))
void PostBlotLoad(BLOT *blot)
{
    PostLoLoad(blot);
    if (F(int, 0xBC) != 0 && B_003DD490.font == 0)
        B_003DD490.font = PloFindSwObject_thunk(&B_003DD490, 0x405, 0x374, blot);
    int height = F(int, 0x94);
    F(BLOT *, 0xC8) = blot;
    F(int, 0xA8) = -1;
    int quotient = (height << 9) / 0x280;
    float scaled = (float)F(int, 0x98) * 0.45454547f;
    asm("" : "+f"(scaled));
    F(float, 0xA0) = 2048.0f - scaled * 0.5f;
    F(float, 0x9C) = 2048.0f - (float)quotient * 0.5f;
    if (F(unsigned char, 0x6D) != 0) {
        VT *vt = F(VT *, 0xC);
        vt->fn((char *)blot + vt->delta, -1);
    }
    func_001A6CA8(blot, 1);
    unsigned flags = F(unsigned, 0x40);
    if (((flags ^ 1) & 1) != 0)
        *(unsigned *)flags |= 0x102;
    else
        F(unsigned, 0x40) = flags | 0x102;
}
