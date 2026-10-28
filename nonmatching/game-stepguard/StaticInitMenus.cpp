struct OBJ { int a; int b; int c; void *vt; };
extern "C" {
void StartupJmt__Fv(void *);
void GadgetMenu_Construct(void *);
void ShopMenu_Construct(void *);
void JobMenu_Construct(void *);
void func_001DD648(void *);
void TitleMenu_Construct(void *);
void CreateSlotheapSwAlign(void *, int, int, int);
void BASIC_Destruct(void *, int);
extern char B_003D9E70[];
extern OBJ B_003D9E80;
extern OBJ B_003D9ED0;
extern OBJ B_003DA0C0;
extern char B_003DA0F0[];
extern char B_003DA150[];
extern char B_003DA3C0[];
extern char B_003DA4F0[];
extern char B_003DA530[];
extern char D_002D8668[];
extern char D_002D37D0[];
extern char D_002CA490[];
extern int B_002DD2E0;
extern int B_002DD2E4;
extern int B_002DD2E8;
extern int B_002DD2EC;
extern int B_002DD2F0;
extern int B_002DD2F4;
extern char B_004520A8[];
extern char B_004520D0[];
extern char B_004520F8[];
extern char B_00452120[];
extern char B_00452148[];
extern char B_00452170[];
}

void StaticInitMenus(int init, int priority)
{
    if (priority != 0xFFFF)
        return;
    if (init != 0) {
        StartupJmt__Fv(B_003D9E70);
        B_003D9E80.vt = D_002D8668;
        B_003D9ED0.vt = D_002D37D0;
        B_003DA0C0.vt = D_002CA490;
        B_003D9E80.a = 0;
        B_003D9ED0.a = 0;
        B_003DA0C0.a = 0;
        B_003D9E80.b = 0;
        B_003D9ED0.b = 0;
        B_003DA0C0.b = 0;
        GadgetMenu_Construct(B_003DA0F0);
        ShopMenu_Construct(B_003DA150);
        JobMenu_Construct(B_003DA3C0);
        func_001DD648(B_003DA4F0);
        TitleMenu_Construct(B_003DA530);
        if (++B_002DD2E0 == 1)
            CreateSlotheapSwAlign(B_004520A8, 0x14, 0x2000, 0x10);
        if (++B_002DD2E4 == 1)
            CreateSlotheapSwAlign(B_004520D0, 0x18, 0x800, 0x10);
        if (++B_002DD2E8 == 1)
            CreateSlotheapSwAlign(B_004520F8, 0x28, 0x200, 0x10);
        if (++B_002DD2EC == 1)
            CreateSlotheapSwAlign(B_00452120, 0x1C, 0x800, 0x10);
        if (++B_002DD2F0 == 1)
            CreateSlotheapSwAlign(B_00452148, 0xC, 0xC8, 0x10);
        if (++B_002DD2F4 == 1)
            CreateSlotheapSwAlign(B_00452170, 0x14, 0x100, 0x10);
    } else {
        BASIC_Destruct(B_003DA530, 2);
        BASIC_Destruct(B_003DA4F0, 2);
        BASIC_Destruct(B_003DA3C0, 2);
        BASIC_Destruct(B_003DA150, 2);
        BASIC_Destruct(B_003DA0F0, 2);
        BASIC_Destruct(&B_003DA0C0, 2);
        BASIC_Destruct(&B_003D9ED0, 2);
        BASIC_Destruct(&B_003D9E80, 2);
    }
}
