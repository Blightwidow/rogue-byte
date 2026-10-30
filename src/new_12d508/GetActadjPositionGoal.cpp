#include "sly2.h"
struct VTBL { char pad[0x28]; short delta; short index; void (*fn)(void *, QW *, int); };
struct TARGET { char pad[0x18]; VTBL *vtbl; };
struct ACTADJ { char pad[0x1C]; TARGET *target; QW offset; };
extern "C" void GetActadjPositionGoal(ACTADJ *adj, QW *pos, int unused)
{
    TARGET *target = adj->target;
    VTBL *vtbl = target->vtbl;
    void (*fn)(void *, QW *, int) = vtbl->fn;
    fn((char *)target + vtbl->delta, pos, unused);
    if (pos != 0) {
        asm("lqc2 vf2, %1\n\tlqc2 vf1, %2\n\tvadd.xyzw vf1, vf1, vf2\n\tsqc2 vf1, %0" : "=m" (*pos) : "m" (adj->offset), "m" (*pos));
    }
}
