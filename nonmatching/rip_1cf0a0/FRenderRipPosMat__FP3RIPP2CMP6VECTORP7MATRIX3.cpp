#include "sly2.h"
struct MATRIX44 { float mat[4][4]; } __attribute__((aligned(16)));
struct ROWS3 { VECTOR row[3]; };
struct PALO { char pad[0x38]; float radius; };
struct CLQ { float a, b, c; };
struct RIP { char pad[0x14]; float tCreated; float dt; PALO *palo; CLQ clqScale; float pad2c; CLQ clqAlpha; };
extern "C" int FInsideCmFrustrum(void *);
extern "C" int FInsideCmMrd(void *, QW, float *, float);
extern "C" void func_001A5EE8(PALO *, MATRIX44, float, float);
extern "C" void func_0011C288(MATRIX44 *, QW, ROWS3 *, float);
extern "C" char B_002DDF40[];
extern "C" float g_2dded0;
extern "C" float g_2bbb60[2];

static inline float GCurve(CLQ *clq, float u) { return clq->a + u * (clq->b + u * clq->c); }
static inline float GClamp(float g, float *range)
{
    float lo = range[0];
    float hi = range[1];
    if (g < lo) return lo;
    if (hi < g) return hi;
    return g;
}

struct FRAME { QW radius; MATRIX44 mat; float out[4]; };
extern "C" int FRenderRipPosMat__FP3RIPP2CMP6VECTORP7MATRIX3(RIP *rip, QW pos, ROWS3 *mat3)
{
    FRAME f;
    if (rip->palo == 0) return 1;
    float dt = rip->dt;
    if (dt <= 0.0f) return 0;
    float u = (g_2dded0 - rip->tCreated) / dt;
    float alpha = GClamp(GCurve(&rip->clqAlpha, u), g_2bbb60);
    QW dpos;
    char *cm = B_002DDF40;
    float scale = GCurve(&rip->clqScale, u);
    asm("lqc2 vf1, %0" : : "m"(*(VECTOR *)(cm + 0x90)));
    asm("lqc2 vf2, %0" : : "m"(pos));
    asm("vsub.xyzw vf2, vf2, vf1\n\tsqc2 vf2, %0" : "=m"(dpos));
    float r100 = scale * 100.0f;
    int bits;
    asm("mfc1 %0, %1" : "=r"(bits) : "f"(r100));
    QW &radius = f.radius;
    radius = (long)bits;
    if (FInsideCmFrustrum(cm) == 0) return 1;
    if (FInsideCmMrd(cm, dpos, f.out, rip->palo->radius) == 0) return 0;
    if (alpha < 0.0001f) {
        if (scale < 0.0001f) return 1;
    }
    func_0011C288(&f.mat, pos, mat3, scale);
    func_001A5EE8(rip->palo, f.mat, alpha * f.out[0], 1.0f);
    return 1;
}
