#include "sly2.h"
extern "C" int FIgnoreSoIntersection();
extern "C" int func_00220498(char *, int, int);
extern "C" void func_001CC9A8(char *, int, int);

extern "C" void func_00144388(char *arg0, int arg1)
{
    int ignore = FIgnoreSoIntersection();
    int result = func_00220498(arg0 + 0x11B0, arg1, ignore);
    func_001CC9A8(arg0 + 0x900, arg1, result);
}
