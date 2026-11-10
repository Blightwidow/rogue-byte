#include "m2c_macros.h"

struct LOLINK {
    char pad[0x10];
    struct LOLINK *plolinkParent;
    s32 field_0x14;
};

s32 func_001A53A0(void *);                      /* extern */
s32 func_001A53E0();                            /* extern */

void func_001A5B80(struct LOLINK *plolink, s32 arg1, s32 arg2) {
    if (plolink->plolinkParent != NULL) {
        if ((arg1 == (s32)plolink) && (arg2 == 0)) {
            func_001A53E0();
        }
        plolink->field_0x14 = (s32) plolink->plolinkParent->field_0x14;
        return;
    }
    if (arg2 != 0) {
        plolink->field_0x14 = 0;
        func_001A53A0(plolink);
    }
}
