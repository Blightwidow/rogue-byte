#include "sly2.h"
#include "slotso.h"
extern "C" float atan2f(float, float);
float RadNormalize(float);
int FSlotSoFacingHeading(SLOTSO *pso)
{
    MATRIX4 *pmat = pso->PmatWorld();
    float rad = atan2f(pmat->mat[0][1], pso->PmatWorld()->mat[0][0]);
    float err = RadNormalize(pso->radHeading - rad);
    float mag = __builtin_fabsf(err);
    return mag < 0.017453294f;
}
