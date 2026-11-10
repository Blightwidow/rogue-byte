#include "types.h"

struct JOY {
    char pad[0x100C];
    s32 field_0x100C;
    s32 field_0x1010;
    char pad2[0xD4];
    s32 field_0x10E8;
};

s32 TriggerRumbleRumk__FP6RUMBLE4RUMKf(void *); /* extern */

void TriggerJoyRumbleRumk__FP3JOY4RUMKf(struct JOY *pjoy) {
    if ((pjoy->field_0x10E8 != 0) && (pjoy->field_0x1010 >= 3) && (pjoy->field_0x100C == 3)) {
        TriggerRumbleRumk__FP6RUMBLE4RUMKf((char *)pjoy + 0x10CC);
    }
}
