#include "sly2.h"
struct CRV {
    char pad0[0xC];
    char *vtable;
    char pad1[0xE0 - 0x10];
    int mode;
    char pad2[4];
    int count;
    char pad3[4];
    float *table;
    QW *points;
    char pad4[4];
    QW mat[4];
    char pad5[0x174 - 0x140];
    float extra;
    char pad6[4];
    int rope;
};
extern "C" {
void InvalidateCrvCache(void);
void FillCrvcCache(CRV *, int);
void RemeasureRopeSim(int);
}
typedef QW *(*GetMatFn)(void *);
void MeasureCrv(CRV *self)
{
    InvalidateCrvCache();
    char *vtable = self->vtable;
    QW *src = ((GetMatFn)*(void **)(vtable + 0xFC))((char *)self + *(short *)(vtable + 0xF8));
    int fenceRow0;
    asm("lqc2 vf5, %1" : "=r"(fenceRow0) : "m"(*src));
    int mode = self->mode;
    asm("sqc2 vf5, %0" : "=m"(self->mat[0]) : "r"(fenceRow0));
    self->mat[1] = src[1];
    self->mat[2] = src[2];
    self->mat[3] = src[3];
    if (mode == 0) {
        int fenceFirst;
        QW *points = self->points;
        float length = 0.0f;
        asm("lqc2 vf4, %1\n\tlqc2 vf3, %2\n\tlqc2 vf2, %3\n\tlqc2 vf1, %4\n\tvmulax.xyz ACC, vf5, vf4x\n\tvmadday.xyz ACC, vf3, vf4y\n\tvmaddaz.xyz ACC, vf2, vf4z\n\tvmaddw.xyz vf6, vf1, vf0w" : "=r"(fenceFirst) : "m"(points[0]), "m"(self->mat[1]), "m"(self->mat[2]), "m"(self->mat[3]), "r"(fenceRow0));
        self->table[0] = 0.0f;
        for (int index = 1; index < self->count; index++) {
            float distance;
            int bits;
            int fenceLoop;
            asm("lqc2 vf2, %2\n\tlqc2 vf1, %3\n\tlqc2 vf4, %4\n\tlqc2 vf3, %5\n\tlqc2 vf5, %6\n\tvmulax.xyz ACC, vf3, vf4x\n\tvmadday.xyz ACC, vf5, vf4y\n\tvmaddaz.xyz ACC, vf2, vf4z\n\tvmaddw.xyz vf3, vf1, vf0w\n\tvsub.xyzw vf1, vf6, vf3\n\tvmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tvmove.xyzw vf6, vf3\n\tqmfc2.ni %0, vf1" : "=r"(bits), "=r"(fenceLoop) : "m"(self->mat[2]), "m"(self->mat[3]), "m"(self->points[index]), "m"(self->mat[0]), "m"(self->mat[1]), "r"(fenceFirst));
            asm("mtc1 %1, %0" : "=f"(distance) : "r"(bits));
            length += distance;
            self->table[index] = length;
        }
    } else {
        self->table[0] = 0.0f;
        for (int index = 0; index < self->count - 1; index++) {
            FillCrvcCache(self, index);
            self->table[index + 1] = self->table[index] + self->extra;
        }
    }
    if (self->rope != 0)
        RemeasureRopeSim(self->rope);
}
