#include "sly2.h"
typedef int QW __attribute__((mode(TI)));
struct VEC { QW q[1]; };
struct BOMB { char pad0[0x5C]; int xf; char pad1[0x210 - 0x60]; int target; char pad2[0xC]; QW pos; int aseg; char handle[0x30]; int fActbank; int actbank; float gain; };
extern "C" void ApplyAsegToHandle(float, float, void *, BOMB *, unsigned, char *, VEC);
extern "C" int CreateXfActbank(BOMB *, int, float, float, int, int);
void FireMissile(BOMB *bomb, int target, QW *pos)
{
    QW value = *pos;
    bomb->target = target;
    bomb->pos = value;
    ApplyAsegToHandle(0.0f, 1.0f, (void *)bomb->aseg, bomb, 8, bomb->handle, *(VEC*)&value);
    if (bomb->fActbank != 0)
        bomb->actbank = CreateXfActbank(bomb, bomb->xf, bomb->gain, 0.0f, 0, 5);
}
