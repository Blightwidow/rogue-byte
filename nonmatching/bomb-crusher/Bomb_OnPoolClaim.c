#include "m2c_macros.h"

M2C_UNK InferExpl(void *, void *);                  /* extern */
M2C_UNK SetSoCnstrForce(void *, M2C_UNK);           /* extern */
M2C_UNK SetSoCnstrTorque(void *, M2C_UNK);          /* extern */
M2C_UNK SetSoNoXpsAll(void *, M2C_UNK);             /* extern */
M2C_UNK func_001A58D0(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_001CB518();                            /* extern */

void Bomb_OnPoolClaim(void *arg0) {
    func_001CB518();
    M2C_FIELD(arg0, s32 *, 0x174) = 0;
    M2C_FIELD(arg0, f32 *, 0x154) = 3.4028235e38f;
    InferExpl(arg0, arg0);
    SetSoCnstrForce(arg0, 0);
    SetSoCnstrTorque(arg0, 0);
    SetSoNoXpsAll(arg0, 0);
    M2C_FIELD(arg0, s32 *, 0x1E8) = 0;
    func_001A58D0(arg0, 0, 0xF);
}
