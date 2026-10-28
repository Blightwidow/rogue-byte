#include "m2c_macros.h"

M2C_UNK InitCplcy(void *);                          /* extern */
M2C_UNK InitCplcyCamobj(void *);                    /* extern */
M2C_UNK InitCplook(void *);                         /* extern */
M2C_UNK InitCpman(s32);                             /* extern */
M2C_UNK InitCptn(void *);                           /* extern */
M2C_UNK func_00150728(void *);                      /* extern */
M2C_UNK func_00151208(void *);                      /* extern */
M2C_UNK func_00151610(void *);                      /* extern */
M2C_UNK func_001518C8(void *);                      /* extern */
extern M2C_UNK D_002CA4D0;
extern M2C_UNK D_002CD378;

void *CM_Construct(void *arg0) {
    void *temp_s1;

    M2C_FIELD(arg0, s32 *, 0) = 0;
    temp_s1 = arg0 + 0x600;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0xC) = &D_002CA4D0;
    InitCpman(arg0 + 0x3A0);
    InitCptn(arg0 + 0x3B0);
    InitCplook(arg0 + 0x450);
    InitCplcyCamobj(arg0 + 0x4A8);
    func_00151208(arg0 + 0x4C0);
    func_00151610(arg0 + 0x500);
    func_00150728(arg0 + 0x520);
    func_001518C8(arg0 + 0x5F0);
    InitCplcy(temp_s1);
    M2C_FIELD(temp_s1, M2C_UNK **, 0xC) = &D_002CD378;
    return arg0;
}
