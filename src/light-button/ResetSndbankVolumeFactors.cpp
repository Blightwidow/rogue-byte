#include "sly2.h"
extern "C" void SetSndbankMasterVolume(void *, float);
extern "C" void SetSndbankVolumeFactor(void *, int, int, float);
extern "C" void ResetSndbankVolumeFactors(void *psndbank)
{
    SetSndbankMasterVolume(psndbank, 1.0f);
    for (int icategory = 0; icategory < 8; icategory++) {
        if (icategory == 1)
            continue;
        for (int ichannel = 0; ichannel < 4; ichannel++)
            SetSndbankVolumeFactor(psndbank, ichannel, icategory, 1.0f);
    }
}
