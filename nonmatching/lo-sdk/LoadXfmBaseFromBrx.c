#include "m2c_macros.h"

M2C_UNK CBinaryInputStream_ReadMatrix4(s32, void *); /* extern */
M2C_UNK InvalidateXfmMatWorld(void *);              /* extern */
s32 S16Read__18CBinaryInputStream(s32);             /* extern */
M2C_UNK SetLoGrfzon(void *, s32);                   /* extern */
s32 U32Read__18CBinaryInputStream(s32);             /* extern */

void LoadXfmBaseFromBrx(void *arg0, s32 arg1) {
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(arg0, s32 *, 0x50) = M2C_FIELD(temp_v1, s32 (**)(void *, s32), 0x18C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x188), S16Read__18CBinaryInputStream(arg1));
    CBinaryInputStream_ReadMatrix4(arg1, arg0 + 0x60);
    InvalidateXfmMatWorld(arg0);
    SetLoGrfzon(arg0, U32Read__18CBinaryInputStream(arg1));
}
