#include "sly2.h"
extern float D_002BE870[3];
#include "goal.h"
struct GOAL_1813C0 : GOAL {
    char pad_30[0x348];
    float x;
    float y;
    float z;
};
void func_001813C0(GOAL_1813C0 *pgoal, float scale)
{
    pgoal->x = D_002BE870[0] * scale;
    pgoal->y = D_002BE870[1] * scale;
    pgoal->z = D_002BE870[2];
}
