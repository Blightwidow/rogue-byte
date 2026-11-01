extern int B_002DFBC4; extern int B_002E0CBC; extern int g_2dfbc0;
void UpdateGrfjoytFromGrfusr(void)
{
    int u = B_002DFBC4; if (u & 0x10) g_2dfbc0 = 5; else if (u & 0xC) g_2dfbc0 = 0; else if (u & 1) g_2dfbc0 = 5; else if (u & 2) g_2dfbc0 = 4; else g_2dfbc0 = 7;
    if (!(g_2dfbc0 & 2)) B_002E0CBC = 0xFFFF;
}
