#include "sly2.h"

extern "C" void SetStepRadTarget(void *pstep, float rad);
extern "C" float atan2f(float y, float x);

void SetStepRadTargetDir(void *pstep, float dy, float dx)
{
    float rad = atan2f(dy, dx);
    SetStepRadTarget(pstep, rad);
}
