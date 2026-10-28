#include "m2c_macros.h"

extern f32 g_2dded0;

void PauseEmitter__FP7EMITTERf(void *arg0, f32 fparg0) {
    M2C_FIELD(arg0, f32 *, 0x148) = (f32) (g_2dded0 + fparg0);
}
