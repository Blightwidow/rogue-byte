struct DL { char *first; char *last; int offset; };
struct DLI { DL *list; char *current; int offset; DLI *next; };
struct SVT { char pad[0x58]; short delta; short index; void (*fn)(char *); };
struct SCR { char pad[0xC]; SVT *vt; };
extern DLI *g_2dd2fc;
extern int g_2dd318;
extern char B_003D9E80, B_003D9ED0, B_002E1E60, B_003DA0F0, B_003DA150, B_003DA0C0, B_003DA3C0, B_002E6550, B_002E65A0, B_003DA4F0, B_003DA530;
extern "C" {
void ReleaseMeter(void *);
void func_001AE970(void *);
void func_001A3070(void *);
void GadgetMenu_Reset(void *);
void ShopMenu_Reset(void *);
void InitHudLabel(void *);
void JobMenu_Reset(void *);
void MemcardMenu_Reset(void *);
void Menu_Reset(void *);
}

void CGc_Shutdown(DL *pdl)
{
    DLI dli;
    int offset = pdl->offset;
    char *item;
    g_2dd2fc = &dli;
    dli.next = g_2dd2fc;
    dli.offset = offset;
    item = pdl->first;
    dli.current = item + offset;
    dli.list = pdl;
    while (item != 0) {
        SVT *vt = ((SCR *)item)->vt;
        vt->fn(item + vt->delta);
        item = *(char **)dli.current;
        dli.current = item + dli.offset;
    }
    g_2dd318 = 0;
    ReleaseMeter(&B_003D9E80);
    func_001AE970(&B_003D9ED0);
    func_001A3070(&B_002E1E60);
    GadgetMenu_Reset(&B_003DA0F0);
    ShopMenu_Reset(&B_003DA150);
    InitHudLabel(&B_003DA0C0);
    JobMenu_Reset(&B_003DA3C0);
    MemcardMenu_Reset(&B_002E6550);
    Menu_Reset(&B_002E65A0);
    Menu_Reset(&B_003DA4F0);
    Menu_Reset(&B_003DA530);
    g_2dd2fc = dli.next;
}
