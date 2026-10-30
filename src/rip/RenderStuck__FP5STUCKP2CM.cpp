#include "sly2.h"
struct Rows3 { QW row[3]; };
struct XF;
struct STUCK { char pad0[0x40]; Rows3 mat; QW pos; char pad1[0xF0 - 0x80]; int xf; };
struct RIP;
extern "C" {
QW ConvertXfPos(int, XF *, QW);
Rows3 ConvertXfMat(int, XF *, Rows3 *);
void FRenderRipPosMat__FP3RIPP2CMP6VECTORP7MATRIX3(void *, QW, Rows3 *);
}

void RenderStuck__FP5STUCKP2CM(STUCK *self)
{
    QW pos = ConvertXfPos(self->xf, 0, self->pos);
    Rows3 copy;
    Rows3 mat = ConvertXfMat(self->xf, 0, &self->mat);
    copy = mat;
    FRenderRipPosMat__FP3RIPP2CMP6VECTORP7MATRIX3(self, pos, &copy);
}
