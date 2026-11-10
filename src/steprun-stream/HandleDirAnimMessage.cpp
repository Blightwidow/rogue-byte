#include "types.h"
extern "C" {
struct DirAnim {
    char pad0[0x34];
    s32 field_0x34;
    s32 field_0x38;
};
struct LoMessage {
    char pad0[8];
    s32 field_0x8;
};
void HandleLoMessage(DirAnim *, s32, LoMessage *);

void HandleDirAnimMessage(DirAnim *object, s32 message, LoMessage *arguments) {
    s32 code;

    if (message == 9) {
        code = arguments->field_0x8;
        switch (code) {
        case 0x180:
            object->field_0x38 = 0;
            break;
        case 0x17D:
            object->field_0x34 = 1;
            break;
        case 0x17E:
            object->field_0x34 = 0;
            break;
        case 0x17F:
            object->field_0x38 = 1;
            break;
        }
    }
    HandleLoMessage(object, message, arguments);
}

}
