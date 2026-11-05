#include "sly2.h"
struct SO;
struct SOV {
    char pad[0xF8];
    short delta;
    short idx;
    VECTOR *(*fn)(void *);
};
struct SO {
    char pad[0xC];
    SOV *vptr;
    char pad2[0x1D8 - 0x10];
    float radHeading;
};
extern "C" float atan2f(float, float);
float RadNormalize(float);
int FSlotSoFacingHeading(SO *pso)
{
    VECTOR *front = pso->vptr->fn((char *)pso + pso->vptr->delta);
    float rad = atan2f(front->y, pso->vptr->fn((char *)pso + pso->vptr->delta)->x);
    float err = RadNormalize(pso->radHeading - rad);
    float mag = __builtin_fabsf(err);
    return mag < 0.017453294f;
}
