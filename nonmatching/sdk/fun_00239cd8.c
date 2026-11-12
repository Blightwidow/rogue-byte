#include "types.h"

typedef struct AlarmNode {
    struct AlarmNode *next;
    s32 field04;
    s32 field08;
    s32 field0C;
    s64 field10;
    s64 field18;
    s64 field20;
} AlarmNode;

typedef struct AlarmState {
    s64 field00;
    s64 field08;
    s64 field10;
    AlarmNode *head;
    s32 status;
} AlarmState;

extern AlarmState D_002C5A30;

void func_00239AC0(s32);
void func_00239AD0(s32);

void func_00239CD8(s64 arg0)
{
    AlarmState *state = &D_002C5A30;
    AlarmNode *cursor;
    s32 control;
    s32 slot;
    s64 bound;
    s64 candidate;

    if (state->status >= 0) {
        return;
    }
    cursor = state->head;
    control = *(volatile s32 *)0x10001010;
    if (cursor == 0) {
        func_00239AD0(0);
        func_00239AC0(control & 0xFFFFF7FF);
        return;
    }
    bound = cursor->field20 + cursor->field10 - cursor->field18;
    cursor = cursor->next;
    if (cursor != 0) {
        candidate = cursor->field20 + cursor->field10 - cursor->field18;
        if ((u64)candidate < (u64)(bound + 0x7333)) {
            bound = candidate;
            for (;;) {
                cursor = cursor->next;
                if (cursor == 0) {
                    break;
                }
                candidate = cursor->field20 + cursor->field10 - cursor->field18;
                if ((u64)candidate >= (u64)(bound + 0x7333)) {
                    break;
                }
                bound = candidate;
            }
        }
    }
    slot = control & 3;
    if (bound - arg0 < 0x7333) {
        func_00239AD0(*(volatile s32 *)0x10001000 + (s32)(0x7333 >> (slot << 2)));
        func_00239AC0(control & 0xFFFFF7FF);
        return;
    }
    func_00239AC0(control & 0xFFFFF7FF);
    func_00239AD0((s32)(bound >> (slot << 2)));
}
