#include "m2c_macros.h"

s128 ConvertAloPos(void *, M2C_UNK, s128);          /* extern */
M2C_UNK GetPathPosFromS(s32, void *, s128 *, f32);  /* extern */

void func_0019E950(void *arg0) {
    char sp[0x400];
    M2C_UNK sp0;
    s128 sp10;
    s128 sp20;
    void *temp_t2;
    void *temp_v0;

    GetPathPosFromS(M2C_FIELD(arg0, s32 *, 0xC), sp, &sp10, M2C_FIELD(arg0, f32 *, 0x10));
    temp_t2 = M2C_FIELD(arg0, void **, 0);
    M2C_ERROR(/* unknown instruction: por $t1, $zero, $v0 */);
    sp20 = ConvertAloPos(M2C_FIELD(arg0, void **, 0), 0, M2C_FIELD(arg0, s128 *, 0x30));
    temp_v0 = M2C_FIELD(temp_t2, void **, 0xC);
    M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK, s32, s128), 0x294)(temp_t2 + M2C_FIELD(temp_v0, s16 *, 0x290), 7, M2C_FIELD(arg0, s32 *, 0xC), sp0);
}
