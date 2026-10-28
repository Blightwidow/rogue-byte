// SPDX-License-Identifier: GPL-3.0-or-later
// PARTIAL: prologue and the kind-9 (spot) loop only; see data/matching/notes/19B110.md
#include "sly2.h"
struct JTX { char pad0[0xC]; char *vptr; char pad1[0xEC - 0x10]; void *poxa; char pad2[0x1000 - 0xF0]; unsigned grfTarget; };
struct JMPX { JTX *pjt; };
struct VT108 { char pad[0x108]; short delta; short index; QW (*fn)(void *); };
struct VT18 { char pad[0x18]; short delta; short index; void (*fn)(void *, void *, QW *, int, float); };
struct SPOT { char pad[0xE0]; int unkE0; char pad1[4]; float zMax; char pad2[0xFC - 0xEC]; unsigned grf; char pad3[0x100 - 0x100]; VT18 *vtLocal; SPOT *next; };
extern "C" const float RO_002A65B8;
extern "C" const float RO_002A65BC;
extern "C" SPOT *B_003E13D8;
extern "C" const float D_FLT_002BF8E0;
extern "C" const float D_FLT_002BF8E4;
extern "C" char FFilterOxa[];
extern QW g_2a2dd0;
extern "C" QW PosLoWorld(void *);
extern "C" QW GetJmpLaunchVelocity(void *, int);
extern "C" int FIsBasicDerivedFrom(void *, int);
extern "C" float GAdjustJtLandingScore(float, float, void *, void *);
extern "C" int MeasureJtJumpToTarget__FP2JTP6VECTORP3ALOT1T1PfT5T1T1(void *, QW, void *, QW, QW, float *, float *, QW *, QW *);
extern "C" int FFindJtObstruction(void *, float, void *, void *, QW, QW, QW, QW, void *);

extern "C" void JtbsChooseJtLanding(JMPX *pjmp, void *ploForce)
{
    struct { QW posJt; QW vJt; QW posAim; QW vAimB; QW vAim; QW triBest; QW vLaunch; QW posTarget; } l;
    float dtBest;
    float sJump = 0.0f;
    float uJump = 0.0f;
    void *pobjBest = 0;
    int jtbsBest = -1;
    l.posJt = PosLoWorld(pjmp->pjt);
    {
        JTX *pjt = pjmp->pjt;
        VT108 *vt = (VT108 *)((JTX *)pjt)->vptr;
        l.vJt = vt->fn((char *)pjt + vt->delta);
    }
    unsigned grfTarget = pjmp->pjt->grfTarget;
    memset((char *)&l.triBest, 0, 0xC);
    float gBest = ploForce ? RO_002A65B8 : RO_002A65BC;
    l.vLaunch = GetJmpLaunchVelocity(pjmp, 4);
    dtBest = 0.0f;
    if (FIsBasicDerivedFrom(pjmp->pjt, 0x35)) {
        for (SPOT *pobj = B_003E13D8; pobj; pobj = pobj->next) {
            if ((pobj->grf & grfTarget) == 0)
                continue;
            VT18 *vt = pobj->vtLocal;
            vt->fn((char *)&pobj->unkE0 + vt->delta, pjmp->pjt, &l.posTarget, 0, 0.0f);
        }
    }
}
