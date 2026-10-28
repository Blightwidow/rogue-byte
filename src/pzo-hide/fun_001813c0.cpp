#include "sly2.h"
extern float D_002BE870[3];
struct GOAL { char pad[0x378]; float x; float y; float z; };
void func_001813C0(GOAL *pgoal, float scale)
{
    pgoal->x = D_002BE870[0] * scale;
    pgoal->y = D_002BE870[1] * scale;
    pgoal->z = D_002BE870[2];
}
