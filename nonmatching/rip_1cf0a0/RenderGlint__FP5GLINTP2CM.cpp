#include "sly2.h"
struct CLQ { float a, b, c; };
struct GLINT {
    char pad0[0x14]; float tCreated; float dt; void *palo; CLQ clqScale; float p2c; CLQ clqAlpha; char pad3[0x70 - 0x3C]; QW pos;
};
struct ROWS3 { QW row[3]; };
extern "C" int FInsideCmFrustrum(void *, QW, QW);
extern "C" void RemoveRip(GLINT *);
extern "C" void BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(ROWS3 *, QW, QW);
extern "C" void LoadRotateMatrixRad(ROWS3 *, float, QW);
extern "C" void func_0011C288(void *, QW, ROWS3 *, float);
extern "C" void func_001A5EE8(void *, void *, float, float);
extern "C" char B_002DDF40[];
extern "C" float g_2dded0;
extern "C" float g_2bbb60[2];
extern "C" QW g_2a2dc0, g_2a2da0;
extern "C" CLQ D_002C1FB0, D_002C1FD0, D_002C1FF0;
extern "C" float D_002C1FC0[2], D_002C1FE0[2];

static inline float GCurve(CLQ *clq, float u) { return clq->a + u * (clq->b + u * clq->c); }
static inline float GClamp(float g, float *range)
{
    float lo = range[0];
    float hi = range[1];
    if (g < lo) return lo;
    if (hi < g) return hi;
    return g;
}

#define SLOT(offset) (*(QW *)(buf + (offset)))
extern "C" void RenderGlint__FP5GLINTP2CM(GLINT *glint, void *pcm)
{
    char buf[0x150] __attribute__((aligned(16)));
    char *cm = B_002DDF40;
    int chainA, chainB;
    asm("lqc2 vf2, %1\n\tlqc2 vf1, %2\n\tvsub.xyzw vf3, vf2, vf1" : "=r"(chainA) : "m"(*(QW *)(cm + 0x90)), "m"(glint->pos));
    asm("vmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z" : "=r"(chainB) : "r"(chainA));
    float milli = 0.001f;
    int bits;
    asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1" : "=r"(bits) : "r"(chainB));
    float length;
    asm("mtc1 %1, %0" : "=f"(length) : "r"(bits));
    float uDistance = length * milli;
    float uLife = (g_2dded0 - glint->tCreated) / glint->dt;
    float scaleDistance = GClamp(GCurve(&D_002C1FB0, uDistance), D_002C1FC0);
    float scale = GCurve(&glint->clqScale, uLife) * scaleDistance;
    float minusOne = -1.0f;
    int minusOneBits;
    asm("mfc1 %0, %1" : "=r"(minusOneBits) : "f"(minusOne));
    float r100 = scale * 100.0f;
    int radiusBits;
    asm("mfc1 %0, %1" : "=r"(radiusBits) : "f"(r100));
    asm("qmtc2.ni %0, vf1" : : "r"(minusOneBits));
    asm("vmulx.xyzw vf2, vf3, vf1x");
    asm("sqc2 vf1, %0" : "=m"(SLOT(0xD0)));
    QW radius = (long)radiusBits;
    asm("sqc2 vf3, %0" : "=m"(SLOT(0x140)));
    QW dposRel;
    asm("qmfc2.ni %0, vf2" : "=r"(dposRel));
    SLOT(0xD0) = radius;
    if (FInsideCmFrustrum(cm, dposRel, radius) == 0) {
        RemoveRip(glint);
        return;
    }
    float alpha = GClamp(GCurve(&glint->clqAlpha, uLife), g_2bbb60);
    float alphaDistance = GClamp(GCurve(&D_002C1FD0, uDistance), D_002C1FE0);
    QW dposCam;
    asm("qmfc2.ni %0, vf3" : "=r"(dposCam));
    alpha = alpha * alphaDistance;
    BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3((ROWS3 *)&SLOT(0xE0), dposCam, g_2a2dc0);
    CLQ *clqSpin = &D_002C1FF0;
    QW *axis = &g_2a2da0;
    ROWS3 *spin = (ROWS3 *)&SLOT(0xD0);
    *(ROWS3 *)&SLOT(0) = *(ROWS3 *)&SLOT(0xE0);
    LoadRotateMatrixRad(spin, clqSpin->a + uLife * (clqSpin->b + uLife * clqSpin->c), *axis);
    asm("lqc2 vf8, %0" : : "m"(SLOT(0xD0)));
    asm("lqc2 vf7, %0" : : "m"(SLOT(0xE0)));
    asm("lqc2 vf6, %0" : : "m"(SLOT(0xF0)));
    asm("lqc2 vf3, %0" : : "m"(SLOT(0)));
    asm("lqc2 vf2, %0" : : "m"(SLOT(0x10)));
    asm("lqc2 vf1, %0" : : "m"(SLOT(0x20)));
    asm("vmulax.xyz ACC, vf3, vf6x\n\tvmadday.xyz ACC, vf2, vf6y\n\tvmaddz.xyz vf5, vf1, vf6z\n\tvmulax.xyz ACC, vf3, vf8x\n\tvmadday.xyz ACC, vf2, vf8y\n\tvmaddz.xyz vf4, vf1, vf8z");
    asm("vmulax.xyz ACC, vf3, vf7x\n\tvmadday.xyz ACC, vf2, vf7y\n\tvmaddz.xyz vf3, vf1, vf7z");
    asm("sqc2 vf4, %0" : "=m"(SLOT(0x60)));
    asm("sqc2 vf3, %0" : "=m"(SLOT(0x70)));
    asm("sqc2 vf5, %0" : "=m"(SLOT(0x80)));
    asm("sqc2 vf8, %0" : "=m"(SLOT(0x30)));
    asm("sqc2 vf7, %0" : "=m"(SLOT(0x40)));
    asm("sqc2 vf6, %0" : "=m"(SLOT(0x50)));
    asm("sqc2 vf4, %0" : "=m"(SLOT(0x110)));
    asm("sqc2 vf4, %0" : "=m"(SLOT(0xD0)));
    asm("sqc2 vf3, %0" : "=m"(SLOT(0x120)));
    asm("sqc2 vf3, %0" : "=m"(SLOT(0xE0)));
    asm("sqc2 vf5, %0" : "=m"(SLOT(0x130)));
    asm("sqc2 vf5, %0" : "=m"(SLOT(0xF0)));
    func_0011C288(&SLOT(0xD0), glint->pos, (ROWS3 *)&SLOT(0x60), scale);
    ((QW *)&SLOT(0x90))[0] = SLOT(0xD0);
    ((QW *)&SLOT(0x90))[1] = SLOT(0xE0);
    ((QW *)&SLOT(0x90))[2] = SLOT(0xF0);
    ((QW *)&SLOT(0x90))[3] = SLOT(0x100);
    func_001A5EE8(glint->palo, &SLOT(0x90), alpha, 1.0f);
}
