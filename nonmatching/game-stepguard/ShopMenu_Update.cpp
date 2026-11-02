struct CRef { int tagk; int n; int p2; int p3; CRef &operator=(const CRef &); };
struct SHOP { char pad0[0x10]; void *dev; char pad14[0x1C]; int dialog; char pad34[0xC]; int mode; };
struct GADGET { int pad0; int pad4; int price; char pad[0x14]; };
struct COINBAG { int amount; int b; int c; };
extern "C" {
void CRef_Destruct(CRef *);
int FJoyButtonPressed(void *, int);
int GetGameCoins(void *);
void Menu_SetDialog(void *, int, int);
void Menu_Update(void);
void Menu_UpdateStick(void *);
void *NewEmitter(int);
void SetEmitterUnpositioned(void *, void *);
void SetGadgetAcquired(int, int);
void SetGameCoins(void *, int, ...);
void ShopMenu_BuildList(void *);
void ShopMenu_SetPage(void *, int);
void ShopMenu_UpdateBlot(void *);
void func_0019F0A8(void *);
void func_001D8A38(CRef *, const char *, const char *, char *, int);
void func_001D8B20(CRef *, CRef *, const char *, const char *, char *, int);
int sprintf(char *, const char *, ...);
extern char B_002DEB30[];
extern char B_003DD490[];
extern GADGET D_002BCD00[];
extern COINBAG D_002C3288[];
extern const char RO_002A79A0[];
extern const char RO_002A79D0[];
extern const char RO_002A79D8[];
void ShopMenu_Update(SHOP *menu)
{
    Menu_Update();
    if (menu->mode == -1)
        return;
    void *dev = menu->dev;
    if (dev == 0)
        return;
    if (menu->dialog != 0 && FJoyButtonPressed(dev, 0x10)) {
        ShopMenu_SetPage(menu, -1);
        return;
    }
    switch (menu->mode) {
    case 0:
        if (FJoyButtonPressed(menu->dev, 0x40)) {
            int selected = *(int *)((char *)menu + 0x254);
            if (selected == -1) {
                SetEmitterUnpositioned(NewEmitter(0x36), 0);
            } else {
                int price = D_002BCD00[selected].price;
                int coins = GetGameCoins(B_002DEB30);
                if (menu->dialog == 0) {
                    Menu_SetDialog(menu, -1, -1);
                    SetGameCoins(B_002DEB30, coins - price);
                    SetGadgetAcquired(*(int *)((char *)menu + 0x254), 1);
                    ShopMenu_BuildList(menu);
                    SetEmitterUnpositioned(NewEmitter(0x29), 0);
                    func_0019F0A8(B_003DD490);
                } else if (coins >= price) {
                    Menu_SetDialog(menu, 0, 0x34);
                } else {
                    Menu_SetDialog(menu, 1, 0x35);
                }
            }
        }
        break;
    case 1:
        if (FJoyButtonPressed(menu->dev, 0x40)) {
            int slot = *(int *)((char *)menu + 0x258);
            if (slot == -1) {
                SetEmitterUnpositioned(NewEmitter(0x36), 0);
            } else {
                CRef ref;
                char name[0x20];
                CRef temp;
                ref.tagk = -1;
                sprintf(name, RO_002A79A0, slot);
                func_001D8A38(&temp, RO_002A79D0, RO_002A79D8, name, 0);
                ref = temp;
                CRef_Destruct(&temp);
                if (ref.n > 0) {
                    CRef count;
                    count.n = ref.n - 1;
                    count.tagk = 0x15;
                    func_001D8B20(&temp, &count, RO_002A79D0, RO_002A79D8, name, 0);
                    CRef_Destruct(&temp);
                    CRef_Destruct(&count);
                    SetGameCoins(B_002DEB30, GetGameCoins(B_002DEB30) + D_002C3288[*(int *)((char *)menu + 0x258)].amount, &D_002C3288[*(int *)((char *)menu + 0x258)]);
                    ShopMenu_BuildList(menu);
                    SetEmitterUnpositioned(NewEmitter(0x29), 0);
                }
                CRef_Destruct(&ref);
            }
        }
        break;
    }
    if (menu->dialog == 0) {
        if (FJoyButtonPressed(menu->dev, 0x10))
            Menu_SetDialog(menu, -1, -1);
    }
    if (FJoyButtonPressed(menu->dev, 0x80)) {
        Menu_SetDialog(menu, -1, -1);
        ShopMenu_SetPage(menu, menu->mode == 0);
    }
    if (menu->dialog != 0)
        Menu_UpdateStick(menu);
    ShopMenu_UpdateBlot(menu);
}
}
