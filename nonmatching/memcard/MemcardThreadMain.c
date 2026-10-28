#include "m2c_macros.h"

M2C_UNK ExitDeleteThread();                         /* extern */
M2C_UNK SignalSema(s32);                            /* extern */
M2C_UNK WaitSema(s32);                              /* extern */
M2C_UNK memset(void *, M2C_UNK, M2C_UNK);           /* extern */
extern M2C_UNK B_002E65E0;
extern s32 B_004425D8;

void MemcardThreadMain(void *arg0) {
    WaitSema(M2C_FIELD(arg0, s32 *, 0));
    M2C_FIELD(arg0, s32 *, 0x10) = M2C_FIELD(arg0, s32 (**)(void *), 0xC)(M2C_FIELD(arg0, s16 *, 8) + &B_002E65E0);
    memset(arg0 + 8, 0, 8);
    M2C_FIELD(arg0, s32 *, 4) = -1;
    B_004425D8 = -1;
    SignalSema(M2C_FIELD(arg0, s32 *, 0));
    ExitDeleteThread();
}
