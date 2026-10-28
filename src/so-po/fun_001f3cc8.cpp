#include "sly2.h"
struct SOVT { char pad[0xA0]; short d; short i; void (*fn)(void *, void *, float, float, void *); };
struct RO { char b[0x30]; };
struct CHILD { char pad0[0xC]; SOVT *vt; char pad1[0x14]; CHILD *pnext; };
struct SO {
    char pad0[0x64]; CHILD *pchildFirst; char pad1[0x8]; CHILD *pchildEnd; char pad2[0xC]; char globset[1];
    char pad3[0xB3]; RO *pro;
};
extern "C" void func_001A4478(void *, void *, void *);
extern "C" void RenderGlobset(void *, void *, float, float, void *);
extern "C" char B_003DD490;

void func_001F3CC8(SO *psoArg, void *pcmArg, void *proArg, float uAlpha, float uAlphaOther)
{
    register void *pro asm("$18") = proArg;
    register void *pcm asm("$19") = pcmArg;
    SO *pso = psoArg;
    struct { RO ro; char extra[0x10]; } local;
    if (pro == 0 && pso->pro != 0) {
        local.ro = *pso->pro;
        pro = &local.ro;
        func_001A4478(&B_003DD490, pcm, &local.ro);
    }
    RenderGlobset(pso->globset, pcm, uAlpha, uAlphaOther, pro);
    for (CHILD *pchild = pso->pchildFirst; pchild != pso->pchildEnd; pchild = pchild->pnext)
        pchild->vt->fn((char *)pchild + pchild->vt->d, pcm, uAlpha, uAlphaOther, pro);
}
