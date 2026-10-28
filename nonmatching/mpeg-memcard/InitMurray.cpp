extern "C" void InitJt(void);
extern "C" void func_0020B840(char *, char *, int);
extern "C" void func_0020BD78(char *);
extern "C" void CarryThrow_Init(char *, char *);
extern "C" char *g_2f7900;

void InitMurray(char *arg0)
{
    char *temp_v0;

    InitJt();
    *(float *)(arg0 + 0x220) = 50.0f;
    *(int *)(arg0 + 0x17F4) = -1;
    *(float *)(arg0 + 0x1410) = 1500.0f;
    *(float *)(arg0 + 0x1414) = 3500.0f;
    *(float *)(arg0 + 0x103C) = 60.0f;
    *(float *)(arg0 + 0x1048) = 125.0f;
    *(int *)(arg0 + 0x13D8) = -1;
    *(int *)(arg0 + 0x1810) = -1;
    *(int *)(arg0 + 0x1840) = -1;
    *(int *)(arg0 + 0x13D0) = -1;
    *(int *)(arg0 + 0x144C) = -1;
    *(int *)(arg0 + 0x1450) = -1;
    *(int *)(arg0 + 0x1458) = -1;
    func_0020B840(arg0 + 0x1320, arg0, 0x15);
    func_0020B840(arg0 + 0x1460, arg0, 0x15);
    func_0020B840(arg0 + 0x1630, arg0, 0x15);
    func_0020B840(arg0 + 0x1540, arg0, 0x15);
    func_0020BD78(arg0 + 0x1850);
    temp_v0 = arg0 + 0x10A8;
    *(float *)(arg0 + 0x1434) = -60.0f;
    *(float *)(arg0 + 0x1098) = -100.0f;
    *(float *)(arg0 + 0x109C) = 100.0f;
    *(float *)(arg0 + 0x10A0) = 50.0f;
    *(float *)(arg0 + 0x10A4) = -10.0f;
    *(float *)(arg0 + 0x10A8) = 250.0f;
    *(float *)(arg0 + 0x1AC8) = -60.0f;
    *(float *)(temp_v0 + 0xC) = 4500.0f;
    *(float *)(temp_v0 + 8) = 1.0f;
    *(int *)(temp_v0 + 4) = 0;
    CarryThrow_Init(arg0 + 0x1910, arg0);
    *(int *)(arg0 + 0x1000) = 4;
    g_2f7900 = arg0;
}
