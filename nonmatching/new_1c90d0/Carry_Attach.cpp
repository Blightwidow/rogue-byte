#include "sly2.h"
struct M4 { QW row[4]; };
struct VTE { short delta; short index; void *fn; };
struct VTO { char pad0[0x50]; VTE setParent; char pad1[0xF8 - 0x58]; VTE getMat; char pad2[0x100 - 0x100 + 0]; VTE getXf; };
struct OBJ { char pad[0xC]; VTO *vt; };
struct JT;
struct SO { char pad0[0xC]; VTO *vt; char pad1[0x58 - 0x10]; void *pxfLinear; void *pxfAngular; char pad2[0xE8 - 0x60]; int pphys; };
struct CARRY { JT *pjt; char pad0[0x34 - 4]; OBJ *source; char pad1[0x94 - 0x38]; void *act94; void *act98; void *act9C; SO *attached; };
extern "C" {
void func_0012E460(void *);
SO *func_001CCA40(JT *, SO *);
M4 ConvertAloMat(int, SO *, M4 *);
void InvertMatrix4Affine(M4 *, M4 *);
M4 __ml__FRC7MATRIX4T0(const M4 &, const M4 &);
void SetLoPosMat(SO *, M4 *);
void SetSoCnstrForce(SO *, int);
void SetSoCnstrTorque(SO *, int);
QW GetXfDofValue(void *, void *);
void *func_0012DC18(SO *, void *, int, int, int, QW);
void FadeAloIn(SO *, float);
}

void Carry_Attach(CARRY *carry, SO *so)
{
    if (so == carry->attached) return;
    func_0012E460(&carry->act94);
    func_0012E460(&carry->act98);
    func_0012E460(&carry->act9C);
    M4 matSource;
    OBJ *source = carry->source;
    void *xfSource = ((void *(*)(void *, M4 *))source->vt->getXf.fn)((char *)source + source->vt->getXf.delta, &matSource);
    ((void (*)(void *, JT *, void *, int))so->vt->setParent.fn)((char *)so + so->vt->setParent.delta, carry->pjt, xfSource, 0);
    OBJ *source2 = carry->source;
    M4 matPlace = *((M4 *(*)(void *))source2->vt->getMat.fn)((char *)source2 + source2->vt->getMat.delta);
    SO *anchor = func_001CCA40(carry->pjt, so);
    if (anchor) {
        M4 matAnchor;
        M4 inverse;
        matAnchor = ConvertAloMat(0, so, ((M4 *(*)(void *))anchor->vt->getMat.fn)((char *)anchor + anchor->vt->getMat.delta));
        InvertMatrix4Affine(&inverse, &matAnchor);
        matPlace = __ml__FRC7MATRIX4T0(matPlace, inverse);
    }
    SetLoPosMat(so, &matPlace);
    if (so->pphys) {
        SetSoCnstrForce(so, 1);
        SetSoCnstrTorque(so, 1);
    }
    void *xfLinear = so->pxfLinear;
    carry->act98 = func_0012DC18(so, xfLinear, 5, 0, 2, GetXfDofValue(xfLinear, xfLinear));
    void *xfAngular = so->pxfAngular;
    carry->act9C = func_0012DC18(so, xfAngular, 5, 0, 2, GetXfDofValue(xfAngular, xfAngular));
    FadeAloIn(so, 0.25f);
    carry->attached = so;
}
