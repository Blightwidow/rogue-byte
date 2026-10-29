#include "sly2.h"
struct ROW16 { float v[4]; } __attribute__((aligned(16)));
struct VEntry { short delta; short index; void (*fn)(void *); };
struct XF {
    ROW16 local[4];
    ROW16 world[4];
    XF *pparent;
    char pad0x80[0xA0 - 0x80];
    int generation;
};
struct SO {
    char pad0[0xC];
    VEntry *vptr;
    char pad1[0x5C - 0x10];
    XF *pxfAngular;
};
struct MATLOCALS {
    ROW16 parent[3];
    ROW16 local[3];
    ROW16 inverse[3];
    ROW16 scratch[3];
};
extern "C" {
void NormalizeRotateMatrix3(void *);
void InvertMatrix3(void *, void *);
void DiscardSoXps(SO *);
void WakeXf(SO *, XF *);
void func_001F3900(SO *);
extern char B_003DD490;
}
void RotateSoToMat(SO *pso, ROW16 *pmat)
{
    if (pso->pxfAngular == 0)
        return;
    MATLOCALS locals;
    XF *pxfParent = pso->pxfAngular->pparent;
    if (pxfParent != 0) {
        locals.parent[0] = pxfParent->world[0];
        locals.parent[1] = pxfParent->world[1];
        locals.parent[2] = pxfParent->world[2];
        NormalizeRotateMatrix3(locals.parent);
    } else {
        memset(locals.parent, 0, 0x30);
        locals.parent[0].v[0] = 1.0f;
        locals.parent[1].v[1] = 1.0f;
        locals.parent[2].v[2] = 1.0f;
    }
    InvertMatrix3(locals.inverse, locals.parent);
    asm("lqc2 vf6, 0x20(%0)" : : "r"(pmat));
    asm("lqc2 vf4, 0x0(%0)" : : "r"(pmat));
    asm("lqc2 vf3, %0" : : "m"(locals.inverse[0]));
    asm("lqc2 vf2, %0" : : "m"(locals.inverse[1]));
    asm("lqc2 vf1, %0" : : "m"(locals.inverse[2]));
    asm("lqc2 vf5, 0x10(%0)" : : "r"(pmat));
    asm("vmulax.xyz ACC, vf3, vf4x");
    asm("vmadday.xyz ACC, vf2, vf4y");
    asm("vmaddz.xyz vf4, vf1, vf4z");
    asm("vmulax.xyz ACC, vf3, vf6x");
    asm("vmadday.xyz ACC, vf2, vf6y");
    asm("vmaddz.xyz vf6, vf1, vf6z");
    asm("vmulax.xyz ACC, vf3, vf5x");
    asm("vmadday.xyz ACC, vf2, vf5y");
    asm("vmaddz.xyz vf3, vf1, vf5z");
    asm("sqc2 vf6, %0" : "=m"(locals.local[2]));
    asm("sqc2 vf3, %0" : "=m"(locals.local[1]));
    asm("sqc2 vf4, %0" : "=m"(locals.local[0]));
    asm("sqc2 vf4, %0" : "=m"(locals.scratch[0]));
    asm("sqc2 vf3, %0" : "=m"(locals.scratch[1]));
    asm("sqc2 vf6, %0" : "=m"(locals.scratch[2]));
    asm("sqc2 vf4, %0" : "=m"(pso->pxfAngular->local[0]));
    pso->pxfAngular->local[1] = locals.local[1];
    pso->pxfAngular->local[0].v[3] = 0.0f;
    pso->pxfAngular->local[2] = locals.local[2];
    pso->pxfAngular->local[2].v[3] = 0.0f;
    pso->pxfAngular->local[1].v[3] = 0.0f;
    int *pxfGeneration = (int *)((char *)&B_003DD490 + 0x3D58);
    *pxfGeneration = *pxfGeneration + 1;
    pso->pxfAngular->generation = *pxfGeneration;
    VEntry *entry = &pso->vptr[18];
    entry->fn((char *)pso + entry->delta);
    DiscardSoXps(pso);
    WakeXf(pso, pso->pxfAngular);
    func_001F3900(pso);
}
