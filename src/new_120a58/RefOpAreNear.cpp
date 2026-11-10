#include "sly2.h"
#include "cref.h"
struct CFrame;
extern "C" int FFloatsNear__Ffff(float, float, float);

extern "C" CRef *RefOpAreNear(CRef *result, int count, CRef *args, CFrame *frame)
{
    float values[3];
    for (int index = 0; index < 3; index++) {
        if (args[index].m_tagk == TAGK_S32) {
            values[index] = (float)args[index].m_tag.m_n;
        } else {
            values[index] = *(float *)&args[index].m_tag.m_n;
        }
    }
    int near = FFloatsNear__Ffff(values[0], values[1], values[2]);
    result->m_tagk = TAGK_Bool;
    result->m_tag.m_n = near != 0;
    return result;
}
