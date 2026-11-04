extern "C" void snd_PauseAllSoundsInGroup(unsigned int);
extern "C" void StopStream(void *);
extern "C" void func_00227788(void *);
extern "C" void snd_StopAllStreams(void);
extern "C" int snd_FlushSoundCommands(void);
extern "C" int snd_StreamSafeCheckCDIdle(int);
extern "C" int snd_StreamSafeCdSync(int);
extern "C" int snd_GetMasterVolume(int);
extern "C" void snd_SetMasterVolume(int, int);
extern "C" void Init__10CByteQueueiPv(void *, int, void *);
extern "C" char B_003DD040;
extern "C" char B_004435F0;
extern "C" char B_002F66B0;

void Init__10CMpegAudio(char *self)
{
    snd_PauseAllSoundsInGroup(0xFFFFFFFFu);
    StopStream(&B_003DD040);
    func_00227788(&B_004435F0);
    snd_StopAllStreams();
    while (snd_FlushSoundCommands() != 0) {
    }
    snd_StreamSafeCheckCDIdle(1);
    snd_StreamSafeCdSync(0);
    *(int *)(self + 0xA0) = snd_GetMasterVolume(2);
    *(int *)(self + 0xA4) = snd_GetMasterVolume(0x10);
    snd_SetMasterVolume(2, 0x400);
    snd_SetMasterVolume(0x10, 0x400);
    *(int *)(self + 0x0) = 1;
    *(int *)(self + 0x4) = -1;
    Init__10CByteQueueiPv(self + 0x30, 0x28, self + 0x8);
    Init__10CByteQueueiPv(self + 0x50, 0x18000,
                          (void *)(0x80000 + *(int *)(&B_002F66B0 + 0x110)));
}
