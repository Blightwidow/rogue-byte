#include "m2c_macros.h"

M2C_UNK CPairPtr_Destructor();        /* extern */
M2C_UNK CRef_Destruct();                       /* extern */
M2C_UNK CRef_SetBasic();                  /* extern */
M2C_UNK CRef_SetBifk();                   /* extern */
M2C_UNK CRef_SetBool();                   /* extern */
M2C_UNK CRef_SetF32();                    /* extern */
M2C_UNK CRef_SetS32();                    /* extern */
M2C_UNK CRef_SetSymid();                  /* extern */
f32 F32Read__18CBinaryInputStream();             /* extern */
M2C_UNK FreeSlotheapPv();           /* extern */
M2C_UNK PairHandle_Assign();            /* extern */
M2C_UNK PairHandle_Init();             /* extern */
s32 *PpairNew();                              /* extern */
M2C_UNK S16Read__18CBinaryInputStream();         /* extern */
s32 S32Read__18CBinaryInputStream();             /* extern */
M2C_UNK SetTag__4CRef4TAGK();             /* extern */
s32 U32Read__18CBinaryInputStream();             /* extern */
u32 U8Read__18CBinaryInputStream();              /* extern */
M2C_UNK UnlinkPairNode();                      /* extern */
M2C_UNK bevy_splice_value_list_ref();   /* extern */
extern s32 B_003E1C34;
extern M2C_UNK B_004520A8;

