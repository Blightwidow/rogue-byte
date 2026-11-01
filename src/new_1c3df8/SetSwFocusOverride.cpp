struct VT { char pad[0x270]; short delta; short idx; void (*fn)(void *, int); };
struct PO { char pad[0xC]; VT *vt; };
struct SW { char pad[0x3EFC]; PO *base; PO *over; };
extern "C" PO *PpoSwFocus(SW *);

void SetSwFocusOverride(SW *psw, PO *ppo)
{
    PO *ppoOld = PpoSwFocus(psw);
    PO *ppoNew = ppo;
    if (ppoNew == 0)
        ppoNew = psw->base;
    if (ppoOld != ppoNew && ppoOld != 0)
        ppoOld->vt->fn((char *)ppoOld + ppoOld->vt->delta, 0);
    psw->over = ppo;
    if (ppoOld != ppoNew && ppoNew != 0)
        ppoNew->vt->fn((char *)ppoNew + ppoNew->vt->delta, 1);
}
