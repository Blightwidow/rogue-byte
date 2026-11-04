#include "m2c_macros.h"

M2C_UNK CRef_CopyConstruct(s32, void *);            /* extern */
M2C_UNK CRef_Destruct(void *);                      /* extern */
s32 FFindSaveVar(s32, s32, void **);                /* extern */
M2C_UNK SetTag__4CRef4TAGK(void *, M2C_UNK);        /* extern */

s32 RefSetSaveValue(s32 arg0, s32 arg1, s32 arg2, void *arg3) {
    char sp[0x400];
    M2C_UNK sp14;
    void *sp10;
    s32 temp_v0;
    s32 temp_v1;
    s8 temp_a0;
    u8 *temp_t0_2;
    void **temp_t0;

    SetTag__4CRef4TAGK(sp, 0x24);
    if (FFindSaveVar(arg1, arg2, &sp10) != 0) {
        temp_a0 = M2C_FIELD(sp10, s8 *, 2);
        if (temp_a0 != -1) {
            temp_t0 = M2C_ERROR(/* Read from unset register $t0 */) + M2C_FIELD(sp10, u16 *, 4);
            switch (temp_a0) {
            case 0:
            case 1:
            case 2:
            case 9:
            case 10:
                *((sp14 * 4) + temp_t0) = M2C_FIELD(arg3, void **, 4);
                break;
            case 3:
                *((sp14 * 4) + temp_t0) = M2C_FIELD(arg3, void **, 4);
                break;
            case 4:
                if (M2C_FIELD(sp10, u8 *, 3) != 0) {
                    temp_v0 = (s32) ((sp14 > -1) ? sp14 : (sp14 + 7)) >> 3;
                    temp_t0_2 = temp_t0 + temp_v0;
                    temp_v1 = (1 << (sp14 - (temp_v0 * 8))) & 0xFF;
                    if (M2C_FIELD(arg3, void **, 4) != NULL) {
                        *temp_t0_2 |= temp_v1;
                    } else {
                        *temp_t0_2 &= ~temp_v1;
                    }
                } else {
                    *temp_t0 = M2C_FIELD(arg3, void **, 4);
                }
                break;
            case 5:
            case 6:
                *((sp14 * 0x10) + temp_t0) = M2C_FIELD(M2C_FIELD(arg3, void **, 4), s128 *, 0);
                break;
            case 7:
                M2C_ERROR(/* unknown instruction: ldl $a0, 0x7($v1) */);
                M2C_ERROR(/* unknown instruction: ldr $a0, ($v1) */);
                M2C_ERROR(/* unknown instruction: sdl $a0, 0x7($v0) */);
                M2C_ERROR(/* unknown instruction: sdr $a0, ($v0) */);
                break;
            case 8:
                M2C_ERROR(/* unknown instruction: ldl $a2, 0x7($a0) */);
                M2C_ERROR(/* unknown instruction: ldr $a2, ($a0) */);
                M2C_ERROR(/* unknown instruction: sdl $a2, 0x7($v0) */);
                M2C_ERROR(/* unknown instruction: sdr $a2, ($v0) */);
                M2C_FIELD(((sp14 * 0xC) + temp_t0), s32 *, 8) = (s32) M2C_FIELD(M2C_FIELD(arg3, void **, 4), s32 *, 8);
                break;
            }
            CRef_CopyConstruct(arg0, sp);
            CRef_Destruct(sp);
        } else {
            goto block_4;
        }
    } else {
block_4:
        CRef_CopyConstruct(arg0, sp);
        CRef_Destruct(sp);
    }
    return arg0;
}
