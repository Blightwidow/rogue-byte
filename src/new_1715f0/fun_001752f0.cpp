// SPDX-License-Identifier: GPL-3.0-or-later
struct GUARD { char pad[0xF3C]; int fFlag; };
struct ANIM { char pad[8]; void *ptarget; };
struct GOAL { char pad[0x10]; GUARD *pguard; char pad2[0x2C]; ANIM *panim; char pad3[0xC]; int field_50; };
extern "C" int GoalAnim_FHandleMessage(GOAL *, int, int *);
extern "C" int func_00209518(void *);
extern "C" void EndJumperFlight(void *);
int func_001752F0(GOAL *pgoal, int nMsg, int *pmsg)
{
    if (nMsg == 9 && pgoal->panim != 0 && func_00209518(pgoal->panim) == pmsg[0]) {
        switch (pmsg[2]) {
        case 0x2d:
            pgoal->pguard->fFlag = 1;
            return 1;
        case 0x2e:
            pgoal->pguard->fFlag = 0;
            return 1;
        case 0x30:
            pgoal->field_50 = 0;
            EndJumperFlight(pgoal->panim->ptarget);
            return 1;
        }
    }
    return GoalAnim_FHandleMessage(pgoal, nMsg, pmsg);
}
