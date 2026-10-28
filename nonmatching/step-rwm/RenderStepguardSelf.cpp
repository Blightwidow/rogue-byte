#include "sly2.h"
struct M4 { QW row[4]; };
struct SO;
struct XF { char pad[0x40]; M4 mat; };
struct GUARD { char pad0[0x2D]; unsigned char grfrop; char pad1[0x60 - 0x2E]; XF *pxfRoot; char pad2[0x80 - 0x64]; char globset[0xAC]; float fade; char pad3[4]; void *pro; char pad4[0x240 - 0x138]; float cx, cy, cz; char pad5[0x360 - 0x24C]; float tStamp; };
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
void RenderGlobset(void *, M4 *, void *, float, float);
QW PosLoWorld(GUARD *);
QW *__as__6VECTORG9VU_VECTOR(QW *, QW);
M4 __ml__FRC7MATRIX4T0(const M4 &, const M4 &);
void InvertMatrix4Affine(M4 *, const M4 *);
float sinf(float);
}
void *memset(void *, int, unsigned int);
void RenderStepguardSelf(GUARD *pguard)
{
    struct Frame { M4 matScale; QW vec; M4 matWorld; M4 matDraw; M4 matScaled; M4 matInverse; } f;
    char *pcam = B_002DDF40;
    if ((pguard->grfrop & *(int *)(pcam + 0x14)) == 0)
        return;
    func_001F3C10(pguard);
    if (!FActiveCplcy(pcam + 0x3B0)) {
        RenderGlobset(pguard->globset, 0, pguard->pro, pguard->fade, pguard->fade);
        return;
    }
    memset(&f.matScale, 0, 0x40);
    ((float *)&f.matScale)[0] = 1.0f;
    ((float *)&f.matScale)[15] = 1.0f;
    ((float *)&f.matScale)[10] = 1.0f;
    ((float *)&f.matScale)[5] = 1.0f;
    QW posGuard = PosLoWorld(pguard);
    asm("lqc2 vf2, %0" : : "m" (*(QW *)(pcam + 0x90)));
    asm("qmtc2.ni %0, vf3" : : "r" (posGuard));
    const float *pc = B_FLT_003E1A60;
    float g0 = B_FLT_003E1A60[0];
    asm("vsub.xyzw vf1, vf3, vf2");
    asm("vmul.xyz vf1, vf1, vf1");
    asm("vaddw.x vf2, vf0, vf0w");
    asm("vadday.x ACC, vf1, vf1y");
    asm("vmaddz.x vf1, vf2, vf1z");
    float g2 = pc[2];
    asm("vsqrt Q, vf1x");
    asm("vwaitq");
    asm("vaddq.x vf1, vf0, Q");
    float sCamera;
    float g1 = pc[1];
    asm("qmfc2.ni %0, vf1" : "=r" (sCamera));
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
    ((float *)&f.matScale)[0] = scaleXy;
    ((float *)&f.matScale)[5] = scaleXy;
    ((float *)&f.matScale)[10] = scaleZ;
    ((float *)&f.vec)[1] = (1.0f - scaleXy) * pguard->cy;
    ((float *)&f.vec)[2] = (1.0f - scaleZ) * pguard->cz;
    ((float *)&f.vec)[0] = (1.0f - scaleXy) * pguard->cx;
    __as__6VECTORG9VU_VECTOR(&f.matScale.row[3], f.vec);
    ((float *)&f.matScale)[15] = 1.0f;
    f.matWorld = pguard->pxfRoot->mat;
    f.matScaled = __ml__FRC7MATRIX4T0(f.matWorld, f.matScale);
    InvertMatrix4Affine(&f.matInverse, &f.matWorld);
    f.matDraw = __ml__FRC7MATRIX4T0(f.matScaled, f.matInverse);
    RenderGlobset(pguard->globset, &f.matDraw, pguard->pro, pguard->fade, pguard->fade);
}
