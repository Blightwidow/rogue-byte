extern "C" {
void InitStep(void *);
void InitJmp(void *, void *);
void InitAttach(void *, void *);
void func_0019F3E8(void *, void *);
void InitJtZap(void *, void *);
void bevy_player_p15_binoc_default(void *, void *);
void CarryThrow_Init(void *, void *);
void InitJtPipe(void *, void *);
void func_00144638(void *, void *);
void SetAloInteract(void *, int, int);
}
void InitJt(char *jt)
{
    InitStep(jt);
    InitJmp(jt + 0x2C0, jt);
    InitAttach(jt + 0x4C0, jt);
    func_0019F3E8(jt + 0x9E0, jt);
    InitJtZap(jt + 0xDF0, jt);
    bevy_player_p15_binoc_default(jt + 0xF00, jt);
    CarryThrow_Init(jt + 0x11B0, jt);
    InitJtPipe(jt + 0xF50, jt);
    func_00144638(jt + 0xFD0, jt);
    *(float *)(jt + 0x103C) = 20.0f;
    *(float *)(jt + 0x1048) = 125.0f;
    *(float *)(jt + 0x10D4) = 1.0f;
    *(float *)(jt + 0x1138) = 1.5f;
    *(float *)(jt + 0x113C) = 2.5f;
    *(float *)(jt + 0x1140) = 3.0f;
    *(float *)(jt + 0x1144) = 5.0f;
    *(int *)(jt + 0x12F0) = 1;
    *(float *)(jt + 0x1020) = 100.0f;
    *(int *)(jt + 0x1300) = 100;
    *(float *)(jt + 0x1304) = -60.0f;
    *(int *)(jt + 0x10C8) = -1;
    *(int *)(jt + 0x10F0) = 1;
    *(float *)(jt + 0x10D8) = 1.0f;
    *(int *)(jt + 0x10EC) = -1;
    *(int *)(jt + 0x1318) = -1;
    *(int *)(jt + 0x10E4) = -1;
    SetAloInteract(jt, 0x3FFFFFF, 0);
    SetAloInteract(jt, 0x10FF00, 8);
}
