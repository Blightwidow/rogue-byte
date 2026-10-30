struct CRef { int tagk; float g; int p2; int p3; };
struct SW { char pad[0x3B1C]; int ppathDt; int pad2[2]; int ppathEpisode; };
extern SW B_003DD490;
struct SLOT { char pad[0x5464]; };
struct SLOTS { char pad[0x24]; SLOT slot[3]; };
extern SLOTS B_002E65E0;
extern char B_003D9ED0[];
extern "C" const char RO_002A6EC8[];
extern "C" char *strcpy(char *, const char *);
extern "C" int sprintf(char *, const char *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void RefGetGameSaveValue(CRef *, int, char *);
extern "C" void CStackFrame_Construct(void *);
extern "C" void CStackFrame_Destructor(void *, int);
extern "C" int NPercentCompleteSaveData(void *, char *);
extern "C" int PsavepathNewStack(const char *, int);
extern "C" int SidEpisodeName(int);
extern "C" int func_001B0078(void *);
const char *PchzStringFromId(void *, int);

extern "C" void func_001ADC40(char *pchz, int islot)
{
    char *pslot = (char *)&B_002E65E0.slot[islot];
    SW *psw = &B_003DD490;
    CRef ref;
    RefGetGameSaveValue(&ref, psw->ppathDt, pslot);
    float dt = ref.g;
    CRef_Destruct(&ref);
    float zero;
    asm volatile("mtc1 $0,%0\n\tnop" : "=f"(zero));
    if (dt != zero) {
        char frame[16];
        CStackFrame_Construct(frame);
        int ppath = PsavepathNewStack("episodeBest", 0);
        RefGetGameSaveValue(&ref, ppath ? ppath : psw->ppathEpisode, pslot);
        int nEpisode = *(int *)&ref.g;
        CRef_Destruct(&ref);
        const char *pchzEpisode = PchzStringFromId(&B_003DD490, SidEpisodeName(nEpisode));
        sprintf(pchz, RO_002A6EC8, pchzEpisode, NPercentCompleteSaveData((char *)&B_003DD490 + 0x3A18, pslot));
        CStackFrame_Destructor(frame, 2);
        return;
    }
    int nMode = func_001B0078(B_003D9ED0);
    if (nMode != 0x19) {
        if (nMode >= 0x19) {
            if (nMode < 0x20) {
                if (nMode >= 0x1E)
                    strcpy(pchz, PchzStringFromId(&B_003DD490, 0x44));
            }
        }
    } else {
        strcpy(pchz, PchzStringFromId(&B_003DD490, 0x45));
    }
}
