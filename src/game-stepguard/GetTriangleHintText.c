#include "m2c_macros.h"

s32 PchzStringFromId(M2C_UNK *, M2C_UNK);           /* extern */
M2C_UNK strcat(s32, M2C_UNK *);                     /* extern */
M2C_UNK strcpy(s32, s32);                           /* extern */
extern M2C_UNK B_003DD490;

void GetTriangleHintText(s32 arg0) {
    strcpy(arg0, PchzStringFromId(&B_003DD490, 0x40));
    strcat(arg0, " : &2T&.");
}
