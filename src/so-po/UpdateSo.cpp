#include "sly2.h"
struct VT { char pad[0x48]; short delta; short index; void (*fn)(void *); };
struct PHYS { char pad[0xDC]; void *pregion; };
struct SO {
    char pad0[0xC]; VT *vt;
    char pad1[0xD8]; PHYS *pphys;
    char pad2[0x40]; float uFade; float duFade;
};
extern float g_2dded4;
extern "C" {
void UpdateLo(SO *);
QW PosLoWorld(SO *);
void *PpathzoneFindPos(QW, int);
void func_001F37C8(SO *, void *);
}
void UpdateSo(SO *pso)
{
    UpdateLo(pso);
    void *link = 0;
    if (pso->pphys)
        link = pso->pphys->pregion;
    if (link) {
        QW pos = PosLoWorld(pso);
        func_001F37C8(pso, PpathzoneFindPos(pos, 1));
    }
    register float zero asm("$f3");
    asm("mtc1 $0, %0\n\tnop" : "=f" (zero));
    float duFade = pso->duFade;
    if (duFade != zero) {
        float uFade = pso->uFade + g_2dded4 * duFade;
        pso->uFade = uFade;
        if (uFade <= zero) {
            pso->uFade = zero;
            pso->duFade = zero;
            VT *vt = pso->vt;
            vt->fn((char *)pso + vt->delta);
        } else {
            float one;
            asm("lui $1, 0x3f80\n\tmtc1 $1, %0\n\tnop" : "=f" (one));
            if (one <= uFade) {
                pso->uFade = one;
                pso->duFade = zero;
            }
        }
    }
}
