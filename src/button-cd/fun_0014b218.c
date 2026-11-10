#include "types.h"

struct GUARDREF {
    char pad[0xF64];
    s32 sgsGuard;
};

struct MSGARGS {
    struct GUARDREF *pguard;
    s32 value;
};

s32 FIsGuardInSgs(s32, s32);                    /* extern */
s32 HandleStepguardMessage();                   /* extern */
s32 func_00154038(s32, s32, s32);           /* extern */

void func_0014B218(s32 arg0, s32 arg1, struct MSGARGS *pmsgargs) {
    struct GUARDREF *pguard;

    HandleStepguardMessage();
    if ((FIsGuardInSgs(arg0, 0x24) == 0) && (arg1 == 0xB)) {
        pguard = pmsgargs->pguard;
        if ((s32)pguard == arg0) {
            func_00154038(pguard->sgsGuard, pmsgargs->value, 1);
        }
    }
}
