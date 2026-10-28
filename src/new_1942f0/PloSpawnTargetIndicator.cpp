#include "sly2.h"
struct VT {
    char p0[0x48];
    short d48; short i48; void (*f48)(void *);
    char p1[0x98];
    short dE8; short iE8; void (*fE8)(void *, QW);
    short dF0; short iF0; void (*fF0)(void *, const void *);
    char p2[0x20];
    short d118; short i118; void (*f118)(void *, QW);
    short d120; short i120; void (*f120)(void *, QW);
};
struct LO { char pad[0xC]; VT *vt; };
struct TARGET { char pad[0x20]; QW pos; };
extern "C" {
LO *PloLeaseCloneObject(void *, int);
void func_001A58D0(LO *, int, int);
void FadeAloIn(LO *, float);
}
extern QW g_2a2dd0;
extern char RO_002A2D00[];
extern "C" LO *PloSpawnTargetIndicator(void *psw, void *ptemplate, TARGET *ptarget)
{
    if (!ptemplate) return 0;
    LO *plo = PloLeaseCloneObject(ptemplate, 0);
    if (plo) {
        func_001A58D0(plo, 0, 0);
        plo->vt->f48((char *)plo + plo->vt->d48);
        FadeAloIn(plo, 0.25f);
        plo->vt->fE8((char *)plo + plo->vt->dE8, ptarget->pos);
        plo->vt->fF0((char *)plo + plo->vt->dF0, RO_002A2D00);
        plo->vt->f118((char *)plo + plo->vt->d118, g_2a2dd0);
        plo->vt->f120((char *)plo + plo->vt->d120, g_2a2dd0);
    }
    return plo;
}
