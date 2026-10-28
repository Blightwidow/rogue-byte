struct CRef { int tagk; int n; };
extern "C" char B_003DD490[];
extern "C" char B_003D4A60[];
struct MENU { char pad[0x4C]; int mode; };
extern "C" MENU B_002E6550;
extern "C" char B_002E65A0[];
extern int g_2deb4c;
extern "C" {
int FSwLoadBusy(void *);
int IEpisodeCurrent(void);
CRef *RefGetGameSaveValue(CRef *, void *, void *);
void CRef_Destruct(CRef *);
void MemcardMenu_SetState(void *, int);
void func_001ABCE8(void *);
void BusyMenu_Show(void *);
}

extern "C" void TryAutosave(char *psave, int fForce)
{
    if (*(int *)(psave + 0xFD50) != 0) {
        if (FSwLoadBusy(B_003DD490) == 0 && g_2deb4c == 0) {
            if (IEpisodeCurrent() != 0 || fForce != 0) {
                CRef ref;
                RefGetGameSaveValue(&ref, *(void **)(B_003DD490 + 0x3B54), B_003D4A60);
                int n = ref.n;
                CRef_Destruct(&ref);
                if (n == 0) {
                    B_002E6550.mode = 3;
                    MemcardMenu_SetState(&B_002E6550, 0x22);
                } else {
                    func_001ABCE8(psave);
                    BusyMenu_Show(B_002E65A0);
                }
            }
        }
    }
}
