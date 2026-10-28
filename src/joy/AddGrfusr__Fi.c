#include "m2c_macros.h"

M2C_UNK UpdateGrfjoytFromGrfusr__Fv();              /* extern */
extern s32 B_002DFBC4;

void AddGrfusr__Fi(s32 arg0) {
    B_002DFBC4 |= arg0;
    UpdateGrfjoytFromGrfusr__Fv();
}
