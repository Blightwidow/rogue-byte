#include "m2c_macros.h"

M2C_UNK CRef_CopyConstruct();            /* extern */
M2C_UNK CRef_Destruct();                      /* extern */
M2C_UNK CRef_SetBool();        /* extern */
M2C_UNK CRef_SetClqPtr();             /* extern */
M2C_UNK CRef_SetF32();           /* extern */
M2C_UNK CRef_SetLmPtr();              /* extern */
M2C_UNK CRef_SetS32();                   /* extern */
M2C_UNK CRef_SetSmpPtr();             /* extern */
M2C_UNK CRef_SetVectorPtr();          /* extern */
s32 FFindSaveVar();           /* extern */

s32 RefGetSaveValue(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    char sp[0x400];
    M2C_UNK sp14;
    void *sp10;
    s32 *temp_t0;
    s32 temp_a2;
    s32 temp_a3;
    s32 temp_v0;
    s8 temp_a0;

    if (FFindSaveVar(arg1, arg2, &sp10, -1) != 0) {
        temp_a0 = M2C_FIELD(sp10, s8 *, 2);
        if (temp_a0 != -1) {
            temp_t0 = arg3 + M2C_FIELD(sp10, u16 *, 4);
            switch (temp_a0) {
            case 0:
            case 1:
            case 2:
            case 10:
                CRef_SetS32(sp, *((sp14 * 4) + temp_t0));
                break;
            case 3:
                CRef_SetF32(sp, sp10, *((sp14 * 4) + temp_t0));
                break;
            case 4:
                if (M2C_FIELD(sp10, u8 *, 3) != 0) {
                    temp_v0 = (s32) ((sp14 > -1) ? sp14 : (sp14 + 7)) >> 3;
                    temp_a2 = sp14 - (temp_v0 * 8);
                    temp_a3 = (1 << temp_a2) & 0xFF;
                    CRef_SetBool(sp, (*(temp_t0 + temp_v0) & temp_a3) != 0, temp_a2, temp_a3);
                } else {
                    CRef_SetBool(sp, *temp_t0, sp14);
                }
                break;
            case 5:
                CRef_SetVectorPtr(sp, temp_t0 + (sp14 * 0x10));
                break;
            case 6:
                CRef_SetClqPtr(sp, temp_t0 + (sp14 * 0x10));
                break;
            case 7:
                CRef_SetLmPtr(sp, temp_t0 + (sp14 * 8));
                break;
            case 8:
                CRef_SetSmpPtr(sp, (sp14 * 0xC) + temp_t0);
                break;
            case 9:
                CRef_SetS32(sp, *((sp14 * 4) + temp_t0));
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
