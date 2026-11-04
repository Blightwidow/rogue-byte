#include "m2c_macros.h"

M2C_UNK CRef_Destruct(void *);                      /* extern */
M2C_UNK *PchzStringFromId(M2C_UNK *, M2C_UNK);      /* extern */
M2C_UNK RefGetGameSaveValue(void *, s32, void *, void *); /* extern */
s32 func_001B0078(M2C_UNK *);                       /* extern */
s32 func_001B0108(M2C_UNK *);                       /* extern */
M2C_UNK strcat(s32, M2C_UNK *);                     /* extern */
M2C_UNK strcpy(s32, M2C_UNK *);                     /* extern */
extern M2C_UNK B_002E6604;
extern M2C_UNK B_003D9ED0;
extern M2C_UNK B_003D9EDC;
extern M2C_UNK B_003DD490;

void func_001ADA20(s32 arg0) {
    char sp[0x400];
    M2C_UNK sp4;
    M2C_UNK var_a1;
    s32 temp_v0;
    void *temp_a3;

    if (func_001B0108(&B_003D9ED0) != 0) {
        temp_a3 = (M2C_FIELD(&B_003D9ED0, s32 *, 0x24) * 0x1C) + &B_003D9EDC;
        RefGetGameSaveValue(sp, M2C_FIELD(&B_003DD490, s32 *, 0x3B1C), (M2C_FIELD(temp_a3, s32 *, 0x14) * 0x5464) + &B_002E6604, temp_a3);
        CRef_Destruct(sp);
        temp_v0 = func_001B0078(&B_003D9ED0);
        switch (temp_v0) {                          /* irregular */
        case 30:
            if (sp4 != 0.0f) {
                var_a1 = 0x25;
            } else {
block_11:
                var_a1 = 0x26;
            }
block_12:
            strcpy(arg0, PchzStringFromId(&B_003DD490, var_a1));
            return;
        case 31:
            if (sp4 != 0.0f) {
                var_a1 = 0x27;
            } else {
                goto block_11;
            }
            goto block_12;
        case 25:
            strcpy(arg0, PchzStringFromId(&B_003DD490, 0x29));
            if (sp4 != 0.0f) {
                strcat(arg0, "\n");
                strcat(arg0, PchzStringFromId(&B_003DD490, 0x25));
            }
            break;
        }
    }
}
