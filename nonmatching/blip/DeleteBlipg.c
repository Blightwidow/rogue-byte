#include "m2c_macros.h"

M2C_UNK FreeSlotheapPv(void *, s32);                /* extern */
s32 PdlFromSwCid(M2C_UNK *, M2C_UNK);               /* extern */
M2C_UNK RemoveSlEntry(s32, s32);                    /* extern */
extern M2C_UNK B_003DD490;

void DeleteBlipg(s32 arg0) {
    RemoveSlEntry(PdlFromSwCid(&B_003DD490, 0x1C), arg0);
    FreeSlotheapPv(&B_003DD490 + 0x4070, arg0);
}
