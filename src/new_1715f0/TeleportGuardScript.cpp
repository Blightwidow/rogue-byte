#include "sly2.h"
struct VT {
    char p0[0xE8];
    short dE8; short iE8; void (*fE8)(void *, QW);
    short dF0; short iF0; void (*fF0)(void *, const void *);
    char p2[0x20];
    short d118; short i118; void (*f118)(void *, QW);
    short d120; short i120; void (*f120)(void *, QW);
};
struct LO { char pad[0xC]; VT *vt; };
struct GUARDREF { char pad[0x10]; LO *plo; };
extern "C" {
void ClearGuardPathMode(LO *);
void SetStepRadTarget(LO *, float);
}
extern QW g_2a2dd0;
extern "C" void TeleportGuardScript(GUARDREF *pref, QW target, float radTarget)
{
    LO *plo = pref->plo;
    ClearGuardPathMode(plo);
    plo->vt->fE8((char *)plo + plo->vt->dE8, target);
    SetStepRadTarget(plo, radTarget);
    plo->vt->fF0((char *)plo + plo->vt->dF0, (char *)plo + 0x1B0);
    plo->vt->f118((char *)plo + plo->vt->d118, g_2a2dd0);
    plo->vt->f120((char *)plo + plo->vt->d120, g_2a2dd0);
}
