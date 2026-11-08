struct EA { float tLocal; int eatyp; int a; int b; };
struct ASEG { char pad[0xA0]; int cea; EA *aea; };
struct ASEGAVT { char pad[8]; short deltaAddRef; short idxAddRef; void (*fnAddRef)(void *); short deltaRelease; short idxRelease; void (*fnRelease)(void *); };
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
// Fast-forward twin of HandleAsegaEvents (src/asega/HandleAsegaEvents.cpp). Retail reads iea and paseg
// through pasega in the forward test, then copies them ($a2, $a3) for the backward test: the source reads
// them once more into scoped locals (scoped so the goto to the shared switch does not cross their
// initialisation). HandleAsegaEvent takes (pasega, pea) only: its disassembly writes $a2/$a3 before reading.
extern "C" void HandleAsegaEventsFF(ASEGB *pasega)
{
    if (pasega->paseg->cea == 0)
        return;
    REF ref(pasega);
    pasega->tTarget = pasega->tLocal;
    while (!FAsegaGone(pasega)) {
        float tTarget = pasega->tTarget;
        EA *pea;
        if (pasega->iea < pasega->paseg->cea) {
            pea = (EA *)(pasega->iea * sizeof(EA) + (unsigned)pasega->paseg->aea);
            if (pea->tLocal <= tTarget && 0.0f <= pasega->svtLocal) {
                pasega->iea = pasega->iea + 1;
                goto dispatch;
            }
        }
        {
            ASEG *paseg = pasega->paseg;
            int iea = pasega->iea;
            if (iea > 0) {
                if (tTarget <= ((EA *)(iea * sizeof(EA) + (unsigned)paseg->aea))[-1].tLocal && pasega->svtLocal < 0.0f) {
                    pasega->iea = iea - 1;
                    pea = (EA *)((unsigned)paseg->aea + (iea - 1) * sizeof(EA));
                    goto dispatch;
                }
            }
        }
        pasega->tLocal = tTarget;
        break;
    dispatch:
        switch (pea->eatyp) {
        case 7: case 8: case 11: case 13: case 14: case 15: case 16:
        case 21: case 22: case 23: case 24:
            HandleAsegaEvent(pasega, pea);
            break;
        }
    }
}
