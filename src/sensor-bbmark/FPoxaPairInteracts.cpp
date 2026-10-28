struct SOVT { char pad[0x1E8]; short delta; short idx; int (*fn)(void *, void *); };
struct SO { char pad[0xC]; SOVT *vt; };
struct POXA { float aMin[3]; float pad0; float aMax[3]; char pad1[0x44]; SO *pso; };
extern "C" int IMax(int, int);

extern "C" int FPoxaPairInteracts(void *psw, POXA *poxa, POXA *poxaOther)
{
    if (poxa->aMin[0] >= poxaOther->aMax[0]) return 0;
    if (poxa->aMin[1] >= poxaOther->aMax[1]) return 0;
    if (poxa->aMin[2] >= poxaOther->aMax[2]) return 0;
    if (poxaOther->aMin[0] >= poxa->aMax[0]) return 0;
    if (poxaOther->aMin[1] >= poxa->aMax[1]) return 0;
    if (poxaOther->aMin[2] >= poxa->aMax[2]) return 0;
    int nIgnore = poxa->pso->vt->fn((char *)poxa->pso + poxa->pso->vt->delta, poxaOther->pso);
    int nIgnoreOther = poxaOther->pso->vt->fn((char *)poxaOther->pso + poxaOther->pso->vt->delta, poxa->pso);
    int nMax = IMax(nIgnore, nIgnoreOther);
    return nMax != 1 && nMax != 3;
}
