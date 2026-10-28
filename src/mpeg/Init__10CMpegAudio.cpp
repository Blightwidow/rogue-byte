struct CByteQueue;
struct AUDIO { int state; int streamId; char hdr[0x28]; char queue0[0x20]; char queue1[0x50]; int vol2; int vol10; };
extern "C" void snd_PauseAllSoundsInGroup(unsigned);
extern "C" void StopStream(void *);
extern "C" void func_00227788(void *);
extern "C" void snd_StopAllStreams();
extern "C" int snd_FlushSoundCommands();
extern "C" void snd_StreamSafeCheckCDIdle(int);
extern "C" void snd_StreamSafeCdSync(int);
extern "C" int snd_GetMasterVolume(int);
extern "C" void snd_SetMasterVolume(int, int);
extern "C" void Init__10CByteQueueiPv(void *, int, void *);
extern char B_003DD040[];
extern char B_004435F0[];
struct G { char pad[0x110]; int pb; };
extern G B_002F66B0;

void Init__10CMpegAudio(AUDIO *self)
{
    snd_PauseAllSoundsInGroup(0xFFFFFFFF);
    StopStream(B_003DD040);
    func_00227788(B_004435F0);
    snd_StopAllStreams();
    int st;
    do {
        st = snd_FlushSoundCommands();
        asm("nop");
        asm("nop");
        asm("nop");
    } while (st != 0);
    snd_StreamSafeCheckCDIdle(1);
    snd_StreamSafeCdSync(0);
    self->vol2 = snd_GetMasterVolume(2);
    self->vol10 = snd_GetMasterVolume(0x10);
    snd_SetMasterVolume(2, 0x400);
    snd_SetMasterVolume(0x10, 0x400);
    self->state = 1;
    self->streamId = -1;
    Init__10CByteQueueiPv((char *)self + 0x30, 0x28, (char *)self + 8);
    Init__10CByteQueueiPv((char *)self + 0x50, 0x18000, (char *)(B_002F66B0.pb + 0x80000));
}
