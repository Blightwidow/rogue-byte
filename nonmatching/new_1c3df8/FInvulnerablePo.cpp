extern "C" int FSwHandsOff();

extern "C" int g_grfcht_2e1e00;

extern "C" int FInvulnerablePo(char* ppo)
{
    if ((g_grfcht_2e1e00 & 1) == 0 && FSwHandsOff(0) == 0)
        return 0;
    return 1;
}