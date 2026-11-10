#include "sly.h"
extern "C" void func_002046F0(void *, int);
int FFaceSlyAimTarget(SLY *self)
{
    int target = self->field_0x18C0;
    if (target) {
        func_002046F0(self, target);
        return 1;
    }
    return 0;
}
