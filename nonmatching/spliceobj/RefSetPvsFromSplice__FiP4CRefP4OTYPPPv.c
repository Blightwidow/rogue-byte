#include "m2c_macros.h"

M2C_UNK CRef_Destruct();                     /* extern */
M2C_UNK CRef_RefCoerceF32();        /* extern */
M2C_UNK CRef_RefCoerceS32();        /* extern */
M2C_UNK SetTag__4CRef4TAGK();           /* extern */
M2C_UNK __as__4CRefRC4CRef();       /* extern */

s32 RefSetPvsFromSplice__FiP4CRefP4OTYPPPv(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    char sp[0x400];
    M2C_UNK sp14;
    M2C_UNK sp4;
    s32 sp0;
    void *sp10;
    void *sp20;
    void *sp30;
    u8 *temp_v1;
    s32 var_a1;
    s32 var_s3;
    u32 temp_a1;
    void **temp_s2;

    var_s3 = 0;
    sp0 = -1;
    if (arg1 > 0) {
        var_a1 = 0 * 8;
        do {
            __as__4CRefRC4CRef(sp, arg2 + var_a1);
            temp_v1 = var_s3 * 4;
            temp_a1 = *(temp_v1 + arg3);
            temp_s2 = *(temp_v1 + M2C_ERROR(/* Read from unset register $t0 */));
            switch (temp_a1) {
            case 5:
            case 6:
            case 7:
            case 8:
            case 14:
            case 15:
            case 16:
            case 17:
            case 19:
            case 20:
            case 21:
                if (sp0 != 0x15) {
                    sp10 = (void *)-1;
                    CRef_RefCoerceS32(&sp20, sp);
                    __as__4CRefRC4CRef(&sp10, &sp20);
                    CRef_Destruct(&sp20);
                    M2C_FIELD(temp_s2, void **, 0) = sp14;
                    CRef_Destruct(&sp10);
                } else {
                case 0:
block_17:
block_18:
                    M2C_FIELD(temp_s2, void **, 0) = sp4;
                }
                break;
            case 1:
                if (sp0 == 0x16) {
                    M2C_FIELD(temp_s2, void **, 0) = sp4;
                } else {
                    sp10 = (void *)-1;
                    CRef_RefCoerceF32(&sp30, sp);
                    __as__4CRefRC4CRef(&sp10, &sp30);
                    CRef_Destruct(&sp30);
                    M2C_FIELD(temp_s2, void **, 0) = sp14;
                    CRef_Destruct(&sp10);
                }
                break;
            case 4:
                M2C_FIELD(temp_s2, void **, 0) = (s128) M2C_FIELD(sp4, s128 *, 0);
                M2C_FIELD(temp_s2, s128 *, 0x10) = (s128) M2C_FIELD(sp4, s128 *, 0x10);
                M2C_FIELD(temp_s2, s128 *, 0x20) = (s128) M2C_FIELD(sp4, s128 *, 0x20);
                break;
            case 2:
            case 9:
                M2C_FIELD(temp_s2, void **, 0) = (s128) M2C_FIELD(sp4, s128 *, 0);
                break;
            case 10:
                M2C_ERROR(/* unknown instruction: ldl $v1, 0x7($v0) */);
                M2C_ERROR(/* unknown instruction: ldr $v1, ($v0) */);
                M2C_ERROR(/* unknown instruction: sdl $v1, 0x7($s2) */);
                M2C_ERROR(/* unknown instruction: sdr $v1, ($s2) */);
                break;
            case 11:
                M2C_ERROR(/* unknown instruction: ldl $v1, 0x7($v0) */);
                M2C_ERROR(/* unknown instruction: ldr $v1, ($v0) */);
                M2C_ERROR(/* unknown instruction: sdl $v1, 0x7($s2) */);
                M2C_ERROR(/* unknown instruction: sdr $v1, ($s2) */);
                M2C_FIELD(temp_s2, s32 *, 8) = (s32) M2C_FIELD(sp4, s32 *, 8);
                break;
            default:
                if (temp_a1 & 0x8000) {
                    __as__4CRefRC4CRef(temp_s2, sp);
                } else if (!(temp_a1 & 0x1000)) {
                    if (temp_a1 & 0x2000) {
                        goto block_17;
                    }
                } else {
                    goto block_18;
                }
                break;
            }
            var_s3 += 1;
            var_a1 = var_s3 * 8;
        } while (var_s3 < arg1);
    }
    SetTag__4CRef4TAGK(arg0, 0x24);
    CRef_Destruct(sp);
    return arg0;
}
