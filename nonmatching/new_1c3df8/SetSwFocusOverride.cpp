struct VT { char pad[0x270]; short delta; short idx; void (*fn)(void *, int); };
struct PO { char pad[0xC]; VT *vt; };
struct SW { char pad[0x3EFC]; PO *base; PO *over; };
extern "C" PO *PpoSwFocus(SW *);
static inline void Notify(PO *po, int f) { po->vt->fn((char *)po + po->vt->delta, f); }

void SetSwFocusOverride(SW *psw, PO *ppo)
{
    PO *ppoOld = PpoSwFocus(psw);
    PO *ppoNew = ppo;
    if (ppoNew == 0)
        ppoNew = psw->base;
    if (ppoOld != ppoNew) {
        if (ppoOld != 0)
            Notify(ppoOld, 0);
    }
    if (ppoOld != ppoNew) {
        psw->over = ppo;
        if (ppoNew != 0)
            Notify(ppoNew, 1);
    } else
        psw->over = ppo;
}
