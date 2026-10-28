#include "sly2.h"
struct MEMCARD;
struct MENU { char pad[0x40]; int state; };
struct B8 { long v; } __attribute__((packed));
extern "C" {
void CreateMemcardThread__FP7MEMCARDii(MEMCARD *, long);
void MemcardMenu_SetState(MENU *, int);
void func_001AD3E0();
extern const B8 RO_002A6E88;
extern const B8 RO_002A6D88;
extern const B8 RO_002A6E90;
}
extern char B_002F633C[];
extern "C" void func_001AD168(MENU *pmenu)
{
    switch (pmenu->state) {
    case 0x1C:
        func_001AD3E0();
        break;
    case 0x12:
        CreateMemcardThread__FP7MEMCARDii((MEMCARD *)B_002F633C, RO_002A6E88.v);
        MemcardMenu_SetState(pmenu, 0x13);
        break;
    case 0x15:
        CreateMemcardThread__FP7MEMCARDii((MEMCARD *)B_002F633C, RO_002A6D88.v);
        MemcardMenu_SetState(pmenu, 0x16);
        break;
    case 0x20:
        CreateMemcardThread__FP7MEMCARDii((MEMCARD *)B_002F633C, RO_002A6E90.v);
        MemcardMenu_SetState(pmenu, 0x21);
        break;
    }
}
