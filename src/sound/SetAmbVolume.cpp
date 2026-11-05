struct AMB { char pad[0x10]; float volume; };
struct LM;
extern LM g_2bbb60;
extern "C" float GLimitLm__FP2LMf(LM *);
extern "C" void SetAmbGrf(AMB *, int, int);
extern "C" void SetAmbVolume(AMB *pamb)
{
    float volume = GLimitLm__FP2LMf(&g_2bbb60);
    if ((int)(volume * 1024.0f) != (int)(pamb->volume * 1024.0f)) {
        pamb->volume = volume;
        SetAmbGrf(pamb, 0x10, 0x10);
    }
}
