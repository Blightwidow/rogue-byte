#include "sly2.h"
struct VT { char pad[0x48]; short delta; short index; void (*fn)(void *); };
struct PHYS { char pad[0xDC]; void *pregion; };
struct SO {
    char pad0[0xC]; VT *vt;
    char pad1[0xD8]; PHYS *pphys;
    char pad2[0x40]; float uFade; float duFade;
};
extern "C" float g_2dded4;
extern "C" {
void UpdateLo(SO *);
QW PosLoWorld(SO *);
void *PpathzoneFindPos(QW, int);
void func_001F37C8(SO *, void *);
}
extern "C" void UpdateSo(SO *pso)
{
    UpdateLo(pso);
    void *link = 0;
    if (pso->pphys)
        link = pso->pphys->pregion;
    if (link) {
        QW pos = PosLoWorld(pso);
        func_001F37C8(pso, PpathzoneFindPos(pos, 1));
    }
    if (pso->duFade != 0.0f) {
        float uFade = pso->uFade + g_2dded4 * pso->duFade;
        pso->uFade = uFade;
        if (uFade <= 0.0f) {
            pso->uFade = 0.0f;
            pso->duFade = 0.0f;
            VT *vt = pso->vt;
            vt->fn((char *)pso + vt->delta);
        } else {
            if (1.0f <= uFade) {
                pso->uFade = 1.0f;
                pso->duFade = 0.0f;
            }
        }
    }
}
