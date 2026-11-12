#include "ps2inline.h"
#include "sly2.h"

extern "C" int FFloatsNear__Ffff(float, float, float);
static inline int Near(float a, float b) { return FFloatsNear__Ffff(a, b, 0.0001f); }
extern "C" QW bevy_classes_k30_cam_1507f8(void *);

int func_00151018(char *self)
{
    QW b;
    QW a = *(QW *)(self + 0x30);
    b = bevy_classes_k30_cam_1507f8(self);
    int result = 0;
    if (Near(LaneX(a), LaneX(b))) {
        if (Near(LaneYInGeneralRegister(a), LaneYInGeneralRegister(b))) {
            result = Near(LaneZInGeneralRegister(a), LaneZInGeneralRegister(b)) != 0;
        }
    }
    return result;
}
