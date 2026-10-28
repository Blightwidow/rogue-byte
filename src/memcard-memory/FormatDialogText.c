#include "m2c_macros.h"

s32 PchzStringFromId(M2C_UNK *, s32);               /* extern */
M2C_UNK strcpy(s32, s32);                           /* extern */
extern M2C_UNK B_003DD490;
extern s32 g_2e6590;

void FormatDialogText(s32 arg0) {
    strcpy(arg0, PchzStringFromId(&B_003DD490, g_2e6590));
}
