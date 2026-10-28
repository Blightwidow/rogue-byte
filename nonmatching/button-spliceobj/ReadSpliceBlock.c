#include "m2c_macros.h"

M2C_UNK CPairPtr_Destructor();          /* extern */
M2C_UNK CRef_Destruct();                       /* extern */
M2C_UNK FreeSlotheapPv();             /* extern */
M2C_UNK PpairSerializeIn();               /* extern */
void *PvAllocSwClearImpl__Fi();      /* extern */
s32 PvAllocSwImpl__Fi();                  /* extern */
M2C_UNK RunSpliceBlockEntry(); /* extern */
s32 U32Read__18CBinaryInputStream();             /* extern */
M2C_UNK Unknown1__18CBinaryInputStream();        /* extern */
M2C_UNK UnlinkPairNode();                        /* extern */
M2C_UNK func_00128148();                   /* extern */
extern s32 B_003E1C34;
extern M2C_UNK B_004520A8;
extern M2C_UNK g_2dd598;

void ReadSpliceBlock(void *arg0, s32 arg1, s32 arg2) {
    char sp[0x400];
    u8 *sp10;
    s32 temp_v0;
    s32 temp_v0_3;
    s32 var_a3;
    s32 var_s1;
    s32 var_s1_2;
    void *temp_s0;
    void *temp_v0_2;

    temp_v0 = U32Read__18CBinaryInputStream(arg2);
    if (temp_v0 != 0) {
        var_s1 = 0;
        temp_v0_2 = PvAllocSwClearImpl__Fi(sp, 0x10, 0x10);
        M2C_FIELD(temp_v0_2, s32 *, 0) = arg1;
        M2C_FIELD(temp_v0_2, s32 *, 4) = temp_v0;
        sp10 = temp_v0 * 8;
        M2C_FIELD(&sp10, s32 *, 4) = 0x10;
        M2C_FIELD(temp_v0_2, s32 *, 8) = PvAllocSwImpl__Fi(&sp10, -1);
        if (temp_v0 > 0) {
loop_3:
            temp_s0 = M2C_FIELD(temp_v0_2, s32 *, 8) + (var_s1 * 8);
            PpairSerializeIn(&sp10, arg2);
            if (sp10 != 0) {
                *sp10 = (s32) (*sp10 + 1);
            }
            M2C_FIELD(temp_s0, s32 *, 0) = sp10;
            M2C_FIELD(temp_s0, s32 *, 4) = 0;
            if (B_003E1C34 != 0) {
                Unknown1__18CBinaryInputStream(arg2);
                Unknown1__18CBinaryInputStream(arg2);
                Unknown1__18CBinaryInputStream(arg2);
            }
            if (sp10 != 0) {
                temp_v0_3 = *sp10 - 1;
                *sp10 = temp_v0_3;
                if (temp_v0_3 == 0) {
                    CPairPtr_Destructor(sp10 + 0x10, 2);
                    CRef_Destruct(sp10 + 8);
                    UnlinkPairNode(sp10);
                    FreeSlotheapPv(&B_004520A8, sp10);
                }
            }
            var_s1 += 1;
            if (var_s1 < temp_v0) {
                goto loop_3;
            }
        }
        var_s1_2 = 0;
        if (temp_v0 > 0) {
            var_a3 = 0;
            do {
                RunSpliceBlockEntry(&sp10, arg0, temp_v0_2, var_a3);
                var_s1_2 += 1;
                CRef_Destruct(&sp10);
                var_a3 = var_s1_2;
            } while (var_s1_2 < temp_v0);
        }
        M2C_FIELD(arg0, void **, 0x39E8) = temp_v0_2;
        M2C_FIELD(temp_v0_2, void **, 0xC) = (void *) M2C_FIELD(arg0, void **, 0x39EC);
        M2C_FIELD(arg0, void **, 0x39EC) = temp_v0_2;
        func_00128148(&g_2dd598);
        CRef_Destruct(sp);
    }
}
