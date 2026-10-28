// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct HUDLABEL { char pad[0x10]; unsigned state; int f14; int id; float value; int pendingId; float pendingValue; };
extern "C" void ClearHudLabel(HUDLABEL *, int);
extern "C" void SetHudLabelState(HUDLABEL *, int);
void ShowHudLabel(HUDLABEL *label, int id, float value) {
    if (id == -1) {
        ClearHudLabel(label, -1);
        return;
    }
    switch (label->state) {
    case 1:
        SetHudLabelState(label, -1);
    case 0:
    case 3:
        label->id = id;
        label->value = value;
        SetHudLabelState(label, 1);
        return;
    case 2:
        if (label->id == id) {
            label->value = value;
            return;
        }
    case 4:
        label->pendingId = id;
        label->pendingValue = value;
    }
}
