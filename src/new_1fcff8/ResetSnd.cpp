typedef int QW __attribute__((mode(TI)));
struct Snd {
    char pad0[0x14];
    int f14;
    int f18;
    char pad1[0x68 - 0x1C];
    int f68;
};
extern "C" void snd_StopAllStreams();
extern "C" void func_00233048(unsigned, int, int, int, int, int, int);
extern "C" int snd_FlushSoundCommands();
extern "C" void ReplaceHitFx(int, QW, int, void *);
extern "C" void *memset(void *, int, unsigned);
extern "C" void func_00227788(void *);
extern "C" void func_00259B48(void *, int);
extern "C" void ResetSlotheap(void *);
void ClearDl__FP2DL(void *);
extern "C" void ResetSndbankVolumeFactors(void *);
extern "C" QW g_2a2dd0;
extern "C" char B_004435F0;

#define F(type, off) (*(type *)((char *)snd + (off)))

void ResetSnd(void *snd)
{
    snd_StopAllStreams();
    func_00233048(0x524B5553, 10, 0, 0, 0, 0, 0);
    int pending;
    do {
        pending = snd_FlushSoundCommands();
        asm volatile("nop\n\tnop");
    } while (pending != 0);
    F(int, 0x14) = 0;
    F(int, 0x18) = -1;
    F(int, 0x1D0) = 0;
    F(int, 0x5C) = 0;
    F(int, 0x60) = 0;
    F(int, 0x138) = 0;
    F(int, 0xEC) = 0;
    F(int, 0xF0) = 0;
    F(int, 0xF4) = 0;
    F(int, 0xF8) = 0;
    F(int, 0xFC) = 0;
    F(int, 0x100) = 0;
    ReplaceHitFx(0, g_2a2dd0, 0, (char *)snd + 0x74);
    memset((char *)snd + 0x108, 0, 0xC);
    func_00227788(&B_004435F0);
    func_00259B48((char *)snd + 0x200, 0);
    F(int, 0x204) = 0;
    memset((char *)snd + 0x208, 0, 0x20);
    func_00259B48((char *)snd + 0x228, 0);
    memset((char *)snd + 0x22C, 0, 0x18);
    F(int, 0x68) = 3;
    ResetSlotheap((char *)snd + 0x1C);
    ResetSlotheap((char *)snd + 0x34);
    ClearDl__FP2DL((char *)snd + 0x4C);
    ResetSndbankVolumeFactors(snd);
}
