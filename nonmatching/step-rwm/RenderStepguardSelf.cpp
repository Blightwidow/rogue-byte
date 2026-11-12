#include "sly2.h"
#include "ps2inline.h"
#include "vu0inline.h"
struct SO;

struct GUARD { char pad0[0x2D]; unsigned char grfrop; char pad1[0x60 - 0x2E]; char *pxfRoot; char pad2[0x80 - 0x64]; char globset[0xAC]; float fade; char pad3[4]; void *pro; char pad4[0x240 - 0x138]; float cx, cy, cz; char pad5[0x360 - 0x24C]; float tStamp; };
extern "C" {
extern char B_002DDF40[];
extern float B_FLT_003E1A60[6];
extern float g_2dded0;
extern float D_FLT_002C3D4C;
extern float D_FLT_002C3D50[3];
extern float D_FLT_002C3D60[2];
extern float g_2bbb60[2];
void func_001F3C10(GUARD *);
int FActiveCplcy(void *);
void RenderGlobset(void *, MATRIX4 *, void *, float, float);
QW PosLoWorld(GUARD *);
QW *__as__6VECTORG9VU_VECTOR(QW *, QW);
void InvertMatrix4Affine(MATRIX4 *, const MATRIX4 *);
float sinf(float);
}
MATRIX4 operator*(const MATRIX4 &, const MATRIX4 &);
static inline MATRIX4 ScaledAboutRoot(const MATRIX4 *world, const MATRIX4 *scale)
{
    MATRIX4 scaled = *world * *scale;
    MATRIX4 inverse;
    InvertMatrix4Affine(&inverse, world);
    return scaled * inverse;
}
void RenderStepguardSelf(GUARD *pguard)
{
    char *pcam = B_002DDF40;
    if ((pguard->grfrop & *(int *)(pcam + 0x14)) == 0)
        return;
    func_001F3C10(pguard);
    if (!FActiveCplcy(pcam + 0x3B0)) {
        RenderGlobset(pguard->globset, 0, pguard->pro, pguard->fade, pguard->fade);
        return;
    }
    MATRIX4 matScale;
    VECTOR vec;
    MATRIX4 matWorld;
    memset(&matScale, 0, 0x40);
    ((float *)&matScale)[0] = 1.0f;
    ((float *)&matScale)[15] = 1.0f;
    ((float *)&matScale)[10] = 1.0f;
    ((float *)&matScale)[5] = 1.0f;
    QW posGuard = PosLoWorld(pguard);
    const float *pc = B_FLT_003E1A60;
    float g0 = B_FLT_003E1A60[0];
    float g2 = pc[2];
    float g1 = pc[1];
    float sCamera = LaneX(SqrtX(SquaredLength(VectorSub(posGuard, *(QW *)(pcam + 0x90)))));
    float scale = g0 + sCamera * (g1 + sCamera * g2);
    if (scale < pc[4])
        scale = pc[4];
    else if (pc[5] < scale)
        scale = pc[5];
    float scaleXy = scale;
    float scaleZ = scale;
    float dt = g_2dded0 - pguard->tStamp;
    if (dt < 0.85f) {
        float uSine = (sinf(dt * D_FLT_002C3D4C) + 1.0f) * 0.5f;
        float u = dt * 1.1764705f;
        float env = D_FLT_002C3D50[0] + u * (D_FLT_002C3D50[1] + u * D_FLT_002C3D50[2]);
        if (env < g_2bbb60[0])
            env = g_2bbb60[0];
        else if (g_2bbb60[1] < env)
            env = g_2bbb60[1];
        float wobble = ((1.0f - uSine) * D_FLT_002C3D60[0] + uSine * D_FLT_002C3D60[1]) * env;
        scaleZ = wobble + 1.0f;
        scaleXy = 1.0f - wobble;
    }
    ((float *)&matScale)[0] = scaleXy;
    ((float *)&matScale)[5] = scaleXy;
    ((float *)&matScale)[10] = scaleZ;
    vec.y = (1.0f - scaleXy) * pguard->cy;
    vec.z = (1.0f - scaleZ) * pguard->cz;
    vec.x = (1.0f - scaleXy) * pguard->cx;
    __as__6VECTORG9VU_VECTOR(&matScale.row[3], *(QW *)&vec);
    ((float *)&matScale)[15] = 1.0f;
    matWorld = *(MATRIX4 *)(pguard->pxfRoot + 0x40);
    MATRIX4 matDraw = ScaledAboutRoot(&matWorld, &matScale);
    RenderGlobset(pguard->globset, &matDraw, pguard->pro, pguard->fade, pguard->fade);
}
