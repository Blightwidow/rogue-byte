#include "types.h"

struct FlagObject {
    char pad0[0x24];
    s32 field_0x24;
};

s32 func_0020CA98(struct FlagObject *object) {
    return object->field_0x24 == 0;
}
