#include "m2c_macros.h"

s32 IEpisodeCurrent();                              /* extern */
M2C_UNK PdescFromEpisode(s32);                      /* extern */

void PdescHubOfCurrentEpisode(void) {
    PdescFromEpisode(IEpisodeCurrent());
}
