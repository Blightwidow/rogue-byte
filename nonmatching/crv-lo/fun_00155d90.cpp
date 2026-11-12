// SPDX-License-Identifier: GPL-3.0-or-later
#include "vu0inline.h"
#include "sly2.h"
#include "goal.h"
#include "step.h"
struct GOAL_155D90 : GOAL {
    int state;
    float tState;
    void *ptable;
    char pad3c[4];
    void *ptarget;
    float tReact;
    float tAnim;
    void *psensed;
    char pad50[4];
    void *pnotice;
};
extern "C" {
int FGoalAnimDone(void *);
int FGoalReactDone(void *);
int GoalFollowCrv_FAtEnd(void *);
void *PsenseFindNotice(void *, void *, int);
QW PosLoWorld(void *);
void func_00155AE0(GOAL_155D90 *, int);
void *func_00155A68(GOAL_155D90 *);
void func_001EEF98(GOAL_155D90 *);
int func_001EF0A8(GOAL_155D90 *);
}
extern QW g_2a2dd0;
extern float g_2dded0;
void func_00155D90(GOAL_155D90 *self)
{
    func_001EEF98(self);
    while (func_001EF0A8(self) == 0) {
        int stateOld = self->state;
        switch (stateOld) {
        case 0:
            if (FGoalAnimDone(self->pgoalChild) != 0) {
                QW target = PosLoWorld(self->ptarget);
                STEP *pstep = self->pstep;
                pstep->TranslateToPos(VectorSub(target, *(QW *)((char *)pstep + 0x240)));
                self->pstep->Slot35(g_2a2dd0);
                self->pstep->Slot36(g_2a2dd0);
                self->tAnim = g_2dded0;
                func_00155AE0(self, 1);
            }
            break;
        case 2:
            if (GoalFollowCrv_FAtEnd(self->pgoalChild) != 0)
                func_00155AE0(self, 1);
            break;
        case 1:
            if (g_2dded0 - self->tAnim > 2.5f) {
                if (g_2dded0 - self->tState > 0.1f) {
                    self->pnotice = PsenseFindNotice(self->pstep, self->psensed, 0);
                    if (self->pnotice != 0)
                        func_00155AE0(self, 3);
                }
            }
            break;
        case 3:
            self->tReact = g_2dded0;
            if (FGoalReactDone(self->pgoalChild) != 0) {
                int next = 1;
                void *pchosen = func_00155A68(self);
                if (pchosen != self->ptarget) {
                    self->ptarget = pchosen;
                    next = 2;
                }
                func_00155AE0(self, next);
            }
            break;
        }
        if (stateOld == self->state)
            break;
    }
}
