struct EA { float tLocal; int eatyp; int a; int b; };
struct ASEG { char pad[0xA0]; int cea; EA *aea; };
struct ASEGAVT { char pad[8]; short deltaAddRef; short idxAddRef; void (*fnAddRef)(void *); short deltaRelease; short idxRelease; void (*fnRelease)(void *); };
struct ASEGA {
    char pad0[0xC]; ASEGAVT *vt; ASEG *paseg_dummy_unused;
};
struct ASEGB {
    char pad0[0xC]; ASEGAVT *vt; int pad1; ASEG *paseg; char pad2[4]; float tLocal; float tTarget; char pad3[0x1C];
    float svtLocal; char pad4[0xC]; int iea;
};
extern "C" int FAsegaGone(ASEGB *);
extern "C" void HandleAsegaEvent(ASEGB *, EA *);

struct REF {
    ASEGB *p;
    REF(ASEGB *q) { p = q; p->vt->fnAddRef((char *)p + p->vt->deltaAddRef); }
    ~REF() { p->vt->fnRelease((char *)p + p->vt->deltaRelease); }
};
extern "C" void HandleAsegaEvents(ASEGB *pasega)
{
    if (pasega->paseg->cea == 0)
        return;
    REF ref(pasega);
    float zero = 0.0f;
    pasega->tTarget = pasega->tLocal;
    while (!FAsegaGone(pasega)) {
        ASEG *paseg = pasega->paseg;
        if (pasega->iea < paseg->cea) {
            EA *pea = (__typeof__(&(paseg->aea)[0]))((pasega->iea) * sizeof((paseg->aea)[0]) + (unsigned)(paseg->aea));
            float tEvent = pea->tLocal;
            if (tEvent < pasega->tTarget || (pasega->tTarget == tEvent && zero < pasega->svtLocal)) {
                pasega->iea = pasega->iea + 1;
                HandleAsegaEvent(pasega, pea);
                continue;
            }
        }
        if (pasega->iea > 0) {
            float tPrev = paseg->aea[pasega->iea - 1].tLocal;
            if (pasega->tTarget < tPrev || (pasega->tTarget == tPrev && pasega->svtLocal < zero)) {
                pasega->iea = pasega->iea - 1;
                HandleAsegaEvent(pasega, &paseg->aea[pasega->iea - 1]);
                continue;
            }
        }
        pasega->tLocal = pasega->tTarget;
        break;
    }
}
