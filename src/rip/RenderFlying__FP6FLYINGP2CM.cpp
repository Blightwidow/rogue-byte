#include "sly2.h"
struct FLYING { char pad[0x70]; QW pos; char padv[0x10]; QW v; char pad2[0xF4 - 0xA0]; int fAlign; };
struct CM;
struct Rows { QW row[3]; };
struct Frame { Rows copy; QW junk; Rows mat; };
struct CAMERA_GLOBAL { char pad[0x60]; QW up; };
extern "C" {
extern CAMERA_GLOBAL B_002DDF40;
extern QW g_2a2dc0;
void BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(Rows *, QW, QW);
int FRenderRipPosMat__FP3RIPP2CMP6VECTORP7MATRIX3(FLYING *, QW, Rows *);
}

int RenderFlying(FLYING *pflying, CM *pcm)
{
    Frame frame;
    QW hint;
    if (pflying->fAlign != 0) {
        QW scale;
        asm("qmtc2.ni %1, %0" : "=j"(scale) : "r"(-1.0f)); // lane 0: the scale
        asm("vmulx.xyzw %0, %1, %2x" : "=j"(hint) : "j"(B_002DDF40.up), "j"(scale));
        frame.junk = scale;
    } else {
        hint = g_2a2dc0;
    }
    BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(&frame.mat, pflying->v, hint);
    frame.copy = frame.mat;
    return FRenderRipPosMat__FP3RIPP2CMP6VECTORP7MATRIX3(pflying, pflying->pos, &frame.copy);
}
