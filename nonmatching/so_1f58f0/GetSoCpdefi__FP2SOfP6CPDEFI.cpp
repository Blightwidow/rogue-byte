#include "sly2.h"
struct XF { char pad[0x40]; MATRIX3 mat; char pad2[0x70 - 0x40 - sizeof(MATRIX3)]; QW pos; };
struct SO { char pad[0x60]; XF *root; };
struct CPDEFI { int grfcpd; char pad[0xC]; QW pos; QW vel; float radHome; float sAdjust; float tMoveLast; int cfk; };
extern float g_2dded0;
extern "C" QW VelocityXfAtPos(XF *, void *, QW);
void TiltMatUpright(MATRIX3 *, MATRIX3 *, MATRIX3 *);
extern "C" float atan2f(float, float);

void GetSoCpdefi(SO *so, float dt, CPDEFI *cp)
{
    XF *xf = so->root;
    MATRIX3 *mat = &xf->mat;
    QW pos = xf->pos;
    cp->pos = pos;
    cp->vel = VelocityXfAtPos(xf, 0, pos);
    MATRIX3 up;
    TiltMatUpright(mat, 0, &up);
    cp->radHome = atan2f(-up.mat[0][1], -up.mat[0][0]);
    cp->sAdjust = 100.0f;
    cp->grfcpd = 0;
    cp->tMoveLast = g_2dded0;
    cp->cfk = 0;
}
