#include "sly2.h"
extern "C" void Vif1InterruptHandler();
extern "C" void AddIntcHandler(int, void (*)(), int);
extern "C" void EnableIntc(int);
extern "C" int NewSema(int, int);
extern "C" int g_2deb18;
extern "C" int g_2deb1c;
extern "C" char B_002DEAF0[];
extern "C" char B_002DEB00[];
extern "C" int B_004425D4;
extern "C" void InitDl__FP2DLi(void *, int);
extern "C" void func_002355E0(int, int);

void StartupFrame()
{
    AddIntcHandler(5, Vif1InterruptHandler, 0);
    EnableIntc(5);
    g_2deb18 = NewSema(0, 2);
    g_2deb1c = NewSema(2, 2);
    InitDl__FP2DLi(B_002DEAF0, 0x454);
    InitDl__FP2DLi(B_002DEB00, 0x1090);
    func_002355E0(B_004425D4, 0);
}
