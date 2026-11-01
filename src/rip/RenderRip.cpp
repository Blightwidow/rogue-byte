#include "sly2.h"
struct RIP { char pad[0x40]; QW row0; QW row1; QW row2; QW pos; };
struct Rows { QW row[3]; };
extern "C" {
int FRenderRipPosMat__FP3RIPP2CMP6VECTORP7MATRIX3(RIP *, QW, Rows *);
void RemoveRip(RIP *);
}
extern "C" void RenderRip(RIP *prip)
{
    QW pos = prip->pos;
    Rows mat;
    mat.row[0] = prip->row0;
    mat.row[1] = prip->row1;
    mat.row[2] = prip->row2;
    if (FRenderRipPosMat__FP3RIPP2CMP6VECTORP7MATRIX3(prip, pos, &mat) == 0)
        RemoveRip(prip);
}
