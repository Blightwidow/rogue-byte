#include "sly2.h"
struct FLYING { char pad[0x70]; QW pos; char padv[0x10]; QW v; char pad2[0xF4 - 0xA0]; int fAlign; };
struct CM;
struct Rows { QW row[3]; };
struct Frame { Rows copy; QW junk; Rows mat; };
extern "C" {
extern char B_002DDF40[];
extern char g_2a2dc0[];
void BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(Rows *, QW, QW);
int FRenderRipPosMat__FP3RIPP2CMP6VECTORP7MATRIX3(FLYING *, QW, Rows *);
}

int RenderFlying(FLYING *pflying, CM *pcm)
{
    Frame frame;
    QW hint;
    if (pflying->fAlign != 0) {
        float neg = -1.0f;
        asm("qmtc2.ni %0, vf2\n\tlqc2 vf1, 0x60(%1)\n\tvmulx.xyzw vf1, vf1, vf2x" : : "r" (*(int *)&neg), "r" (B_002DDF40));
        asm("sqc2 vf2, %0" : "=m" (frame.junk));
    } else {
        asm("lqc2 vf1, %0" : : "m" (*(QW *)g_2a2dc0));
    }
    QW velocity = pflying->v;
    asm volatile("qmfc2.ni %0, vf1" : "=r" (hint));
    BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(&frame.mat, velocity, hint);
    frame.copy = frame.mat;
    return FRenderRipPosMat__FP3RIPP2CMP6VECTORP7MATRIX3(pflying, pflying->pos, &frame.copy);
}
