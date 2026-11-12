#include "types.h"
#include "ps2inline.h"

extern "C" int FFloatsNear__Ffff(float, float, float);
static inline int Near(float a, float b) { return FFloatsNear__Ffff(a, b, 0.0001f); }
extern "C" QW bevy_classes_k30_cam_150780(void *);

int func_00150F58(char *self)
{
    QW a = *(QW *)(self + 0x20);
    QW b = bevy_classes_k30_cam_150780(self);
    int result = 0;
    if (Near(LaneX(a), LaneX(b))) {
        if (Near(LaneYInGeneralRegister(a), LaneYInGeneralRegister(b))) {
            result = Near(LaneZInGeneralRegister(a), LaneZInGeneralRegister(b)) != 0;
        }
    }
    return result;
}
