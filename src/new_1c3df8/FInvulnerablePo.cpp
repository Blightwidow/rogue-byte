extern "C" int FSwHandsOff(char *);
extern "C" char B_003DD490[];
extern "C" int g_2e1e00;

extern "C" int FInvulnerablePo(char *ppo)
{
    if ((g_2e1e00 & 1) != 0 || FSwHandsOff(B_003DD490)) return 1; return 0;
}
