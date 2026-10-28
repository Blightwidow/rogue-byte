#include "m2c_macros.h"

M2C_UNK CRef_ConstructClq();           /* extern */
M2C_UNK CRef_ConstructLm();       /* extern */
M2C_UNK CRef_ConstructVector();        /* extern */
f32 F32Read__18CBinaryInputStream();        /* extern */
s32 S16Read__18CBinaryInputStream();             /* extern */
s32 S32Read__18CBinaryInputStream();             /* extern */
M2C_UNK SetTag__4CRef4TAGK();        /* extern */
s32 U32Read__18CBinaryInputStream();             /* extern */
s32 U8Read__18CBinaryInputStream();              /* extern */

void *LoadRefFromBrx(void *arg0, u32 arg1, s32 arg2) {
    char sp[0x400];
    f32 *var_s0;
    f32 *var_s0_2;
    s32 temp_v0;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_v0;

    switch (arg1) {
    case 0:
        temp_v0 = U8Read__18CBinaryInputStream(arg2) != 0;
        M2C_FIELD(arg0, s32 *, 0) = 0x17;
        M2C_FIELD(arg0, s32 *, 4) = temp_v0;
        break;
    case 5:
    case 6:
        var_v0 = S32Read__18CBinaryInputStream(arg2);
block_15:
        M2C_FIELD(arg0, s32 *, 4) = var_v0;
        M2C_FIELD(arg0, s32 *, 0) = 0x15;
        break;
    case 1:
        M2C_FIELD(arg0, s32 *, 4) = M2C_BITWISE(s32, F32Read__18CBinaryInputStream(arg2));
        M2C_FIELD(arg0, s32 *, 0) = 0x16;
        break;
    case 7:
    case 14:
    case 15:
    case 16:
    case 17:
    case 19:
    case 20:
    case 21:
    case 23:
        var_v0 = S16Read__18CBinaryInputStream(arg2);
        goto block_15;
    case 9:
        var_s0 = sp;
        var_s1 = 2;
        do {
            var_s1 -= 1;
            *var_s0 = F32Read__18CBinaryInputStream(arg2);
            var_s0 += 4;
        } while (var_s1 >= 0);
        CRef_ConstructClq(arg0, sp);
        break;
    case 10:
        CRef_ConstructLm(arg0, sp, F32Read__18CBinaryInputStream(arg2, F32Read__18CBinaryInputStream(arg2)));
        break;
    case 2:
        var_s0_2 = sp;
        var_s1_2 = 2;
        do {
            var_s1_2 -= 1;
            *var_s0_2 = F32Read__18CBinaryInputStream(arg2);
            var_s0_2 += 4;
        } while (var_s1_2 >= 0);
        CRef_ConstructVector(arg0, sp);
        break;
    default:
        if (((s32) (arg1 & 0xFFFF7FFF) >> 0xC) == 1) {
            var_v0 = U32Read__18CBinaryInputStream(arg2);
            goto block_15;
        }
        SetTag__4CRef4TAGK(arg0, 0x24);
        break;
    }
    return arg0;
}
