#include "sly2.h"
struct PHYS { char pad[0xDC]; void *pregion; };
#include "so.h"
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
            pso->Remove();
        } else {
            if (1.0f <= uFade) {
                pso->uFade = 1.0f;
                pso->duFade = 0.0f;
            }
        }
    }
}
