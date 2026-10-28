#include "m2c_macros.h"

M2C_UNK PauseEmitterIndefinite__FP7EMITTER();       /* extern */
M2C_UNK UnpauseEmitter__FP7EMITTER(void *);         /* extern */

void SetEmitterEnabled__FP7EMITTERi(void *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0xF0);
    switch (temp_v0) {                              /* irregular */
    case -1:
        M2C_FIELD(arg0, s32 *, 0xF4) = arg1;
        break;
    case 0:
        if (arg1 == 0) {
            PauseEmitterIndefinite__FP7EMITTER();
        } else if (arg1 != -1) {
            M2C_FIELD(arg0, s32 *, 0xF4) = arg1;
        } else {
            UnpauseEmitter__FP7EMITTER(arg0);
        }
        break;
    }
    M2C_FIELD(arg0, s32 *, 0xE0) = 1;
}
