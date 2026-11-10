#include "so.h"
struct XA { char pad[4]; SO *target; };
void AddWaterExternalAccelerations(void *water, XA *xa, float dt)
{
    SO *target = xa->target;
    target->Slot72(water, dt);
}
