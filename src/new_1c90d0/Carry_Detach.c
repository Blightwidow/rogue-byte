#include "types.h"

struct CARRY {
    char pad[0x94];
    s32 field_0x94;
    s32 field_0x98;
    s32 field_0x9C;
    s32 fAttached;
};

s32 func_0012E460(void *);                      /* extern */

void Carry_Detach(struct CARRY *pcarry) {
    if (pcarry->fAttached != 0) {
        func_0012E460(&pcarry->field_0x94);
        func_0012E460(&pcarry->field_0x98);
        func_0012E460(&pcarry->field_0x9C);
        pcarry->fAttached = 0;
    }
}
