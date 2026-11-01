#include "m2c_macros.h"

M2C_UNK AddAmbSlotSource(void *, M2C_UNK, s32, f32 *, M2C_UNK); /* extern */
void *NewStreamAmb(s32, M2C_UNK);                   /* extern */
M2C_UNK StopAmb(s32, void *, M2C_UNK);              /* extern */
s32 func_001FCFF8(void *, s32);                     /* extern */
M2C_UNK func_001FE478(void *, void *, s32);         /* extern */
M2C_UNK func_00259B48(void *, void *);              /* extern */
extern s32 g_2dd5bc;
extern s32 g_2e1e40;
extern s32 g_2f7900;

s32 QueueStream(void *arg0, s32 arg1) {
    char sp[0x400];
    M2C_UNK sp0;
    f32 sp10;
    s32 temp_s0;
    s32 temp_v0;
    s32 temp_v0_3;
    s32 temp_v0_5;
    s32 var_a0;
    void *temp_s0_2;
    void *temp_v0_2;
    void *temp_v0_4;
    void *temp_v0_6;

    func_001FE478(sp, arg0, arg1);
    temp_v0 = M2C_FIELD(arg0, s32 *, 0x204);
    if (temp_v0 > 0) {
        var_a0 = M2C_FIELD(((temp_v0 * 4) + arg0), s32 *, 0x204);
    } else {
        var_a0 = 0;
    }
    if (var_a0 != 0) {
        StopAmb(var_a0, sp0, 0);
    }
    if (sp0 != NULL) {
        temp_v0_2 = M2C_FIELD(sp0, void **, 0xC);
        M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, void *), 0x3C)(sp0 + M2C_FIELD(temp_v0_2, s16 *, 0x38), sp0);
        goto block_14;
    }
    temp_v0_3 = func_001FCFF8(arg0, arg1);
    if ((temp_v0_3 == 0) || (M2C_FIELD(arg0, s32 *, 0x204) == 8)) {
        if (sp0 == NULL) {
            return 0;
        }
        temp_v0_4 = M2C_FIELD(sp0, void **, 0xC);
        M2C_FIELD(temp_v0_4, M2C_UNK (**)(void *, void *), 0x14)(sp0 + M2C_FIELD(temp_v0_4, s16 *, 0x10), sp0);
        return 0;
    }
    func_00259B48(sp, NewStreamAmb(temp_v0_3, 4));
    sp10 = 2000.0f;
    M2C_FIELD(&sp10, f32 *, 4) = 5000.0f;
    AddAmbSlotSource(sp0, 3, g_2dd5bc, &sp10, 0x3F800000);
    AddAmbSlotSource(sp0, 3, g_2f7900, &sp10, 0x3F800000);
    AddAmbSlotSource(sp0, 4, g_2e1e40, &sp10, 0x3F800000);
block_14:
    temp_v0_5 = M2C_FIELD(arg0, s32 *, 0x204);
    temp_s0_2 = (temp_v0_5 * 4) + arg0;
    M2C_FIELD(arg0, s32 *, 0x204) = (s32) (temp_v0_5 + 1);
    func_00259B48(temp_s0_2 + 0x208, sp0);
    temp_s0 = M2C_FIELD(temp_s0_2, s32 *, 0x208);
    if (sp0 != NULL) {
        temp_v0_6 = M2C_FIELD(sp0, void **, 0xC);
        M2C_FIELD(temp_v0_6, M2C_UNK (**)(void *, void *), 0x14)(sp0 + M2C_FIELD(temp_v0_6, s16 *, 0x10), sp0);
    }
    return temp_s0;
}
