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
        int iea = pasega->iea;
        float tTarget = pasega->tTarget;
        float svtLocal = pasega->svtLocal;
        bool fForward = false;
        if (iea < paseg->cea) {
            float tEvent = paseg->aea[iea].tLocal;
            fForward = tEvent < tTarget || (tTarget == tEvent && zero < svtLocal);
        }
        if (fForward) {
            pasega->iea = iea + 1;
            HandleAsegaEvent(pasega, &paseg->aea[iea]);
            continue;
        }
        if (iea > 0) {
            float tPrev = paseg->aea[iea - 1].tLocal;
            if (tTarget < tPrev || (tTarget == tPrev && svtLocal < zero)) {
                pasega->iea = iea - 1;
                HandleAsegaEvent(pasega, &paseg->aea[iea - 1]);
                continue;
            }
        }
        pasega->tLocal = tTarget;
        break;
    }
}
