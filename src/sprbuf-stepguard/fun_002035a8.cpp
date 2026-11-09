#include "types.h"
struct XfmObject {
    char pad0[0xE0];
    float radius;
    float radiusDefault;
    float radiusScale;
    char pad1[0xF4 - 0xEC];
    s32 limitDefault;
    s32 limit;
    char pad2[0x104 - 0xFC];
    float range;
};
extern "C" void LoadXfmFromBrx(XfmObject *);
extern "C" void func_002035A8(XfmObject *object)
{
    *(s32 *)&object->radiusDefault = 0;
    object->radius = 75.0f;
    object->radiusScale = 0.25f;
    object->range = 5000.0f;
    LoadXfmFromBrx(object);
    if (object->radiusDefault == 0.0f) {
        object->radiusDefault = object->radius;
    }
    if (object->limit == -2) {
        object->limit = object->limitDefault;
    }
}
