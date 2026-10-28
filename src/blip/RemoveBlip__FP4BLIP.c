#include "m2c_macros.h"

M2C_UNK AppendDlEntry(M2C_UNK *, void *);           /* extern */
M2C_UNK RemoveDlEntry(s32, void *);                 /* extern */
extern M2C_UNK B_002DEB00;

void RemoveBlip__FP4BLIP(void *arg0) {
    RemoveDlEntry(M2C_FIELD(arg0, s32 *, 0x108C) + 0x448, arg0);
    AppendDlEntry(&B_002DEB00, arg0);
}
