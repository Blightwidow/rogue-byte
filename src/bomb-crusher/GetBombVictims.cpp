#include "sly2.h"
struct ALLOCREQ { int cb; int cbAlign; };
struct GEOM { int unk0; char *pso; int unk8; int kind; char pad[0x64]; int bsp; };
struct VICTIMS { int cgeom; GEOM **ageom; int cpso; };
extern "C" {
extern char B_003DD490[];
void FFilterOxaBasic();
void IntersectSwBoundingSphere(float, void *, QW, void *, void *, int *, GEOM ***);
void *PvAllocStackImpl__Fi(ALLOCREQ *);
int FIsBasicDerivedFrom(void *, int);
int CsbiIntersectSphereBsp__FP6VECTORfiP3BSPT3P4GEOMiP3SBI(QW, float, GEOM *, int, int, int, int, void *);
void SortUniquePso(void *, int *, void *);
}
extern "C" void GetBombVictims(char *pbomb, int *pcpso, void **papso)
{
    ALLOCREQ req;
    char asbi[0x30];
    VICTIMS v;
    float radius = *(float *)(pbomb + 0x15C);
    float radiusJt = *(float *)(pbomb + 0x160);
    float query = radiusJt < radius ? radius : radiusJt;
    IntersectSwBoundingSphere(query, B_003DD490, *(QW *)(pbomb + 0x180), (void *)FFilterOxaBasic, *(void **)(pbomb + 0xEC), &v.cgeom, &v.ageom);
    if (v.cgeom == 0) {
        *pcpso = 0;
        *papso = 0;
        return;
    }
    req.cb = v.cgeom << 2;
    req.cbAlign = 0x10;
    char **apso = (char **)PvAllocStackImpl__Fi(&req);
    v.cpso = 0;
    for (int igeom = 0; igeom < v.cgeom; igeom++) {
        GEOM *pgeom = v.ageom[igeom];
        char *pso = pgeom->pso;
        void *powner = *(void **)(*(char **)(pso + 0xEC) + 0x60);
        if (pgeom->kind == 1)
            continue;
        if (powner == *(void **)(*(char **)(pbomb + 0xEC) + 0x60))
            continue;
        if (pgeom->bsp != 0) {
            QW pos = *(QW *)(pbomb + 0x180);
            float r = FIsBasicDerivedFrom(powner, 0x34) ? *(float *)(pbomb + 0x160) : *(float *)(pbomb + 0x15C);
            if (CsbiIntersectSphereBsp__FP6VECTORfiP3BSPT3P4GEOMiP3SBI(pos, r, pgeom, 0x7FFFFFFF, 0, 0, 1, asbi) == 0)
                continue;
        }
        apso[v.cpso] = pgeom->pso;
        v.cpso = v.cpso + 1;
    }
    SortUniquePso(pbomb, &v.cpso, apso);
    *pcpso = v.cpso;
    *papso = apso;
}
