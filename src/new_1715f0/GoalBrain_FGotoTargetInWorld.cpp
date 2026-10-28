#include "sly2.h"
struct BRAINDATA { char pad[0x28]; unsigned long flags; };
struct ACTOR { char pad[0xF68]; BRAINDATA *pdata; };
struct GOALBRAIN { char pad[0x10]; ACTOR *pactor; };
unsigned long GoalBrain_FGotoTargetInWorld(GOALBRAIN *pbrain)
{
    BRAINDATA *pdata = pbrain->pactor->pdata;
    unsigned long result = 0;
    if (pdata)
        result = (pdata->flags >> 60) & 1;
    return result;
}
