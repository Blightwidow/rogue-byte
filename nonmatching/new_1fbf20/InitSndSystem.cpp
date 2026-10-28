#include "sly2.h"
extern "C" void snd_StartSoundSystem(int);
extern "C" void func_00233048(int, long, long, long, long, long, long);
extern "C" long TickReadCount(void *);
extern "C" char g_2dded0[];
struct SNDMGR { char pad[0x13C]; float grid[8][4]; float f1BC; float mix[4]; char pad2[0x20]; long t1F0; long t1F8; };
extern "C" SNDMGR B_003DD040;
void InitSndSystem()
{
    snd_StartSoundSystem(2);
    func_00233048(0x524B5553, 0L, 0L, 0L, 0L, 0L, 0L);
    B_003DD040.f1BC = 1.0f;
    short i; int j; for (i = 0; i < 4; i++) { B_003DD040.mix[i] = 1.0f; for (j = 7; j >= 0; j--) B_003DD040.grid[j][i] = 1.0f; }
    long t = TickReadCount(g_2dded0);
    B_003DD040.t1F8 = t;
    B_003DD040.t1F0 = t;
}
