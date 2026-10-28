#include "sly2.h"
struct PO { char pad[0x184]; int unk184; };
struct MSGARGS { PO *psource; void *ptarget; };
struct GUARD { char pad[0xC]; void *field0C; };
struct STEPGUARD { char pad0[0x26C]; char goalstack[0x49C - 0x26C]; GUARD *pguard; };
extern "C" void HandlePoMessage(STEPGUARD *, int, MSGARGS *);
extern "C" void SetGuardDamageSource(GUARD *, PO *);
extern "C" void GoalStack_HandleMessage(void *, int, MSGARGS *);

void HandleStepguardMessage(STEPGUARD *pstepguard, int msg, MSGARGS *pargs)
{
    HandlePoMessage(pstepguard, msg, pargs);
    switch (msg) {
    case 4: {
        if (pargs->ptarget == pstepguard) {
            PO *psource = pargs->psource;
            if (psource->unk184 != 0)
                SetGuardDamageSource(pstepguard->pguard, psource);
        }
        break;
    }
    case 5: {
        if (pargs->ptarget == pstepguard) {
            GUARD *pguard = pstepguard->pguard;
            if ((void *)pargs->psource == pguard->field0C)
                SetGuardDamageSource(pguard, 0);
        }
        break;
    }
    }
    GoalStack_HandleMessage(pstepguard->goalstack, msg, pargs);
}
