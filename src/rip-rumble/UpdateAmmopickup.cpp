#include "types.h"
extern "C" {
struct AmmopickupObject {
    char pad0[0x58];
    struct AmmopickupTarget *field_0x58;
    char pad5C[0x150 - 0x5C];
    s32 field_0x150;
};
struct AmmopickupTarget {
    char pad0[0x98];
    s16 field_0x98;
};
void SetAmmopickupState(void *, s32);
void UpdateSo();

void UpdateAmmopickup(AmmopickupObject *object) {
    UpdateSo();
    if ((object->field_0x150 == 0) && (object->field_0x58->field_0x98 == 3)) {
        SetAmmopickupState(object, 1);
    }
}

}
