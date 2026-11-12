#include "sly2.h"
#include "vu0inline.h"

struct VT {
    char pad[0x18];
    short delta;
    short index;
    void (*fn)(void *, float, float, QW *, int);
};
struct CHN { int unk0; void **panim; };
struct ASEG { char pad[0x74]; float duration; };
struct BLENTRY { int unk0; ASEG *paseg; int unk8; int unkC; QW qVelocity; char pad[0x20]; };
struct TARGET { int unk0; int unk4; int dw; };
struct ABLE { int iKey; TARGET *ptarget; };
struct ASEGBLX { char pad[0x5C]; int cable; ABLE *pable; char pad2[0x6C]; int dwBase; };
struct BLRUNX { void *powner; ASEGBLX *pasegbl; int unk8; int unkC; BLENTRY aent[2]; };
union VU_SCALE2 { QW q; VECTOR v; };

extern "C" {
void FillBlAmrsg__FiiPviiP3OID(int, int, void *, int, int, const void *);
CHN *PchnFindAseg(ASEG *, void *, int, int);
void EnsureAsegBlendDynamic(void *, int, int, void *, int, const void *, const void *, void *);
void BindAsegChn(ASEGBLX *, void *, ABLE *, void *, void *);
void ReblendAsegbl(ASEGBLX *);
}
extern char D_002C3DC0[], D_002C3DC8[], D_002C3DD0[], D_002C3DD8[];

static inline void ScaleVelocity(QW *pqOut, QW qEnd, QW qStart, ASEG *paseg, union VU_SCALE2 *pscale)
{
    pscale->q = VectorFromWord(*(u32 *)&paseg->duration);
    *pqOut = ScaleByReciprocalX(VectorSub(qEnd, qStart), pscale->q);
}

struct BIND { int unk0; ASEGBLX *pbound; };

void PostStepLoadRun__FP4STEPP5BLRUNPP6ASEGBL(BLRUNX *prun)
{
    QW aq[2];
    union VU_SCALE2 scale;
    BIND bind;
    if (prun->aent[0].paseg == 0)
        return;
    ASEGBLX **ppasegbl = &prun->pasegbl;
    void *pvFill = prun->aent;
    FillBlAmrsg__FiiPviiP3OID(0x40, 2, pvFill, 0x20, 2, D_002C3DC0);
    BLENTRY *pentFirst = prun->aent;
    FillBlAmrsg__FiiPviiP3OID(0x40, 2, pvFill, 0x30, 2, D_002C3DC8);
    BLENTRY *pentLoop = pentFirst;
    u32 iEntry = 0;
    do {
        ASEG *paseg = pentLoop->paseg;
        if (paseg != 0) {
            CHN *pchn = PchnFindAseg(paseg, prun->powner, 1, 1);
            VT *vt = *(VT **)pchn->panim;
            vt->fn((char *)pchn->panim + vt->delta, 0.0f, 1.0f, &aq[0], 0);
            VT *vt2 = *(VT **)pchn->panim;
            vt2->fn((char *)pchn->panim + vt2->delta, paseg->duration, 1.0f, &aq[1], 0);
            ScaleVelocity(&pentLoop->qVelocity, aq[1], aq[0], paseg, &scale);
        }
        iEntry++;
        pentLoop++;
    } while (iEntry < 2);
    EnsureAsegBlendDynamic(prun->powner, 0x40, 2, pentFirst, 2, D_002C3DD8, D_002C3DD0, ppasegbl);
    for (int iable = 0; iable < prun->pasegbl->cable; iable++) {
        ABLE *pable = &prun->pasegbl->pable[iable];
        TARGET *ptargetA;
        TARGET *ptargetB;
        if (pable->iKey < 0) {
            ptargetA = 0;
            ptargetB = pable->ptarget;
        } else {
            ptargetA = pable->ptarget;
            ptargetB = 0;
        }
        BindAsegChn(prun->pasegbl, prun->powner, pable, &bind, &bind.pbound);
        switch (*(int *)((char *)bind.pbound + 0x9C)) {
        case 16:
        case 18:
        case 20:
            if (ptargetA != 0)
                ptargetA->dw = prun->pasegbl->dwBase + 0xC;
            if (ptargetB != 0)
                ptargetB->dw = prun->pasegbl->dwBase + 0xC;
            break;
        case 17:
        case 19:
        case 21:
            break;
        default:
            if (ptargetA != 0)
                ptargetA->dw = 0;
            if (ptargetB != 0)
                ptargetB->dw = 0;
            break;
        }
    }
    ReblendAsegbl(prun->pasegbl);
}
