#include "m2c_macros.h"

s32 IEpisodeCurrent();                              /* extern */
s32 PchzStringFromId(M2C_UNK *, s32);               /* extern */
s32 SidEpisodeName(s32);                            /* extern */
M2C_UNK strcpy(s32, s32);                           /* extern */
extern M2C_UNK B_003DD490;

void GetEpisodeNameText(s32 arg0) {
    strcpy(arg0, PchzStringFromId(&B_003DD490, SidEpisodeName(IEpisodeCurrent())));
}
