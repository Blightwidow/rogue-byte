#include "stepguard.h"
#include "types.h"
extern "C" {
s64 GrfsgsFromSgs(int);
s32 NGuardAlertLevel(STEPGUARD *arg0) {
    s64 grfs;
    if (arg0->grfsgs & GrfsgsFromSgs(7)) {
        return 2;
    }
    grfs = GrfsgsFromSgs(5);
    grfs |= GrfsgsFromSgs(6);
    if (arg0->grfsgs & grfs) {
        return 1;
    }
    return 0;
}
}
