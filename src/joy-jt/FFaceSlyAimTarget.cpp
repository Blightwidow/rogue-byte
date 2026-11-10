#include "sly.h"
extern "C" void func_002046F0(void *, TARGET *);
int FFaceSlyAimTarget(SLY *self)
{
    TARGET *target = self->ptarget;
    if (target) {
        func_002046F0(self, target);
        return 1;
    }
    return 0;
}
