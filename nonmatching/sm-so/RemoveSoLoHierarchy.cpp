#include "sly2.h"
struct PHYS { char pad[0xDC]; int unkDC; };
struct CHILD { char pad0[0xC]; struct CVT *vt; char pad1[0x18]; unsigned long grf; };
struct CVT { char pad[0x60]; short d; short i; void (*fn)(void *); };
struct DL { CHILD *pfirst; CHILD *plast; int ibDle; };
struct DLI { DL *pdl; CHILD **ppv; int ibDle; DLI *pdliNext; };
struct SO {
    char pad0[0x64]; CHILD *pchildFirst; char pad1[0x4]; int ibChildDle; char pad2[0xE8 - 0x70]; PHYS *pphys;
    char pad3[0x12C - 0xEC]; float uFade; float duFade;
};
struct UL { unsigned long v; } __attribute__((packed));
extern "C" void RemoveLoHierarchy(SO *);
extern "C" void RemoveSoGeomsFromOxa(SO *);
extern "C" void func_001F37C8(SO *, void *);
extern "C" void CancelSwCallbacks(void *, int, SO *, unsigned long, int);
extern "C" char B_003DD490;
extern "C" const UL RO_002A8270;
extern "C" DLI *g_2dd2fc;

void RemoveSoLoHierarchy(SO *pso)
{
    RemoveLoHierarchy(pso);
    RemoveSoGeomsFromOxa(pso);
    pso->duFade = 0.0f;
    pso->uFade = 1.0f;
    int link = 0;
    if (pso->pphys)
        link = pso->pphys->unkDC;
    if (link) {
        CancelSwCallbacks(&B_003DD490, 3, pso, RO_002A8270.v, 0);
        func_001F37C8(pso, 0);
    }
    DL *pdl = (DL *)&pso->pchildFirst;
    DLI dli;
    dli.ppv = (CHILD **)pdl;
    dli.pdl = pdl;
    asm volatile("");
    DLI *pdliNext = g_2dd2fc;
    int ibDle = pdl->ibDle;
    g_2dd2fc = &dli;
    dli.pdliNext = pdliNext;
    asm volatile("");
    CHILD *pchild = pdl->pfirst;
    dli.ibDle = ibDle;
    dli.ppv = (CHILD **)((short *)pchild + ibDle);
    if (pchild && !(pchild->grf & (0x8000UL << 41))) {
        for (;;) {
            pchild->vt->fn((char *)pchild + pchild->vt->d);
            pchild = *dli.ppv;
            dli.ppv = (CHILD **)((short *)pchild + dli.ibDle);
            if (!pchild || (pchild->grf & (0x8000UL << 41)))
                break;
        }
    }
    g_2dd2fc = dli.pdliNext;
}
