#include "m2c_macros.h"
extern "C" {

M2C_UNK CRef_ConstructVectorValue(void *, M2C_UNK); /* extern */
M2C_UNK CRef_CopyConstruct(s32, void *);            /* extern */
M2C_UNK CRef_Destruct(void *);                      /* extern */
M2C_UNK ConvertAloPos(s32, s32, s128);              /* extern */

s32 RefOpConvertObjectPosition(s32 arg0, s32 arg1, void *arg2) {
    char sp[0x10];
    ConvertAloPos(M2C_FIELD(arg2, s32 *, 4), M2C_FIELD(arg2, s32 *, 0xC), *M2C_FIELD(arg2, s128 **, 0x14));
    CRef_ConstructVectorValue(sp, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */));
    CRef_CopyConstruct(arg0, sp);
    CRef_Destruct(sp);
    return arg0;
}
}
