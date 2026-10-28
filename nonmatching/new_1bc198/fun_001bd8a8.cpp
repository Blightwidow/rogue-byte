#include "sly2.h"
struct VEntry { short delta; short index; void *(*fn)(void *); };
struct ROW16 { float v[4]; } __attribute__((aligned(16)));
struct OBSTACLE {
    char pad0[0xC];
    VEntry *vptr;
    char pad1[0xE8 - 0x10];
    int cposObstacle;
    char pad2[0xF4 - 0xEC];
    VECTOR *aposObstacle;
};
extern "C" {
int ClsgClipEdgeToObstacle(OBSTACLE *, QW, QW, int, void *);
int FObstacleContainsPos(OBSTACLE *, QW);
}
int FObstaclesOverlap(OBSTACLE *pobstacleA, OBSTACLE *pobstacleB)
{
    struct Locals {
        ROW16 mat[4];
        char alsg[0x60];
    } locals;
    VEntry *entry = &pobstacleA->vptr[31];
    MATRIX4 *pmatA = (MATRIX4 *)entry->fn((char *)pobstacleA + entry->delta);
    asm("lqc2 vf5, 0x0(%0)" : : "r"(pmatA));
    asm("sqc2 vf5, %0" : "=m"(locals.mat[0]));
    asm("lqc2 vf4, 0x10(%0)" : : "r"(pmatA));
    asm("sqc2 vf4, %0" : "=m"(locals.mat[1]));
    asm("lqc2 vf3, 0x20(%0)" : : "r"(pmatA));
    asm("sqc2 vf3, %0" : "=m"(locals.mat[2]));
    asm("lqc2 vf2, 0x30(%0)" : : "r"(pmatA));
    asm("sqc2 vf2, %0" : "=m"(locals.mat[3]));
    asm("lqc2 vf1, %0" : : "m"(pobstacleA->aposObstacle[0]));
    asm("vmulax.xyz ACC, vf5, vf1x");
    asm("vmadday.xyz ACC, vf4, vf1y");
    asm("vmaddaz.xyz ACC, vf3, vf1z");
    asm("vmaddw.xyz vf1, vf2, vf0w");
    if (pobstacleA->cposObstacle > 1) {
        int ipos = 1;
        for (;;) {
            QW posPrev;
            QW pos;
            asm("qmfc2.ni %0, vf1" : "=r"(posPrev));
            asm("lqc2 vf5, %0" : : "m"(locals.mat[0]));
            asm("lqc2 vf3, %0" : : "m"(pobstacleA->aposObstacle[ipos]));
            asm("lqc2 vf4, %0" : : "m"(locals.mat[1]));
            asm("lqc2 vf2, %0" : : "m"(locals.mat[2]));
            asm("lqc2 vf1, %0" : : "m"(locals.mat[3]));
            asm("vmulax.xyz ACC, vf5, vf3x");
            asm("vmadday.xyz ACC, vf4, vf3y");
            asm("vmaddaz.xyz ACC, vf2, vf3z");
            asm("vmaddw.xyz vf1, vf1, vf0w");
            asm("qmfc2.ni %0, vf1" : "=r"(pos));
            int clsg = ClsgClipEdgeToObstacle(pobstacleB, posPrev, pos, 1, locals.alsg);
            asm("qmtc2.ni %0, vf1" : : "r"(pos));
            if (clsg != 0)
                break;
            ipos++;
            if (pobstacleA->cposObstacle <= ipos)
                break;
        }
        if (ipos < pobstacleA->cposObstacle)
            return 1;
    }
    VEntry *entryB = &pobstacleB->vptr[31];
    MATRIX4 *pmatB = (MATRIX4 *)entryB->fn((char *)pobstacleB + entryB->delta);
    QW posB;
    asm("lqc2 vf5, 0x30(%0)" : : "r"(pmatB));
    asm("lqc2 vf4, %0" : : "m"(pobstacleB->aposObstacle[0]));
    asm("lqc2 vf3, 0x0(%0)" : : "r"(pmatB));
    asm("lqc2 vf2, 0x10(%0)" : : "r"(pmatB));
    asm("lqc2 vf1, 0x20(%0)" : : "r"(pmatB));
    asm("vmulax.xyz ACC, vf3, vf4x");
    asm("vmadday.xyz ACC, vf2, vf4y");
    asm("vmaddaz.xyz ACC, vf1, vf4z");
    asm("vmaddw.xyz vf6, vf5, vf0w");
    asm("qmfc2.ni %0, vf6" : "=r"(posB));
    return FObstacleContainsPos(pobstacleA, posB) != 0;
}
