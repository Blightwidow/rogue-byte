struct CRef { int tagk; float g; int p2; int p3; };
struct JB { char pad[0x100C]; int a; int b; };
struct SLOTHOLDER { char pad[0x8000 + 0x7D54]; int pslot; };
struct SW { char pad[0x3B1C]; int ppathDt; };
extern JB B_002DFC00;
extern SLOTHOLDER B_002E65E0;
extern SW B_003DD490;
extern "C" const char RO_002A7A70[];
extern "C" char *strcpy(char *, const char *);
extern "C" char *strcat(char *, const char *);
extern "C" void CRef_Destruct(CRef *);
extern "C" void RefGetGameSaveValue(CRef *, int, int);
extern "C" int func_001A2C98();
const char *PchzStringFromId(void *, int);

void GetTitlePromptText(char *pchz)
{
    if (B_002DFC00.a == 1 && B_002DFC00.b == 0) {
        strcpy(pchz, PchzStringFromId(&B_003DD490, 9));
        return;
    }
    float tPlayed = 0.0f;
    if (B_002E65E0.pslot != 0) {
        CRef refDt;
        RefGetGameSaveValue(&refDt, B_003DD490.ppathDt, B_002E65E0.pslot);
        tPlayed = refDt.g;
        CRef_Destruct(&refDt);
    }
    float zero;
    asm volatile("mtc1 $0,%0\n\tnop" : "=f"(zero));
    int sid = (tPlayed != zero) ? 6 : 5;
    strcpy(pchz, PchzStringFromId(&B_003DD490, sid));
    strcat(pchz, RO_002A7A70);
    strcat(pchz, PchzStringFromId(&B_003DD490, 8));
    if (func_001A2C98() > 1) {
        strcat(pchz, RO_002A7A70);
        strcat(pchz, PchzStringFromId(&B_003DD490, 0x56));
    }
}
