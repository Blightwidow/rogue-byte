#include "types.h"
s32 NRandRaw();

float GRandInRange(float low, float high) {
    s32 raw;
    float fraction;
    if (low == high) {
        return low;
    }
    raw = NRandRaw();
    fraction = (float)(raw % 92699);
    return low + (high - low) * fraction * 1.078760306e-05f;
}
