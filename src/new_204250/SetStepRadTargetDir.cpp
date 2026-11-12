#include "ps2inline.h"
#include "sly2.h"

extern "C" void SetStepRadTarget(void *pstep, float rad);
extern "C" float atan2f(float y, float x);

void SetStepRadTargetDir(void *pstep, QW delta)
{
    float dy = LaneYInGeneralRegister(delta);
    float dx = LaneX(delta);
    SetStepRadTarget(pstep, atan2f(dy, dx));
}
