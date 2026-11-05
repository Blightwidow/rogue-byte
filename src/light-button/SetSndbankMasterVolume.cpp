struct SndBank { char pad0[0x1BC]; float masterVolume; };
extern char g_2bbb60[];
extern "C" float GLimitLm__FP2LMf(void *);
extern "C" void snd_SetMasterVolume(int, int);
extern "C" void SetSndbankMasterVolume(SndBank *self)
{
    float limited = GLimitLm__FP2LMf(g_2bbb60);
    int newVolume = (int)(limited * 1024.0f);
    int oldVolume = (int)(self->masterVolume * 1024.0f);
    if (oldVolume != newVolume) {
        self->masterVolume = limited;
        snd_SetMasterVolume(0x10, newVolume);
    }
}
