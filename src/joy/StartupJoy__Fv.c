#include "m2c_macros.h"

M2C_UNK InitCodes(M2C_UNK *);                       /* extern */
M2C_UNK InitJoy(M2C_UNK *, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK UpdateGrfjoytFromGrfusr__Fv();              /* extern */
M2C_UNK scePadInit(M2C_UNK);                        /* extern */
extern M2C_UNK B_002DDEC0;
extern M2C_UNK B_002DFC00;

void StartupJoy__Fv(void) {
    UpdateGrfjoytFromGrfusr__Fv();
    scePadInit(0);
    InitJoy(&B_002DFC00, 0, 0);
    InitCodes(&B_002DDEC0);
}
