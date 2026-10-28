#include "sly2.h"
struct SAVE { char b[0x5408]; };
extern SAVE *g_2deb4c;
extern SAVE B_003D4A60;
extern "C" void StoreAudioModeInSave();
extern "C" void ApplyOptionsFromSave(SAVE *);
extern "C" void ApplyPendingSave()
{
    if (g_2deb4c != 0) {
        B_003D4A60 = *g_2deb4c;
        g_2deb4c = 0;
        StoreAudioModeInSave();
        ApplyOptionsFromSave(&B_003D4A60);
    }
}
