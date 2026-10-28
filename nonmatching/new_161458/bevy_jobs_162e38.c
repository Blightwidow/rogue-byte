#include "m2c_macros.h"

s32 FSwLoadBusy(M2C_UNK *);                         /* extern */
s32 PdescHubOfCurrentEpisode();                     /* extern */
M2C_UNK RequestTransition(M2C_UNK *, s32, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK B_003DD490;

void bevy_jobs_162e38(s32 arg0) {
    M2C_FIELD(&B_003DD490, s32 *, 0x3B18) = arg0;
    if ((FSwLoadBusy(&B_003DD490) == 0) && (M2C_FIELD(&B_003DD490, s32 *, 0x3C84) == 0)) {
        RequestTransition(&B_003DD490, PdescHubOfCurrentEpisode(), 0x189, -1);
    }
}
