#include "types.h"
extern "C" {
struct CloneSet {
    char pad0[0x18];
    s32 *field_0x18;
    char pad1c[0x6C - 0x1C];
};

s32 IcloneFromCloneId(...);
s32 IsetFromCloneId(s32);
extern CloneSet *B_003E1398;
s32 OidFromCloneId(s32 arg0) {
    CloneSet *cloneSet;
    if (IcloneFromCloneId() == -1) {
        return -1;
    }
    cloneSet = &B_003E1398[IsetFromCloneId(arg0)];
    return cloneSet->field_0x18[IcloneFromCloneId(arg0)];
}
}