s32 **PpairSerializeIn(s32 **arg0, s32 arg1) {
    char sp[0x400];
    u8 *sp0;
    s32 *sp10;
    f32 *temp_s0_10;
    f32 *temp_s0_2;
    f32 *temp_s0_4;
    f32 *temp_s0_6;
    f32 *temp_s0_8;
    s32 *temp_s1;
    s32 temp_s0_3;
    s32 temp_s0_5;
    s32 temp_s0_7;
    s32 temp_s0_9;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_s2_3;
    s32 var_s2_4;
    s32 var_s2_5;
    u32 temp_s0;
    u32 temp_v0;

    temp_v0 = U8Read__18CBinaryInputStream(arg1);
    if (temp_v0 == 0xFF) {
        PairHandle_Init(arg0, NULL);
    } else {
        PairHandle_Init(sp, PpairNew(arg0));
        if (B_003E1C34 != 0) {
            S32Read__18CBinaryInputStream(arg1);
            S16Read__18CBinaryInputStream(arg1);
            S16Read__18CBinaryInputStream(arg1);
            S16Read__18CBinaryInputStream(arg1);
            S16Read__18CBinaryInputStream(arg1);
            S16Read__18CBinaryInputStream(arg1);
            S16Read__18CBinaryInputStream(arg1);
        }
        temp_s0 = temp_v0 & 0x7F;
        temp_s1 = sp0 + 8;
        switch (temp_s0) {
        case 0:
        case 1:
        case 2:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 20:
            CRef_Destruct(temp_s1);
            SetTag__4CRef4TAGK(temp_s1, temp_s0);
            break;
        case 21:
            CRef_SetS32(temp_s1, S32Read__18CBinaryInputStream(arg1));
            break;
        case 22:
            CRef_SetF32(temp_s1, F32Read__18CBinaryInputStream(arg1));
            break;
        case 23:
            CRef_SetBool(temp_s1, U32Read__18CBinaryInputStream(arg1) != 0);
            break;
        case 33:
            CRef_SetBasic(temp_s1, U32Read__18CBinaryInputStream(arg1));
            break;
        case 24:
            CRef_SetSymid(temp_s1, U32Read__18CBinaryInputStream(arg1));
            break;
        case 25:
            CRef_SetBifk(temp_s1, U32Read__18CBinaryInputStream(arg1));
            break;
        case 26:
            var_s2 = 0;
            CRef_Destruct(temp_s1);
            SetTag__4CRef4TAGK(temp_s1, 0x1AU);
            do {
                temp_v0_2 = var_s2 * 4;
                var_s2 += 1;
                temp_s0_2 = M2C_FIELD(temp_s1, s32 *, 4) + temp_v0_2;
                *temp_s0_2 = F32Read__18CBinaryInputStream(arg1);
            } while (var_s2 < 3);
            break;
        case 27:
            var_s2_2 = 0;
            CRef_Destruct(temp_s1);
            SetTag__4CRef4TAGK(temp_s1, 0x1BU);
            do {
                temp_s0_3 = M2C_FIELD(temp_s1, s32 *, 4);
                temp_s0_4 = temp_s0_3 + (var_s2_2 * 4);
                var_s2_2 += 1;
                *temp_s0_4 = F32Read__18CBinaryInputStream(arg1);
            } while (var_s2_2 < 0x10);
            break;
        case 28:
            var_s2_3 = 0;
            CRef_Destruct(temp_s1);
            SetTag__4CRef4TAGK(temp_s1, 0x1CU);
            do {
                temp_s0_5 = M2C_FIELD(temp_s1, s32 *, 4);
                temp_s0_6 = temp_s0_5 + (var_s2_3 * 4);
                var_s2_3 += 1;
                *temp_s0_6 = F32Read__18CBinaryInputStream(arg1);
            } while (var_s2_3 < 3);
            break;
        case 29:
            var_s2_4 = 0;
            CRef_Destruct(temp_s1);
            SetTag__4CRef4TAGK(temp_s1, 0x1DU);
            do {
                temp_s0_7 = M2C_FIELD(temp_s1, s32 *, 4);
                temp_s0_8 = temp_s0_7 + (var_s2_4 * 4);
                var_s2_4 += 1;
                *temp_s0_8 = F32Read__18CBinaryInputStream(arg1);
            } while (var_s2_4 < 2);
            break;
        case 30:
            var_s2_5 = 0;
            CRef_Destruct(temp_s1);
            SetTag__4CRef4TAGK(temp_s1, 0x1EU);
            do {
                temp_s0_9 = M2C_FIELD(temp_s1, s32 *, 4);
                temp_s0_10 = temp_s0_9 + (var_s2_5 * 4);
                var_s2_5 += 1;
                *temp_s0_10 = F32Read__18CBinaryInputStream(arg1);
            } while (var_s2_5 < 3);
            break;
        case 31:
            PpairSerializeIn(&sp10, arg1);
            bevy_splice_value_list_ref(temp_s1, sp10);
            if (sp10 != NULL) {
                temp_v0_3 = *sp10 - 1;
                *sp10 = temp_v0_3;
                if (temp_v0_3 == 0) {
                    CPairPtr_Destructor(sp10 + 0x10, 2);
                    CRef_Destruct(sp10 + 8);
                    UnlinkPairNode(sp10);
                    FreeSlotheapPv(&B_004520A8, sp10);
                }
            }
            break;
        }
        if ((temp_v0 >> 7) & 0xFF) {
            PpairSerializeIn(&sp10, arg1);
            PairHandle_Assign(sp0 + 0x10, sp10);
            if (sp10 != NULL) {
                temp_v0_4 = *sp10 - 1;
                *sp10 = temp_v0_4;
                if (temp_v0_4 == 0) {
                    CPairPtr_Destructor(sp10 + 0x10, 2);
                    CRef_Destruct(sp10 + 8);
                    UnlinkPairNode(sp10);
                    FreeSlotheapPv(&B_004520A8, sp10);
                }
            }
        }
        PairHandle_Init(arg0, sp0);
        if (sp0 != NULL) {
            temp_v0_5 = *sp0 - 1;
            *sp0 = temp_v0_5;
            if (temp_v0_5 == 0) {
                CPairPtr_Destructor(sp0 + 0x10, 2);
                CRef_Destruct(sp0 + 8);
                UnlinkPairNode(sp0);
                FreeSlotheapPv(&B_004520A8, sp0);
            }
        }
    }
    return arg0;
}
