#include "sly2.h"
struct CRef { int tagk; float g; int p2; int p3; };
struct SW { char pad[0x3B1C]; void *ppathDt; };
struct SS { char pad[0x24]; int icur; };
struct E { char pad[0x14]; int slot; char pad2[4]; };
extern SW B_003DD490;
extern SS B_003D9ED0;
extern E B_003D9EDC[];
extern char B_002E6604[];
extern "C" const char RO_STR_002A6ED8[];
extern "C" {
char *strcpy(char *, const char *);
char *strcat(char *, const char *);
void CRef_Destruct(CRef *);
void RefGetGameSaveValue(CRef *, void *, void *);
int func_001B0108(void *);
int func_001B0078(void *);
}
const char *PchzStringFromId(void *, int);

void func_001ADA20(char *pchz)
{
    SS *pss = &B_003D9ED0;
    if (func_001B0108(pss) == 0) return;
    CRef refDt;
    SW *psw = &B_003DD490;
    int  slot;
    RefGetGameSaveValue(&refDt, psw->ppathDt, B_002E6604 + slot * 0x5464);
    slot = B_003D9EDC[pss->icur].slot;
    float dt = refDt.g;
    CRef_Destruct(&refDt);
    int mode = func_001B0078(pss);
    switch (mode) {
    case 0x1E: {
        float zero;
        asm volatile("mtc1 $0,%0\n\tnop" : "=f"(zero));
        strcpy(pchz, PchzStringFromId(psw, (dt != zero) ? 0x25 : 0x26));
        break;
    }
    case 0x1F: {
        float zero;
        asm volatile("mtc1 $0,%0\n\tnop" : "=f"(zero));
        strcpy(pchz, PchzStringFromId(psw, (dt != zero) ? 0x27 : 0x26));
        break;
    }
    case 0x19: {
        strcpy(pchz, PchzStringFromId(psw, 0x29));
        float zero;
        asm volatile("mtc1 $0,%0\n\tnop" : "=f"(zero));
        if (dt == zero) return;
        strcat(pchz, RO_STR_002A6ED8);
        strcat(pchz, PchzStringFromId(psw, 0x25));
        break;
    }
    }
}
