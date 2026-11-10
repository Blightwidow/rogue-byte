#include "sly2.h"
extern "C" void func_001CB518(void *);
#include "goal.h"
struct GOAL_17F170 : GOAL {
    char pad_30[0x150];
    int a;
    int b;
};
void func_0017F170(GOAL_17F170 *pgoal)
{
    func_001CB518(pgoal);
    pgoal->b = pgoal->a;
}
