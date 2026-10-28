#include "sly2.h"
extern "C" void bevy_camera_follow_activity(void *, int, int);
extern "C" void EndJob(int);
extern "C" void CGc_Shutdown(void *);
extern "C" void func_001FF830(void *);
extern "C" void ClearDifficultySuckPaths_thunk(void *);
extern "C" void bevy_camera_cm_14d650(void *);
extern "C" void ResetSnd(void *);
extern "C" void func_001EC7E8();
struct RUMBLE; enum RUMS { R3 = 3 };
void SetRumbleRums(RUMBLE *, RUMS);
void FreeSw();
extern "C" char B_002DEB30[], B_003D9E70[], B_002DDF40[], B_003DD040[], B_002E0CCC[];
extern "C" int g_2e1e40, g_2f7900, g_2dd5bc, B_002DD648, B_003D4A54, B_002DE570, g_2dfb80, B_002DFBC4,
    B_003E1C40, B_003E1C44, B_003E1C48, B_003E1C4C, B_003E1C50, B_003DD48C;
void ShutdownSwForLoad(char *sw)
{
    bevy_camera_follow_activity(B_002DEB30, 1, 0);
    int job = *(int *)(sw + 0x3B18);
    if (job) {
        EndJob(job);
        *(int *)(sw + 0x3B18) = 0;
    }
    CGc_Shutdown(B_003D9E70);
    func_001FF830(sw);
    ClearDifficultySuckPaths_thunk(B_002DEB30);
    bevy_camera_cm_14d650(B_002DDF40);
    ResetSnd(B_003DD040);
    func_001EC7E8();
    SetRumbleRums((RUMBLE *)B_002E0CCC, R3);
    g_2e1e40 = 0;
    g_2f7900 = 0;
    g_2dd5bc = 0;
    B_002DD648 = 0;
    B_003D4A54 = 0;
    B_002DE570 = 0;
    g_2dfb80 = 0;
    B_002DFBC4 = 0;
    B_003E1C40 = 0;
    B_003E1C44 = 0;
    B_003E1C48 = 0;
    B_003E1C4C = 0;
    B_003E1C50 = 0;
    B_003DD48C = 0;
    FreeSw();
}
