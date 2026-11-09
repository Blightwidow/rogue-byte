#include "types.h"
struct XfmObject {
    char pad0[0x38];
    f32 value;
};
extern "C" {
void PostLoLoad();
extern f32 RO_002C3C58;

void PostXfmObjectLoad(XfmObject *object)
{
    PostLoLoad();
    if (object->value == 1e10f) {
        object->value = RO_002C3C58;
    }
}
}
