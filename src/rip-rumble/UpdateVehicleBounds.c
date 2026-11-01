#include "m2c_macros.h"

s128 ConvertAloPos(void *, long, s128);
void ExtendSoBounds(void *, s128, f32);
void UpdateSoBounds(s8 *);

void UpdateVehicleBounds(void *arg0) {
    s32 index = 0;
    UpdateSoBounds(arg0);
    if (M2C_FIELD(arg0, s32 *, 0x190) > 0) {
        char *entry = (char *)arg0 + 0x1A0;
        do {
            s128 pos;
            index += 1;
            pos = ConvertAloPos(arg0, 0, M2C_FIELD(entry, s128 *, 0x50));
            ExtendSoBounds(arg0, pos, M2C_FIELD(entry, f32 *, 0x20));
            entry += 0x60;
        } while (index < M2C_FIELD(arg0, s32 *, 0x190));
    }
}
