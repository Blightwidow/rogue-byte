struct JOY { char pad[0x10B4]; unsigned grf; };
struct MENU { char pad0[0xC]; void *vt; JOY *pjoy; char pad1[0x24 - 0x14]; void *pblot; };
struct MENUITEM { int kind; void (*pfn)(MENUITEM *); int cSub; char pad[0x14]; };
struct SB { char pad[0x8000]; struct { char pad[0x7D50]; void *cur; void *sv; } t; };
extern SB B_002E65E0;
extern "C" {
void Menu_Update(MENU *);
int FJoyButtonPressed(JOY *, int);
int FJoyButtonPeek(JOY *, int);
void ConsumeJoyButton(JOY *, int);
void func_001ACC38(void *, int);
void StartGameFromSave(void *);
void StartNewGame(MENU *);
void OpenOptionsMenu(int);
int func_001A2C98();
void *PloFindSwObject_thunk(void *, int, int, int);
void func_001A2C48(int *, int **);
void *memset(void *, int, unsigned);
void PauseMenu_Push(void *, int, MENUITEM *, void *, void *);
void SelectLanguage(MENUITEM *);
extern char B_002E6550[];
extern char B_003DD490[];
extern char B_003D9ED0[];
extern MENUITEM B_003DA578[];
extern int D_002C35B8[];
extern char D_002C35F0[];
}

void TitleMenu_Update(MENU *menu)
{
    Menu_Update(menu);
    if (menu->pblot == 0 || menu->pjoy == 0)
        return;
    if (FJoyButtonPressed(menu->pjoy, 0x800)) {
        void *slot = B_002E65E0.t.sv;
        B_002E65E0.t.cur = slot;
        if (slot != 0) {
            func_001ACC38(B_002E6550, 1);
            StartGameFromSave(B_002E65E0.t.cur);
        } else {
            StartNewGame(menu);
        }
        return;
    }
    if (FJoyButtonPeek(menu->pjoy, 0x100) && (menu->pjoy->grf & 0x108) == 0x100) {
        ConsumeJoyButton(menu->pjoy, 0x100);
        OpenOptionsMenu(0);
        return;
    }
    if (func_001A2C98() < 2)
        return;
    if (FJoyButtonPressed(menu->pjoy, 0x10)) {
        void *blot = PloFindSwObject_thunk(B_003DD490, 5, 0x5D6, 0);
        if (blot != 0) {
            int clanguage;
            int *ailanguage;
            func_001A2C48(&clanguage, &ailanguage);
            for (int ilanguage = 0; ilanguage < clanguage; ilanguage++) {
                int language = ailanguage[ilanguage];
                MENUITEM *item = &B_003DA578[ilanguage];
                memset(item, 0, 0x20);
                int kind = D_002C35B8[language];
                item->cSub = language;
                item->pfn = SelectLanguage;
                item->kind = kind;
            }
            PauseMenu_Push(B_003D9ED0, clanguage, B_003DA578, blot, D_002C35F0);
        }
    }
}
