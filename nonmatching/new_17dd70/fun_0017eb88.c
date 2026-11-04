#include "m2c_macros.h"

M2C_UNK FindCrvClosestPointAll(s32, M2C_UNK, M2C_UNK *, void *); /* extern */
M2C_UNK FindCrvClosestPointFromS(s32, M2C_UNK, M2C_UNK *, void *, f32); /* extern */
M2C_UNK PosLoWorld(s32);                            /* extern */
M2C_UNK func_0017ECF0(void *, M2C_UNK);             /* extern */
M2C_UNK func_001EEF70();                            /* extern */
void *func_00205438(s32, M2C_UNK);                  /* extern */
extern M2C_UNK B_003DD020;

void func_0017EB88(void *arg0) {
    void *temp_v0;
    void *temp_v0_2;

    func_001EEF70();
    if (M2C_FIELD(arg0, f32 *, 0x38) >= 0.0f) {
        PosLoWorld(M2C_FIELD(arg0, s32 *, 0x10));
        FindCrvClosestPointFromS(M2C_FIELD(arg0, s32 *, 0x30), M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */), &B_003DD020, arg0 + 0x40, M2C_FIELD(arg0, f32 *, 0x38));
    } else {
        PosLoWorld(M2C_FIELD(arg0, s32 *, 0x10));
        FindCrvClosestPointAll(M2C_FIELD(arg0, s32 *, 0x30), M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */), &B_003DD020, arg0 + 0x40);
    }
    temp_v0 = func_00205438(M2C_FIELD(arg0, s32 *, 0x10), 0xBA);
    M2C_FIELD(temp_v0, s32 *, 0xA8) = (s32) M2C_FIELD(arg0, s32 *, 0x50);
    M2C_FIELD(temp_v0, s32 *, 0xAC) = (s32) M2C_FIELD(arg0, s32 *, 0x54);
    M2C_FIELD(temp_v0, s32 *, 0xBC) = (s32) M2C_FIELD(arg0, s32 *, 0x58);
    func_0017ECF0(arg0, 1);
    temp_v0_2 = M2C_FIELD(temp_v0, void **, 0xC);
    M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *), 0x44)(temp_v0 + M2C_FIELD(temp_v0_2, s16 *, 0x40));
}
