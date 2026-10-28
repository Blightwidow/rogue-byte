#include "sly2.h"
struct MATRIX44 { float mat[4][4]; } __attribute__((aligned(16)));
struct ROWS3 { VECTOR row[3]; };
struct LM { float lo; float hi; };
extern "C" LM g_2bbb60;
extern const float RO_FLT_002A4B30[4] = {0.0f, 0.0f, 1.5f, 0.0f};
extern "C" float g_2dded0;
extern "C" void func_001F3C70(char *);
extern "C" void func_001A5EE8(char *, MATRIX44 *, float, float);
extern "C" void LoadMatrixFromPosRotScale(MATRIX44 *, QW, ROWS3 *, float *);
extern "C" QW PosLoWorld(char *);
extern "C" ROWS3 *PmatLoWorld(char *);
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
extern "C" void RenderLoot(char *ploot)
{
    char buf[0x90] __attribute__((aligned(16)));
    switch (*(int *)(ploot + 0x184)) {
    case 4: {
        float dtBlend = *(float *)(ploot + 0x180);
        float elapsed = g_2dded0 - *(float *)(ploot + 0x188);
        if (dtBlend <= elapsed) {
            *(QW *)buf = *(QW *)(ploot + 0x170);
        } else {
            asm volatile("nop\n\tnop");
            float u = elapsed / dtBlend;
            float gBlend = GLimitLm(&g_2bbb60, RO_FLT_002A4B30[0] + u * (RO_FLT_002A4B30[1] + u * RO_FLT_002A4B30[2]));
            float *pheld = (float *)(ploot + 0x170);
            float *pscale = (float *)buf;
            for (int iaxis = 0; iaxis < 3; iaxis++)
                pscale[iaxis] = (1.0f - gBlend) + gBlend * pheld[iaxis];
        }
        MATRIX44 *pmat = (MATRIX44 *)(buf + 0x50);
        QW pos = PosLoWorld(ploot);
        LoadMatrixFromPosRotScale(pmat, pos, PmatLoWorld(ploot), (float *)buf);
        *(MATRIX44 *)(buf + 0x10) = *(MATRIX44 *)(buf + 0x50);
        func_001A5EE8(ploot, (MATRIX44 *)(buf + 0x10), 1.0f, 1.0f);
        break;
    }
    case 1:
    case 5:
        func_001F3C70(ploot);
        break;
    case 2:
    case 3:
        break;
    }
}
