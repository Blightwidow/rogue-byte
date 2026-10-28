#include "sly2.h"
struct GOAL { char pad[0x10]; void *pguard; char pad1[4]; GOAL *child; char pad2[0x30 - 0x1C]; int state; char pad3[0xC]; int pick; };
extern "C" {
void func_001EEF98(GOAL *);
int func_00209098(void *);
void func_0017B9C0(GOAL *);
void func_0017B8B0(GOAL *, int);
int func_001EF0A8(GOAL *);
int FGoalNoticeDone(GOAL *);
}
void func_0017BD78(GOAL *pgoal)
{
    func_001EEF98(pgoal);
    int fCan = func_00209098(pgoal->pguard);
    func_0017B9C0(pgoal);
    while (func_001EF0A8(pgoal) == 0) {
        int nState = pgoal->state;
        switch (nState) {
        case 0:
            if (fCan != 0)
                func_0017B8B0(pgoal, 2);
            else if (pgoal->pick != 0)
                func_0017B8B0(pgoal, 1);
            break;
        case 1:
            if (fCan != 0)
                func_0017B8B0(pgoal, 2);
            else if (pgoal->pick != 0) {
                if (pgoal->pick != pgoal->child->state) {
                    func_0017B8B0(pgoal, -1);
                    func_0017B8B0(pgoal, 1);
                } else if (FGoalNoticeDone(pgoal->child) != 0)
                    func_0017B8B0(pgoal, 0);
            } else
                func_0017B8B0(pgoal, 0);
            break;
        case 2:
            if (fCan == 0)
                func_0017B8B0(pgoal, 0);
            break;
        }
        if (nState == pgoal->state)
            break;
    }
}
