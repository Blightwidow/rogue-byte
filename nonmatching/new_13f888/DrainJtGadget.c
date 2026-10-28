#include "m2c_macros.h"

M2C_UNK DrainJtPower(s32, f32);                     /* extern */
extern f32 D_FLT_002BD260;
extern f32 D_FLT_002BD264;

void DrainJtGadget(s32 arg0, s32 *arg1) {
    s32 temp_a1;

    temp_a1 = *arg1;
    switch (temp_a1) {                              /* irregular */
    case 29:
        DrainJtPower(temp_a1, D_FLT_002BD260);
        return;
    case 42:
        DrainJtPower(temp_a1, D_FLT_002BD264);
        break;
    }
}
