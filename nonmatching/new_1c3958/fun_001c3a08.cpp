#include "sly2.h"
struct Frame1C3A08 { QW mat[3]; QW pos; QW scale; };
extern int g_2c0d04;
extern "C" {
void GetJtPipeGoalMat__FP2JTP4PIPEfP7MATRIX3(void *, int, float, void *);
void GetPathPosFromS(void *, QW *, int, float);
void func_001C3A08(void *jt, int unused, QW *out, float s)
{
    Frame1C3A08 frame;
    GetJtPipeGoalMat__FP2JTP4PIPEfP7MATRIX3(jt, 1, s, &frame);
    GetPathPosFromS(jt, &frame.pos, 0, s);
    if (out != 0) {
        int fence;
        int fence2;
        int fence3;
        asm("lqc2 vf2, %1" : "=r"(fence) : "m"(frame.pos));
        asm("qmtc2.ni %1, vf3" : "=r"(fence2) : "r"(g_2c0d04), "r"(fence));
        asm("lqc2 vf1, %1\n\tvadda.xyzw ACC, vf2, vf0\n\tvmaddx.xyzw vf2, vf1, vf3x" : "=r"(fence3) : "m"(frame.mat[0]), "r"(fence2));
        int fence4;
        asm("sqc2 vf3, %1" : "=r"(fence4), "=m"(frame.scale) : "r"(fence3));
        asm("sqc2 vf2, %0" : "=m"(*out) : "r"(fence4));
    }
}
}
