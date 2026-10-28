extern "C" int B_003D4A54;
extern "C" void InitPo(void);
extern "C" void InitHub(int hub)
{
    InitPo();
    B_003D4A54 = hub;
}
