#include "m2c_macros.h"

f32 UNoise__Fi(s32 arg0) {
    s32 temp_a3;

    temp_a3 = (arg0 << 0xD) ^ arg0;
    return (f32) (((temp_a3 * ((temp_a3 * temp_a3 * 0x3D73) + 0xC0AE5)) + 0x5208DD0D) & 0x7FFFFFFF) * 4.656613e-10f;
}
