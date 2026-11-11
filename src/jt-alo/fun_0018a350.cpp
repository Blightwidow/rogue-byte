#include "types.h"
#include "ps2inline.h"
struct HOLDER { char pad[0x18C4]; void *field_0x18C4; int field_0x18C8; };
extern "C" {
void func_00141588(HOLDER *, QW *);
QW PosLoWorld(void *);
}
void func_0018A350(HOLDER *pholder, QW *ppos)
{
    float *pcomponents = (float *)ppos;
    switch (pholder->field_0x18C8) {
    case 3:
        func_00141588(pholder, ppos);
        pcomponents[2] = FloatFromWord(LaneWordZ(PosLoWorld(pholder->field_0x18C4))) + -175.0f;
        break;
    case 0x16:
        func_00141588(pholder, ppos);
        pcomponents[2] = FloatFromWord(LaneWordZ(PosLoWorld(pholder->field_0x18C4))) + -100.0f;
        break;
    case 0x15:
        *ppos = PosLoWorld(pholder);
        break;
    default:
        func_00141588(pholder, ppos);
        break;
    }
}
