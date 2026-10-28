#include "m2c_macros.h"

s32 PchzStringFromId(M2C_UNK *, s32);               /* extern */
M2C_UNK strcpy(s32, s32);                           /* extern */
extern s32 B_003DA0D8;
extern M2C_UNK B_003DD490;

void BindTextMarquee(s32 arg0) {
    strcpy(arg0, PchzStringFromId(&B_003DD490, B_003DA0D8));
}
