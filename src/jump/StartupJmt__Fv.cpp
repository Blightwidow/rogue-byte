extern "C" void InitDl__FP2DLi(int, int);
extern "C" int StartupJmt__Fv(int dl)
{
    InitDl__FP2DLi(dl, 0x14);
    return dl;
}
