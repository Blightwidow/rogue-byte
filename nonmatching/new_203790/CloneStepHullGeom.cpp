#include "types.h"
#include "ps2inline.h"
#include "vu0inline.h"

struct VECTOR { float x, y, z, w; };
struct XFPART { char pad[0x40]; };
struct HULLGEOM {
    XFPART *pxf;
    char pad4[0x18];
    int cvec;
    char pad20[0x78 - 0x20];
    int field78;
    QW *avec;
    char pad80[0x10];
    int field90;
    int *pindex;
};
struct HULLSTEP {
    char pad0[0x28];
    u64 grfo;
    char pad30[0xE0 - 0x30];
    int cgeom;
    HULLGEOM *ageom;
    char padE8[0x60 - 0x0];
    char pad148[0x210 - 0x148];
    float gMin;
    float gValue;
    int *pindexA;
    int *pindexB;
    char pad220[0x240 - 0x220];
    QW qPos;
    char pad250[0x258 - 0x250];
    HULLGEOM *pgeom;
};
union VU_SCALE { QW q; float g; };
static inline QW AddScaled(QW base, QW direction, u32 word)
{
    VU_SCALE scale;
    scale.q = VectorFromWord(word);
    return ScaleAddX(base, direction, scale.q);
}

extern "C" {
void RemoveSoGeomsFromOxa(HULLSTEP *);
void AddSoGeomsToOxa(HULLSTEP *);
int FIsBasicDerivedFrom(HULLSTEP *, int);
void CloneCloth(HULLGEOM *, void *, int, HULLGEOM *);
void EnsureSogeomLvo(HULLGEOM *);
void TransformGeom(void *, void *, void *);
}
extern QW g_2a2dc0;
extern QW g_2a2dd0;

extern "C" void CloneStepHullGeom(HULLSTEP *pstep, HULLGEOM *pgeomSource)
{
    if ((int)(pstep->grfo >> 60) & 1)
        RemoveSoGeomsFromOxa(pstep);
    int index = pstep->cgeom;
    int fExtra = 0;
    pstep->cgeom = index + 1;
    pstep->pgeom = (HULLGEOM *)((char *)pstep->ageom + index * 0xB0);
    if (!FIsBasicDerivedFrom(pstep, 0x34))
        fExtra = pgeomSource->cvec == pgeomSource->field78;
    CloneCloth(pgeomSource, *(void **)((char *)pstep + 0x60), fExtra == 0 ? 2 : 3, pstep->pgeom);
    EnsureSogeomLvo(pstep->pgeom);
    HULLGEOM *pgeom = pstep->pgeom;
    float gMin = 3.4028235e38f;
    for (int ivec = 0; ivec < pgeom->cvec; ivec++) {
        VECTOR *pvector = (VECTOR *)pgeom->avec + ivec;
        gMin = gMin < pvector->z ? gMin : pvector->z;
    }
    pstep->gMin = gMin;
    int cvec = pstep->pgeom->cvec;
    int offset = cvec * 0x10;
    pstep->pgeom->cvec = cvec + 2;
    *(QW *)((char *)pstep->pgeom->avec + offset) = pstep->qPos;
    *(QW *)((char *)pstep->pgeom->avec + offset + 0x10) = AddScaled(pstep->qPos, g_2a2dc0, *(u32 *)&pstep->gValue);
    if (fExtra)
        *(QW *)((char *)pstep->pgeom->avec + offset + 0x20) = g_2a2dd0;
    TransformGeom(pstep->pgeom->pxf + 1, &pstep->pgeom->field78, &pstep->pgeom->field90);
    pstep->pindexA = (int *)((char *)pstep->pgeom->pindex + offset);
    pstep->pindexB = (int *)((char *)pstep->pgeom->pindex + offset + 0x10);
    if ((int)(pstep->grfo >> 60) & 1)
        AddSoGeomsToOxa(pstep);
}
