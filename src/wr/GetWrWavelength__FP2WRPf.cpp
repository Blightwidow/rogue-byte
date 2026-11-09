#include "types.h"

struct WrCircle {
    char pad0[0x64];
    f32 frequency;
};

struct WR;

extern "C" {
WrCircle *PwreGetWrCircle__FP2WR4ENSK(WR *, int);

f32 GetWrWavelength__FP2WRPf(WR *pwr, f32 *) {
    f32 frequency = PwreGetWrCircle__FP2WR4ENSK(pwr, 1)->frequency;
    f32 wavelength = 0.0f;
    if (frequency != 0.0f) {
        wavelength = 1.0f / frequency;
    }
    return wavelength;
}
}
