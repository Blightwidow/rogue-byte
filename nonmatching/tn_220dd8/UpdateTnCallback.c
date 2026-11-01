#include "m2c_macros.h"

M2C_UNK ConvertAloPos(M2C_UNK, void *, M2C_UNK);    /* extern */
s32 FIsBasicDerivedFrom(void *, M2C_UNK);           /* extern */
s32 PcgtPointInCbspQuick__FP4CBSPP6VECTOR(s32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK PosLoWorld(void *, s32);                    /* extern */
void *PpoSwFocus(M2C_UNK *);                        /* extern */
M2C_UNK SetTnTns__FP2TN3TNS(void *, s32);           /* extern */
extern s32 B_002DE240;
extern M2C_UNK B_003DD490;

void UpdateTnCallback(void *arg0) {
    s32 temp_a1;
    s32 var_s2;
    void *temp_v0;

    temp_v0 = PpoSwFocus(&B_003DD490);
    if (temp_v0 != NULL) {
        if (temp_v0 != M2C_FIELD(arg0, void **, 0xE0)) {
            SetTnTns__FP2TN3TNS(arg0, 0);
            M2C_FIELD(arg0, void **, 0xE0) = temp_v0;
        }
        temp_a1 = M2C_FIELD(arg0, s32 *, 0x13C);
        var_s2 = temp_a1;
        if (temp_a1 == -1) {
            PosLoWorld(temp_v0, temp_a1);
            ConvertAloPos(0, arg0, M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */));
            var_s2 = PcgtPointInCbspQuick__FP4CBSPP6VECTOR(M2C_FIELD(arg0, s32 *, 0x108), 0x7FFFFFFF, M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */)) != 0;
        }
        if (M2C_FIELD(arg0, s32 *, 0x124) == 0) {
            if ((FIsBasicDerivedFrom(temp_v0, 0x34) == 0) || (M2C_FIELD(temp_v0, s32 *, 0x2DC) == -1) || (B_002DE240 != 0) || (M2C_FIELD(arg0, s32 *, 0x13C) != -1)) {
                goto block_11;
            }
        } else {
block_11:
            SetTnTns__FP2TN3TNS(arg0, var_s2);
        }
    }
}
