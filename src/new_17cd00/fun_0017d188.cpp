#include "sly2.h"
struct OWNER { char pad[0xF88]; float zRef; };
#include "goal.h"
struct GOAL_17D188 : GOAL {
    char pad_30[0x8];
    float z;
};
int func_0017D188(GOAL_17D188 *pgoal)
{
    float diff = ((OWNER *)pgoal->pstep)->zRef - pgoal->z;
    int result = 1;
    if (__builtin_fabsf(diff) < 50.0f) {
    } else
        result = 0;
    return result;
}
