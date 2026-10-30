#include "sly2.h"
struct VEntry { short delta; short index; void *(*fn)(void *); };
struct ALLOCREQ { int size; int align; };
struct ROW16 { float v[4]; } __attribute__((aligned(16)));
struct OBSTACLE {
    char pad0[0xC];
    VEntry *vptr;
    char pad1[0xE8 - 0x10];
    int cposObstacle;
    char pad2[0xF4 - 0xEC];
    VECTOR *aposObstacle;
    char pad3[0x1A0 - 0xF8];
    VECTOR posMin;
    VECTOR posMax;
};
extern "C" {
void CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void *PvAllocStackImpl__Fi(void);
QW PosLoWorld(OBSTACLE *);
void *PpathzoneFindPos(QW, int);
void AddPathzoneObstacle(void *, OBSTACLE *);
extern const float RO_002A76D0;
extern const float RO_002A76D4;
}
void Obstacle_AddToPathzone(OBSTACLE *pobstacle)
{
    struct Locals {
        char frame[0x10];
        ALLOCREQ req;
        ROW16 mat[4];
    } locals;
    CStackFrame_Construct(locals.frame);
    locals.req.align = 0x10;
    locals.req.size = pobstacle->cposObstacle * 0x10 - 1;
    VECTOR *aposWorld = (VECTOR *)PvAllocStackImpl__Fi();
    VEntry *entry = &pobstacle->vptr[31];
    MATRIX4 *pmatWorld = (MATRIX4 *)entry->fn((char *)pobstacle + entry->delta);
    asm("lqc2 vf2, 0x0(%0)" : : "r"(pmatWorld));
    asm("sqc2 vf2, %0" : "=m"(locals.mat[0]));
    asm("lqc2 vf5, 0x10(%0)" : : "r"(pmatWorld));
    asm("sqc2 vf5, %0" : "=m"(locals.mat[1]));
    asm("lqc2 vf4, 0x20(%0)" : : "r"(pmatWorld));
    asm("sqc2 vf4, %0" : "=m"(locals.mat[2]));
    asm("lqc2 vf3, 0x30(%0)" : : "r"(pmatWorld));
    asm("sqc2 vf3, %0" : "=m"(locals.mat[3]));
    asm("lqc2 vf1, %0" : : "m"(pobstacle->aposObstacle[0]));
    asm("vmulax.xyz ACC, vf2, vf1x");
    asm("vmadday.xyz ACC, vf5, vf1y");
    asm("vmaddaz.xyz ACC, vf4, vf1z");
    asm("vmaddw.xyz vf2, vf3, vf0w");
    asm("sqc2 vf2, %0" : "=m"(pobstacle->posMin));
    asm("sqc2 vf2, %0" : "=m"(pobstacle->posMax));
    asm("sqc2 vf2, %0" : "=m"(aposWorld[0]));
    aposWorld[pobstacle->cposObstacle - 1] = pobstacle->posMin;
    for (int ipos = 1; ipos < pobstacle->cposObstacle - 1; ipos++) {
        asm("lqc2 vf1, %0" : : "m"(locals.mat[3]));
        asm("lqc2 vf5, %0" : : "m"(locals.mat[0]));
        asm("lqc2 vf4, %0" : : "m"(pobstacle->aposObstacle[ipos]));
        asm("lqc2 vf6, %0" : : "m"(locals.mat[1]));
        asm("lqc2 vf3, %0" : : "m"(locals.mat[2]));
        asm("vmulax.xyz ACC, vf5, vf4x");
        asm("vmadday.xyz ACC, vf6, vf4y");
        asm("vmaddaz.xyz ACC, vf3, vf4z");
        asm("vmaddw.xyz vf5, vf1, vf0w");
        asm("lqc2 vf2, %0" : : "m"(pobstacle->posMin));
        asm("lqc2 vf1, %0" : : "m"(pobstacle->posMax));
        asm("vmini.xyz vf2, vf2, vf5");
        asm("vmax.xyz vf1, vf1, vf5");
        asm("sqc2 vf2, %0" : "=m"(pobstacle->posMin));
        asm("sqc2 vf1, %0" : "=m"(pobstacle->posMax));
        asm("sqc2 vf5, %0" : "=m"(aposWorld[ipos]));
    }
    pobstacle->posMin.z = RO_002A76D0;
    pobstacle->posMax.z = RO_002A76D4;
    QW posWorld = PosLoWorld(pobstacle);
    void *ppathzone = PpathzoneFindPos(posWorld, 0);
    if (ppathzone != 0) {
        AddPathzoneObstacle(ppathzone, pobstacle);
    }
    CStackFrame_Destructor(locals.frame, 2);
}
