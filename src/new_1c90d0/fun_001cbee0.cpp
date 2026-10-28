#include "sly2.h"
struct RANGE { float lo; float hi; };
struct SENSE { char pad0[0x50]; int flag; float strength; RANGE range; };
struct TARGET { char pad[0x18]; int oid; };
struct STIM { char pad0[0x14]; SENSE *sense; char pad1[0x28]; TARGET *target; };
extern "C" int func_00208BE0(void *, STIM *);
extern "C" int func_001CBEE0(void *self, STIM *stim)
{
    SENSE *sense = stim->sense;
    RANGE saved = sense->range;
    float strength = sense->strength;
    if (sense->flag == 0 && stim->target != 0 && stim->target->oid == 0x246) {
        float doubled = strength + strength;
        float half = (saved.hi - saved.lo) * 0.5f;
        float mid = saved.lo + half;
        sense->range.hi = mid + (half + half);
        sense->strength = doubled;
        sense->range.lo = mid - (half + half);
    }
    int result = func_00208BE0(self, stim);
    sense->range = saved;
    sense->strength = strength;
    return result;
}
