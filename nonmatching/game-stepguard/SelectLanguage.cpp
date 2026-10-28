extern "C" void func_001A2BD0(int);
extern "C" void RequestTransition(int, int, int, int, int, int);
void SelectLanguage(void *arg0)
{
    func_001A2BD0(*(int *)((char *)arg0 + 8));
    RequestTransition(0x3DD490, 0, 0x189, -1, 1, -1);
}