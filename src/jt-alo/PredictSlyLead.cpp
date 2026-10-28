#include "m2c_macros.h"

M2C_UNK PredictLoLead();                            /* extern */

void PredictSlyLead(void *arg0, s32 *arg1) {
    u32 temp_v1;

    PredictLoLead();
    temp_v1 = M2C_FIELD(arg0, u32 *, 0x18C8);
    switch (temp_v1) {
    case 0:
    case 1:
    case 5:
    case 10:
    case 12:
        *arg1 = 1;
        break;
    }
}
