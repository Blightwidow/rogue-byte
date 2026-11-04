#include "sly2.h"
struct UL { unsigned long v; } __attribute__((packed));
extern "C" const UL RO_002A4E80;
extern "C" char B_003DD490[];
struct Link { int a; int b; };
struct Slot { char pad0[8]; void *first; void *second; char pad[0x30]; };
struct Child { Slot slot[2]; };
struct Pair2 { char pad[8]; };
struct Kid { char pad0[8]; int owner; int other; char pad10[0x8C]; int kind; char pad_a0[0xC]; Kid *nextKid; };
struct Group { Kid *firstKid; Group *next; };
struct Board { char pad[0x60]; int index; Group *groups; };
struct Gs { char pad[0x18C4]; int id; int mode; };
struct Button {
    char pad0[0xEC]; Board *board; char pad1[0x1E0 - 0xF0]; unsigned state; float timeA; float timeB;
    char pad2[0x2A8 - 0x1EC]; int mode; char pad3[0x2F4 - 0x2AC]; int id; int target;
};
extern "C" {
void UpdateSo(void);
void SetButtonButtons(Button *, unsigned);
int FCheckButtonObject(Button *, int);
void QueueSwCallbackOnce(void *, Button *, unsigned long, int);
}
extern Gs *g_2e1e40;
extern float g_2dded0;
extern "C" void UpdateButton(Button *button)
{
    UpdateSo();
    switch (button->state) {
    case 2:
        if (g_2e1e40 != 0 && g_2e1e40->mode == 3 && g_2e1e40->id == button->id)
            button->timeA = g_2dded0;
        {
            float time = button->timeB;
            if (time >= 0.0f && time < g_2dded0 - button->timeA)
                SetButtonButtons(button, 4);
        }
        break;
    case 3:
    default:
        break;
    case 4: {
        int buttons = -1;
        switch (button->mode) {
        case 0: case 2: case 3: buttons = 1; break;
        case 1: buttons = 0; break;
        }
        if (buttons != -1) SetButtonButtons(button, buttons);
        break;
    }
    case 0:
    case 1: {
        unsigned buttons = button->state;
        switch (button->mode) {
        case 1:
        case 2:
            break;
        case 3:
            buttons = 0;
            if (g_2e1e40 != 0) {
                if (g_2e1e40->mode == 3)
                    buttons = g_2e1e40->id == button->id;
            }
            break;
        case 0:
            Group *group = button->board->groups;
            buttons = 0;
            for (; group != 0; group = group->next) {
                for (Kid *kid = group->firstKid; kid != 0; kid = kid->nextKid) {
                    if (kid->kind == 10) continue;
                    int side = button->board->index != kid->owner;
                    int other = *(int *)((char *)kid + ((1 - side) << 6) + 8);
                    if (*(Button **)((char *)kid + (side << 6) + 0xC) == button && FCheckButtonObject(button, other)) {
                        button->target = other;
                        QueueSwCallbackOnce(B_003DD490, button, RO_002A4E80.v, 0);
                        buttons = button->state;
                        goto done;
                    }
                }
            }
            break;
        }
    done:
        SetButtonButtons(button, buttons);
        break;
    }
    }
}
