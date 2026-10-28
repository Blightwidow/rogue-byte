struct CRef { int tagk; int n; int p2; int p3; CRef &operator=(const CRef &); };
struct ENT { int id; int unk; };
struct SHOPMENU { char pad0[0x4C]; ENT aent[0x40]; char padx[0x250 - 0x4C - 0x40 * 8]; int ifirst; };
struct LOOT { int a; int sidName; int c; };
extern SHOPMENU B_003DA150;
extern char B_003DD490;
extern LOOT D_002C3288[];
extern "C" const char RO_002A79A0[];
extern "C" const char RO_002A79D0[];
extern "C" const char RO_002A79D8[];
extern "C" const char RO_002A7A30[];
extern "C" int sprintf(char *, const char *, ...);
extern "C" char *strcpy(char *, const char *);
extern "C" void func_001D8A38(CRef *, const char *, const char *, const char *, int);
extern "C" void CRef_Destruct(CRef *);
const char *PchzStringFromId(void *, int);

void GetLootRowName(char *pchz, int irow)
{
    int sid = -1;
    int cloot = 0;
    unsigned loot = B_003DA150.aent[B_003DA150.ifirst + irow].id;
    if (loot < 0x40) {
        CRef ref;
        ref.tagk = -1;
        char achzIndex[0x20];
        sprintf(achzIndex, RO_002A79A0, loot);
        CRef refResult;
        func_001D8A38(&refResult, RO_002A79D0, RO_002A79D8, achzIndex, 0);
        ref = refResult;
        CRef_Destruct(&refResult);
        sid = D_002C3288[loot].sidName;
        cloot = ref.n;
        CRef_Destruct(&ref);
    }
    if (sid != -1) {
        strcpy(pchz, PchzStringFromId(&B_003DD490, sid));
        if (1 < cloot)
            sprintf(pchz, RO_002A7A30, pchz, cloot);
    } else {
        pchz[0] = 0;
    }
}
