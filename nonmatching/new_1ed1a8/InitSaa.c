#include "m2c_macros.h"

M2C_UNK AppendSlEntry(M2C_UNK *, void *);           /* extern */
M2C_UNK InitSl(s32, M2C_UNK, void *);               /* extern */
M2C_UNK PrependSlEntry(M2C_UNK *, void *);          /* extern */
extern M2C_UNK B_003E159C;

void InitSaa(void *arg0, void *arg1) {
    M2C_FIELD(arg0, s32 *, 0x14) = (s32) M2C_FIELD(arg1, s32 *, 0);
    M2C_FIELD(arg0, s32 *, 0x18) = (s32) M2C_FIELD(arg1, s32 *, 4);
    M2C_FIELD(arg0, s32 *, 0x20) = (s32) M2C_FIELD(arg1, u16 *, 8);
    M2C_FIELD(arg0, s32 *, 0x1C) = (s32) M2C_FIELD(arg1, u16 *, 0xA);
    InitSl(arg0 + 0x34, 0x10, arg1);
    if (M2C_FIELD(arg0, s32 *, 0x30) == 0) {
        PrependSlEntry(&B_003E159C, arg0);
        return;
    }
    AppendSlEntry(&B_003E159C, arg0);
}
