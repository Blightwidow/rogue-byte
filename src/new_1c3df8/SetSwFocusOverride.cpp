struct VT { char pad[0x270]; short delta; short idx; void (*fn)(void *, int); };
struct PO { char pad[0xC]; VT *vt; };
#include "sw.h"
extern "C" PO *PpoSwFocus(SW *);

void SetSwFocusOverride(SW *psw, PO *ppo)
{
    PO *ppoOld = PpoSwFocus(psw);
    PO *ppoNew = ppo;
    if (ppoNew == 0)
        ppoNew = psw->ppoFocusBase;
    if (ppoOld != ppoNew && ppoOld != 0)
        ppoOld->vt->fn((char *)ppoOld + ppoOld->vt->delta, 0);
    psw->ppoFocusOverride = ppo;
    if (ppoOld != ppoNew && ppoNew != 0)
        ppoNew->vt->fn((char *)ppoNew + ppoNew->vt->delta, 1);
}
