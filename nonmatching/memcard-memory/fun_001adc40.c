#include "m2c_macros.h"

M2C_UNK CRef_Destruct(void *);                      /* extern */
M2C_UNK CStackFrame_Construct(M2C_UNK *);           /* extern */
M2C_UNK CStackFrame_Destructor(M2C_UNK *, M2C_UNK); /* extern */
s32 NPercentCompleteSaveData(void *, void *);       /* extern */
s32 PchzStringFromId(M2C_UNK *, s32);               /* extern */
s32 PsavepathNewStack(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK RefGetGameSaveValue(void *, s32, void *);   /* extern */
s32 SidEpisodeName(f32);                            /* extern */
s32 func_001B0078(M2C_UNK *);                       /* extern */
M2C_UNK sprintf(s32, M2C_UNK *, s32, s32);          /* extern */
M2C_UNK strcpy(s32, s32);                           /* extern */
extern M2C_UNK B_002E6604;
extern M2C_UNK B_003D9ED0;
extern M2C_UNK B_003DD490;
extern M2C_UNK RO_002A6EC8;

void func_001ADC40(s32 arg0, s32 arg1) {
    char sp[0x400];
    M2C_UNK sp4;
    M2C_UNK sp10;
    s32 temp_s2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_a1;
    void *temp_s3;

    temp_s3 = (arg1 * 0x5464) + &B_002E6604;
    RefGetGameSaveValue(sp, M2C_FIELD(&B_003DD490, s32 *, 0x3B1C), temp_s3);
    CRef_Destruct(sp);
    if (sp4 == 0.0f) {
        temp_v0 = func_001B0078(&B_003D9ED0);
        if (temp_v0 != 0x19) {
            if ((temp_v0 >= 0x19) && (temp_v0 < 0x20) && (temp_v0 >= 0x1E)) {
                strcpy(arg0, PchzStringFromId(&B_003DD490, 0x44));
            }
        } else {
            strcpy(arg0, PchzStringFromId(&B_003DD490, 0x45));
        }
    } else {
        CStackFrame_Construct(&sp10);
        temp_v0_2 = PsavepathNewStack("episodeBest", 0);
        if (temp_v0_2 != 0) {
            var_a1 = temp_v0_2;
        } else {
            var_a1 = M2C_FIELD(&B_003DD490, s32 *, 0x3B28);
        }
        RefGetGameSaveValue(sp, var_a1, temp_s3);
        CRef_Destruct(sp);
        temp_s2 = PchzStringFromId(&B_003DD490, SidEpisodeName(sp4));
        sprintf(arg0, &RO_002A6EC8, temp_s2, NPercentCompleteSaveData(&B_003DD490 + 0x3A18, temp_s3));
        CStackFrame_Destructor(&sp10, 2);
    }
}
