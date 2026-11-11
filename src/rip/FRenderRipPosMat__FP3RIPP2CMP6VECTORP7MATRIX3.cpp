// SPDX-License-Identifier: GPL-3.0-or-later
#include "ps2inline.h"
#include "vu0inline.h"
#include "sly2.h"
struct MATRIX44 { float mat[4][4]; } __attribute__((aligned(16)));
struct ROWS3 { VECTOR row[3]; };
struct LM { float lo; float hi; };
struct CMDATA { char pad[0x90]; QW pos; };
struct RIPOBJECT { char pad[0x38]; float radius; };
struct COEFFS { float c0, c1, c2; };
struct RIP { char pad[0x14]; float tStart; float duration; RIPOBJECT *object; COEFFS radius; char pad2c[4]; COEFFS scale; };
extern "C" LM g_2bbb60;
extern "C" float g_2dded0;
extern "C" CMDATA D_2DDF40;
extern "C" int FInsideCmFrustrum(CMDATA *, QW, QW);
extern "C" int FInsideCmMrd(CMDATA *, QW, float *, float);
extern "C" MATRIX44 func_0011C288(QW, ROWS3 *, float);
extern "C" void func_001A5EE8(RIPOBJECT *, MATRIX44 *, float, float);
static inline float Quadratic(COEFFS *pcoeffs, float u)
{
    return pcoeffs->c0 + u * (pcoeffs->c1 + u * pcoeffs->c2);
}
static inline float GLimitLm(LM *plm, float g)
{
    float lo = plm->lo;
    float hi = plm->hi;
    if (g < lo)
        return lo;
    if (hi < g)
        return hi;
    return g;
}
int FRenderRipPosMat__FP3RIPP2CMP6VECTORP7MATRIX3(RIP *rip, QW pos, ROWS3 *rows)
{
    if (rip->object == 0)
        return 1;
    float duration = rip->duration;
    if (duration <= 0.0f)
        return 0;
    float u = (g_2dded0 - rip->tStart) / duration;
    float gScale = GLimitLm(&g_2bbb60, Quadratic(&rip->scale, u));
    float radius = Quadratic(&rip->radius, u);
    QW offset = VectorSub(pos, D_2DDF40.pos);
    union { QW q; float f[4]; } extent;
    extent.q = QuadFromFloat(radius * 100.0f);
    if (!FInsideCmFrustrum(&D_2DDF40, offset, extent.q))
        return 1;
    float t;
    if (!FInsideCmMrd(&D_2DDF40, offset, &t, rip->object->radius))
        return 0;
    if (gScale < 0.0001f && radius < 0.0001f)
        return 1;
    MATRIX44 world;
    MATRIX44 built = func_0011C288(pos, rows, radius);
    world = built;
    func_001A5EE8(rip->object, &world, gScale * t, 1.0f);
    return 1;
}
