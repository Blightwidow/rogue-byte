// SPDX-License-Identifier: GPL-3.0-or-later
struct EMITTER1DC4B0;
struct MENU1DC4B0 { char pad0[0x28]; int direction; float directionTime; char pad1[0x48 - 0x30]; int count; char pad2[0x24C - 0x4C]; int index; };
extern "C" {
void ShopMenu_SetPage(MENU1DC4B0 *, int);
void ShopMenu_Select(MENU1DC4B0 *, int);
EMITTER1DC4B0 *NewEmitter(int);
void SetEmitterUnpositioned(EMITTER1DC4B0 *, int);
extern float g_2ddf0c[];
void ShopMenu_SetDirection(MENU1DC4B0 *menu, int direction)
{
    if (direction == menu->direction)
        return;
    menu->direction = direction;
    menu->directionTime = g_2ddf0c[0];
    switch (direction) {
    case 0:
        ShopMenu_SetPage(menu, 1);
        break;
    case 4:
        ShopMenu_SetPage(menu, 0);
        break;
    case 1:
    case 2:
    case 3: {
        int index = menu->index;
        if (index > 0) {
            ShopMenu_Select(menu, index - 1);
            SetEmitterUnpositioned(NewEmitter(0x35), 0);
        } else {
            SetEmitterUnpositioned(NewEmitter(0x36), 0);
        }
        break;
    }
    case 5:
    case 6:
    case 7: {
        int index = menu->index;
        if (index < menu->count - 1) {
            ShopMenu_Select(menu, index + 1);
            SetEmitterUnpositioned(NewEmitter(0x35), 0);
        } else {
            SetEmitterUnpositioned(NewEmitter(0x36), 0);
        }
        break;
    }
    }
}
}
