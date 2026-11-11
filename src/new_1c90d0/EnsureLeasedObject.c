#include "types.h"

void PloLeaseCloneObject(s32, s32);
s32 PloLeased();

void EnsureLeasedObject(s32 arg0) {
    if (PloLeased() == 0) {
        PloLeaseCloneObject(arg0, 1);
    }
}
