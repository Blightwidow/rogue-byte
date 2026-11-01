// SPDX-License-Identifier: GPL-3.0-or-later
struct EMITTER1DD558;
struct MENU1DD558 { char pad0[0x28]; int direction; float directionTime; char pad1[0x48 - 0x30]; int count; char pad2[0x118 - 0x4C]; int index; };
extern "C" {
void JobMenu_SetPage(MENU1DD558 *, int);
void JobMenu_Select(MENU1DD558 *, int);
EMITTER1DD558 *NewEmitter(int);
void SetEmitterUnpositioned(EMITTER1DD558 *, int);
extern float g_2ddf0c[];
void JobMenu_SetDirection(MENU1DD558 *menu, int direction)
{
    if (direction == menu->direction)
        return;
    menu->direction = direction;
    menu->directionTime = g_2ddf0c[0];
    switch (direction) {
    case 0:
        if (menu->count != 0)
            JobMenu_SetPage(menu, 1);
        break;
    case 4:
        JobMenu_SetPage(menu, 0);
        break;
    case 1:
    case 2:
    case 3: {
        int index = menu->index;
        if (index > 0) {
            JobMenu_Select(menu, index - 1);
            SetEmitterUnpositioned(NewEmitter(0x35), 0);
        }
        break;
    }
    case 5:
    case 6:
    case 7: {
        int index = menu->index;
        if (index < menu->count - 1) {
            JobMenu_Select(menu, index + 1);
            SetEmitterUnpositioned(NewEmitter(0x35), 0);
        }
        break;
    }
    }
}
}
