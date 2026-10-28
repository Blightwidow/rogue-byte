extern "C" int B_002DFB4C;
extern "C" int B_002DFB58;
extern "C" void WaitSema(int);
void SyncVBlank(void)
{
    B_002DFB58 = 1;
    WaitSema(B_002DFB4C);
}
