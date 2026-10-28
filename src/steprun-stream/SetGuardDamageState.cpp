typedef int QW __attribute__((mode(TI)));
struct SRC { char pad[0x184]; int ndamage; int grftak; };
struct VT { char pad[0x108]; short delta; short idx; QW (*fn)(void *); };
struct OBJ { char pad[0xC]; VT *vt; };
struct WATCH { OBJ *guard; int state; float t; SRC *src; };
struct WKR { SRC *src; int u4; void *target; int grftak; int ndamage; char pad[0xC]; QW pos; QW vel; char pad2[0x20]; };
extern "C" { struct CK { float t; }; extern CK g_2dded0; void *memset(void *, int, unsigned); QW PosLoWorld(void *); void PaloAbsorbWkr(void *); }
void SetGuardDamageState(WATCH *pwatch, int state)
{
    if (state == pwatch->state)
        return;
    pwatch->state = state;
    pwatch->t = g_2dded0.t;
    if (state != 2)
        return;
    WKR wkr;
    memset(&wkr, 0, 0x60);
    SRC *src = pwatch->src;
    wkr.src = src;
    wkr.target = pwatch->guard;
    wkr.grftak = src->grftak;
    wkr.ndamage = src->ndamage;
    wkr.pos = PosLoWorld(pwatch->guard);
    wkr.vel = pwatch->guard->vt->fn((char *)pwatch->guard + pwatch->guard->vt->delta);
    PaloAbsorbWkr(&wkr);
}
