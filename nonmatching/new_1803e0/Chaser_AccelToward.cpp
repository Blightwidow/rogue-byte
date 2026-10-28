#include "sly2.h"
struct M3 { QW row[3]; };
struct VT { char pad[0x108]; short d108; short i10A; QW (*f10C)(void *); };
struct Chaser { char pad0[0xC]; VT *vt; char pad1[0x5C - 0x10]; char *pxf; char pad2[0x1C0 - 0x60]; int state; char pad3[0x204 - 0x1C4]; float radYaw;
  char pad4[0x210 - 0x208]; QW vecVelocity; char pad5[0x378 - 0x220]; char smp[0xC]; float gSpeed; };
extern "C" QW g_2a2dc0;
extern "C" void LoadRotateMatrixRad(M3 *, float, QW);
extern "C" void ConvertXfMat(M3 *, void *, void *, M3 *);
extern "C" void AccelSoTowardMatSmooth__FP2SOfP7MATRIX3P3SMP(Chaser *, M3 *, void *);
extern "C" void AddSoAcceleration(Chaser *, QW);
extern "C" void Chaser_AccelToward(Chaser *chaser)
{
    M3 copy;
    M3 mat;
    if (chaser->state != 4) {
        LoadRotateMatrixRad(&mat, chaser->radYaw, g_2a2dc0);
        copy = mat;
        if (chaser->state != 3) {
            ConvertXfMat(&mat, *(void **)(chaser->pxf + 0xA0), 0, &copy);
            copy = mat;
        }
        AccelSoTowardMatSmooth__FP2SOfP7MATRIX3P3SMP(chaser, &copy, chaser->smp);
    }
    if (chaser->state == 3) {
        QW vecGoal = chaser->vecVelocity;
        VT *vt = chaser->vt;
        asm volatile("");
        QW (*fn)(void *) = vt->f10C;
        QW vecCurrent = fn((char *)chaser + vt->d108);
        QW diff;
        asm("qmtc2.ni %0, vf3" : : "r" (vecCurrent));
        asm("lqc2 vf1, %0" : : "m" (vecGoal));
        asm("vsub.xyzw vf2, vf1, vf3");
        int bits = *(int *)((char *)chaser + 0x384);
        asm("qmtc2.ni %0, vf1" : : "r" (bits));
        asm("vmulx.xyzw vf3, vf2, vf1x");
        asm("sqc2 vf1, %0" : "=m" (copy.row[0]));
        asm("qmfc2.ni %0, vf3" : "=r" (diff));
        AddSoAcceleration(chaser, diff);
    }
}
