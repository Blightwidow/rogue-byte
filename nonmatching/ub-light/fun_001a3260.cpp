#include "sly2.h"
struct M3 { QW row[3]; };
struct VT { char pad[0xF0]; short delta; short index; void (*fn)(void *, M3 *); };
struct LIGHT { char pad0[0xC]; VT *vptr; char pad1[0x20 - 0x10]; LIGHT *pnext; char pad2[0x160 - 0x24]; int fDynamic; };
extern LIGHT *B_003E04F8;
extern QW g_2a2dc0;
extern "C" {
void *PloNew(int, int, int, int);
void BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(M3 *, QW, QW);
void func_001A3610(LIGHT *, float);
void func_001A3630(LIGHT *, float);
}
static inline QW Word(float f) { QW r; asm("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
static inline QW Vec3(float x, float y, float z) { return __builtin_pcpyld(Word(z), __builtin_pextlw(Word(y), Word(x))); }
extern "C" void func_001A3260()
{
    LIGHT *plight = B_003E04F8;
    while (plight && plight->fDynamic != 0)
        plight = plight->pnext;
    if (plight) return;
    plight = (LIGHT *)PloNew(4, 0, 0x188, -1);
    LIGHT *pnew = plight;
    struct L { M3 copy; QW dir; M3 mat; } l;
    QW dir = Vec3(-0.2f, 0.3f, -1.0f);
    l.dir = dir;
    BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(&l.mat, dir, g_2a2dc0);
    l.copy = l.mat;
    VT *vtable = pnew->vptr;
    vtable->fn((char *)pnew + vtable->delta, &l.copy);
    func_001A3610(pnew, 255.0f);
    func_001A3630(pnew, 240.0f);
}
