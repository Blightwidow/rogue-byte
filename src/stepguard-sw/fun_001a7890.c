#include "m2c_macros.h"

M2C_UNK FlushCache(M2C_UNK);                        /* extern */
M2C_UNK func_00241728(s32 *, M2C_UNK *);            /* extern */
M2C_UNK func_002417F0(s32 *, M2C_UNK, M2C_UNK);     /* extern */
extern s32 *B_002DE590;
extern M2C_UNK RO_00259DF0;

void func_001A7890(void) {
    *B_002DE590 |= 0x40;
    FlushCache(0);
    func_00241728(B_002DE590, &RO_00259DF0);
    func_002417F0(B_002DE590, 0, 0);
    *B_002DE590 &= ~0x40;
}
