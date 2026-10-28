extern "C" void InitJt(void *);
extern "C" void func_0020B840(void *, void *, int);
extern "C" void bevy_player_p25_default(void *, void *);
extern "C" void Carry_Init(void *);
void SetStepSpinRatio__FP4STEPf(void *, float);
extern "C" void *g_2e1e40;
#define I(off) (*(int *)((char *)p + (off)))
#define F(off) (*(float *)((char *)p + (off)))
extern "C" void InitSly(void *p)
{
    InitJt(p);
    F(0x19AC) = 15.0f;
    I(0x18C8) = -1;
    I(0x18D8) = -1;
    I(0x18D0) = -1;
    func_0020B840((char *)p + 0x1320, p, 0x6F);
    func_0020B840((char *)p + 0x1C30, p, 0x6F);
    char *q = (char *)p + 0x10A8;
    F(0x1098) = -100.0f;
    F(0x109C) = 100.0f;
    F(0x10A0) = 50.0f;
    F(0x10A4) = -10.0f;
    F(0x10A8) = 250.0f;
    *(float *)(q + 8) = 1.0f;
    *(int *)(q + 4) = 0;
    *(float *)(q + 0xC) = 4500.0f;
    SetStepSpinRatio__FP4STEPf(p, 1.6f);
    I(0x1FB0) = 0x1A;
    I(0x1FBC) = 0x25;
    I(0x1FC8) = 0x26;
    I(0x1FD4) = 0x29;
    bevy_player_p25_default((char *)p + 0x1FF0, p);
    I(0x1000) = 1;
    F(0x1020) = 200.0f;
    I(0x264) = 0xC7;
    Carry_Init((char *)p + 0x17D0);
    g_2e1e40 = p;
}
