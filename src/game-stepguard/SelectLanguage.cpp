extern "C" void func_001A2BD0(int);
extern "C" void RequestTransition(void *, int, int, int, int, int);
extern "C" char B_003DD490;
void SelectLanguage(void *arg0)
{
    func_001A2BD0(*(int *)((char *)arg0 + 8));
    RequestTransition(&B_003DD490, 0, 0x189, -1, 1, -1);
}
