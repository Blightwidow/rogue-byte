// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct LO_174490;
struct VT_174490 {
    char pad[0xE8];
    short delta1; short index1; void (*fnSetPos)(char *, QW);
    short delta2; short index2; void (*fnSetRot)(char *, int);
};
struct LO_174490 { char pad0[0xC]; VT_174490 *vt; char pad1[0x2E8 - 0x10]; int unk2E8; char pad2[0x1000 - 0x2EC]; int unk1000; };
struct GOAL_174490 { char pad[8]; int unk8; };
struct SPAWN_174490 { int k; int pad4; LO_174490 *plo; int unkC; GOAL_174490 *pgoal; };
struct GEN_174490 { char pad[0x90]; int clo; LO_174490 **aplo; };
struct CMD_174490 { int k; char pad[0x70 - 4]; CMD_174490() { memset(this, 0, sizeof(*this)); } };
struct BRAIN_174490;
extern "C" {
LO_174490 *PloLeaseCloneObject(LO_174490 *, int);
int FFindSurfaceAlongUp(QW *, int, int, float, float);
int NRandInRange(int, int);
BRAIN_174490 *func_00205458(LO_174490 *, int);
void GoalBrain_SetCommand(BRAIN_174490 *, CMD_174490 *);
extern const float D_002BE5F0[2];

LO_174490 *func_00174490(GEN_174490 *pgen, SPAWN_174490 *pspawn, QW *ppos, int rot, int goal)
{
    LO_174490 *plo = 0;
    int k = pspawn->k;
    if (k == 0) {
        plo = PloLeaseCloneObject(pspawn->plo, 0);
    } else if (k >= 0) {
      if (k < 3) {
        int aindex[8];
        FFindSurfaceAlongUp(ppos, 1, 0, D_002BE5F0[1], D_002BE5F0[0]);
        for (int i = 0; i < pgen->clo; i++)
            aindex[i] = i;
        for (int i = 0; i < pgen->clo; i++) {
            int j = NRandInRange(0, pgen->clo - 1);
            int t = aindex[i];
            aindex[i] = *(j + aindex);
            *(j + aindex) = t;
        }
        for (int i = 0; i < pgen->clo; i++) {
            LO_174490 *ploT = pgen->aplo[aindex[i]];
            ploT->vt->fnSetPos((char *)ploT + ploT->vt->delta1, *ppos);
            ploT->vt->fnSetRot((char *)ploT + ploT->vt->delta2, rot);
            plo = PloLeaseCloneObject(ploT, 0);
            if (plo != 0)
                break;
        }
        int kSpawn = pspawn->k;
        if (kSpawn == 1) {
            if (plo == 0)
                goto done;
            pspawn->pgoal->unk8 = goal;
            plo->unk2E8 = pspawn->unkC;
            BRAIN_174490 *pbrain = func_00205458(plo, 0x9C);
            CMD_174490 cmd;
            cmd.k = -1;
            GoalBrain_SetCommand(pbrain, &cmd);
            cmd.k = kSpawn;
            GoalBrain_SetCommand(pbrain, &cmd);
        }
      }
    }
    if (plo != 0)
        plo->unk1000 = 1;
done:
    return plo;
}
}
