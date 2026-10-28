/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct ITEM { int kind; char b[0x1C]; };
struct ITEMCOPY { char b[0x20]; };
struct PAUSE { char pad[0x20]; int blot; };
struct SCREEN { char pad[1]; };
struct MENUITEM { char pad[0x1C]; unsigned grf; };
extern "C" {
extern ITEM D_002BFEC8[];
extern ITEM B_002F6470[];
extern PAUSE B_003D9ED0;
extern SCREEN B_003DA530;
extern char D_002BFD38[];
int CGc_FFindScreen(SCREEN *);
void PauseMenu_Push(PAUSE *, int, ITEM *, int, void *);
void func_001AF390(PAUSE *, int, ITEM *);
}
void OpenOptionsMenu(MENUITEM *caller)
{
    ITEM *source = D_002BFEC8;
    ITEM *dest = B_002F6470;
    unsigned index = 0;
    do {
        int show = 1;
        switch (source->kind) {
        case 0x3D:
            break;
        case 0x3C:
            show = CGc_FFindScreen(&B_003DA530) != 0;
            break;
        case 0x3E:
            show = CGc_FFindScreen(&B_003DA530) == 0;
            break;
        }
        if (show) {
            *(ITEMCOPY *)dest = *(ITEMCOPY *)source;
            dest++;
        }
        index++;
        source++;
    } while (index < 11);
    if (caller) {
        func_001AF390(&B_003D9ED0, dest - B_002F6470, B_002F6470);
        caller->grf |= 2;
    } else {
        PauseMenu_Push(&B_003D9ED0, dest - B_002F6470, B_002F6470, B_003D9ED0.blot, D_002BFD38);
    }
}
