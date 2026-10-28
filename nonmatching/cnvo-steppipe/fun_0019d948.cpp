// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct SW { char pad[0x3B0C]; struct JOB *pjob; };
struct JOB { char pad[0x6C]; int id; };
struct BLOT { char pad[0xCC]; int aid[2]; };
struct HUD { int a; int b; BLOT *pblot; };
struct TASK { char pad[0x5C]; int id; char pad2[0x1C]; JOB *pjob; };
extern SW B_003DD490;
extern "C" {
void CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void OrderTasks(int *, TASK ***);
int FTaskComplete(TASK *);
void qsort(void *, int, int, int (*)(const void *, const void *));
int func_00165C28(const void *, const void *);
}
void func_0019D948(HUD *phud)
{
    struct { int frame; int ctask; TASK **aptask; } s;
    BLOT *pblot = phud->pblot;
    if (pblot) {
        pblot->aid[0] = pblot->aid[1] = -1;
        SW *psw = &B_003DD490; JOB *pjob = psw->pjob;
        if (pjob) {
            int idJob = pjob->id;
            if (idJob != -1) {
                phud->pblot->aid[0] = idJob;
                int kind = 1;
                asm("" : "+r"(kind));
                CStackFrame_Construct(&s);
                OrderTasks(&s.ctask, &s.aptask);
                qsort(s.aptask, s.ctask, 4, func_00165C28);
                for (int i = 0; i < s.ctask; i++) {
                    TASK *ptask = s.aptask[i];
                    if (psw->pjob == ptask->pjob && ptask->id != -1 && !FTaskComplete(ptask)) {
                        phud->pblot->aid[kind] = ptask->id;
                        break;
                    }
                }
                CStackFrame_Destructor(&s, 2);
            }
        }
    }
}
