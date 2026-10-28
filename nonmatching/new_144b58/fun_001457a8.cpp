#include "sly2.h"
extern "C" {
QW PosLoWorld(void *);
void *PmatLoWorld(void *);
int FIsBasicDerivedFrom(void *, int);
void LoadRotateMatrixRad(void *, QW, float);
void MeasureCrv(void *);
void *GoalPartnerFollow_PpathzoneTarget(void *);
int FFindPathzoneCrv(void *, QW, QW, void *);
void GoalFollowCrv_SetCrv(void *, void *, int);
extern QW g_2a2dc0;
}
struct VT { char pad[0x108]; short delta; short index; QW (*fn)(void *); };
struct Rows3 { QW r[3]; };
struct Frame { union { QW rows[3]; Rows3 rows3; }; QW pos; QW v40; QW v50; QW v60; QW v70; QW v80; };
void func_001457A8(char *self)
{
    Frame f;
    *(QW *)(self + 0x50) = PosLoWorld(*(void **)(self + 0x30));
    if (FIsBasicDerivedFrom(*(void **)(self + 0x30), 0x33)) {
        char *leader = *(char **)(self + 0x30);
        LoadRotateMatrixRad(&f.v40, g_2a2dc0, *(float *)(leader + 0x1A8));
        float neg = *(float *)(self + 0x68);
        int bits;
        asm volatile("lqc2 vf6, %2\n\tneg.s %1, %1\n\tlqc2 vf5, %3\n\tlqc2 vf3, %4\n\tsqc2 vf6, %5\n\tmfc1 %0, %1\n\tqmtc2.ni %0, vf4\n\tsqc2 vf5, %6\n\tsqc2 vf3, %7\n\tsqc2 vf4, %2" : "=&r" (bits), "+f" (neg), "+m" (f.v40) : "m" (f.v50), "m" (f.v60), "m" (f.rows[0]), "m" (f.rows[1]), "m" (f.rows[2]));
        asm volatile("lqc2 vf1, %0\n\tlqc2 vf2, %1\n\tvmulax.xyz ACC, vf6, vf1x\n\tvmadday.xyz ACC, vf5, vf1y\n\tvmaddz.xyz vf1, vf3, vf1z\n\tvadda.xyzw ACC, vf0, vf2\n\tvmaddx.xyzw vf2, vf1, vf4x\n\tsqc2 vf2, %2" : : "m" (*(QW *)(leader + 0x190)), "m" (*(QW *)(self + 0x50)), "m" (f.pos));
    } else {
        char *mat = (char *)PmatLoWorld(*(void **)(self + 0x30));
        char *leader = *(char **)(self + 0x30);
        f.rows[0] = *(QW *)mat;
        f.v70 = *(QW *)(self + 0x50);
        f.rows[1] = *(QW *)(mat + 0x10);
        f.rows[2] = *(QW *)(mat + 0x20);
        asm("sq %1, %0" : "=m" (f.v80) : "r" (*(int *)(self + 0x68)));
        f.v40 = f.v80;
        VT *vt = *(VT **)(leader + 0xC);
        QW r = vt->fn(leader + vt->delta);
        int dummy;
        asm volatile("lqc2 vf2, %1\n\tlqc2 vf3, %2\n\tqmtc2.ni %3, vf4\n\tvadda.xyzw ACC, vf0, vf2\n\tvmaddx.xyzw vf1, vf4, vf3x\n\tsqc2 vf1, %4" : "=r" (dummy) : "m" (f.v70), "m" (f.v80), "r" (r), "m" (f.pos));
    }
    asm("lqc2 vf3, %0" : : "m" (*(QW *)(self + 0x40)));
    asm("lqc2 vf5, %0\n\tlqc2 vf4, %1\n\tlqc2 vf2, %2\n\tlqc2 vf1, %3\n\tvmulax.xyz ACC, vf5, vf3x\n\tvmadday.xyz ACC, vf4, vf3y\n\tvmaddz.xyz vf3, vf2, vf3z" : : "m" (f.rows[0]), "m" (f.rows[1]), "m" (f.rows[2]), "m" (f.pos));
    char *owner = *(char **)(self + 0x10);
    asm("vadd.xyzw vf1, vf1, vf3\n\tsqc2 vf1, %0" : "=m" (f.pos));
    char *crv = *(char **)(owner + 0x294);
    char *zoneHolder = *(char **)(owner + 0xE8);
    char *zone = 0;
    if (zoneHolder)
        zone = *(char **)(zoneHolder + 0xDC);
    char *path = 0;
    if (zone)
        path = *(char **)(zone + 0x10);
    QW posOwner = PosLoWorld(owner);
    if (!path) {
        *(int *)(crv + 0xE8) = 2;
        char *nodes = *(char **)(crv + 0xF4);
        *(QW *)nodes = posOwner;
        *(QW *)(*(char **)(crv + 0xF4) + 0x10) = f.pos;
        MeasureCrv(crv);
    } else if (GoalPartnerFollow_PpathzoneTarget(self) != path) {
        FFindPathzoneCrv(path, posOwner, posOwner, crv);
    } else {
        if (!FFindPathzoneCrv(path, posOwner, f.pos, crv))
            FFindPathzoneCrv(path, posOwner, posOwner, crv);
    }
    GoalFollowCrv_SetCrv(*(void **)(self + 0x18), crv, 0);
}
