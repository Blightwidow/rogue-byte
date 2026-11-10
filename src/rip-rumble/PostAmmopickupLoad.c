#include "types.h"

struct AmmopickupObject {
    char pad0[0x160];
    s32 field_0x160;
    char field_0x164[4];
};

s32 PostSoLoad();
s32 SetAmmopickupState(void *, s32);
s32 func_001F1448(s32, void *, s32, s32, void *);

void PostAmmopickupLoad(struct AmmopickupObject *object) {
    PostSoLoad();
    func_001F1448(object->field_0x160, object, -1, 0, object->field_0x164);
    SetAmmopickupState(object, 0);
}
