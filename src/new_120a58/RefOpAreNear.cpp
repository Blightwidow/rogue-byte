#include "sly2.h"
struct CRef { int tagk; int n; };
struct CFrame;
extern "C" int FFloatsNear__Ffff(float, float, float);

extern "C" CRef *RefOpAreNear(CRef *result, int count, CRef *args, CFrame *frame)
{
    float values[3];
    for (int index = 0; index < 3; index++) {
        if (args[index].tagk == 0x15) {
            values[index] = (float)args[index].n;
        } else {
            values[index] = *(float *)&args[index].n;
        }
    }
    int near = FFloatsNear__Ffff(values[0], values[1], values[2]);
    result->tagk = 0x17;
    result->n = near != 0;
    return result;
}
