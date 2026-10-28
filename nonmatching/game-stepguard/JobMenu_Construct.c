#include "m2c_macros.h"

M2C_UNK JobMenu_InitPage(void *);                   /* extern */
M2C_UNK Menu_Construct();                           /* extern */
extern M2C_UNK D_002D8468;

void *JobMenu_Construct(void *arg0) {
    Menu_Construct();
    M2C_FIELD(arg0, s32 *, 0x20) = 0x4E0;
    M2C_FIELD(arg0, M2C_UNK **, 0xC) = &D_002D8468;
    JobMenu_InitPage(arg0);
    return arg0;
}
