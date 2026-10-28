#include "m2c_macros.h"

M2C_UNK RecalcClockRate();                          /* extern */
extern M2C_UNK g_2dded0;

void InitClock(s32 *arg0) {
    *arg0 = 0;
    M2C_FIELD(&g_2dded0, f32 *, 0x28) = 1.0f;
    M2C_FIELD(&g_2dded0, f32 *, 0x18) = 1.0f;
    M2C_FIELD(&g_2dded0, f32 *, 0x1C) = 1.0f;
    M2C_FIELD(&g_2dded0, f32 *, 0x20) = 1.0f;
    M2C_FIELD(&g_2dded0, f32 *, 0x2C) = 1.0f;
    M2C_FIELD(&g_2dded0, f32 *, 0x30) = 1.0f;
    M2C_FIELD(&g_2dded0, f32 *, 0x38) = 1.0f;
    M2C_FIELD(&g_2dded0, f32 *, 0x34) = 1.0f;
    RecalcClockRate();
}
