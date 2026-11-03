struct CRef { int tagk; int n; int pad[2]; };
extern "C" CRef *CRef_CopyConstruct(CRef *, const CRef *);
extern "C" void CRef_Destruct(CRef *);
extern "C" void RefSetGameSaveValue(CRef *, void *, CRef *, void *);
extern "C" void bevy_player_p18_gadget_refill(void *, int);
extern "C" void StartGameFromSave(void *);
extern "C" void *B_003E0FAC;
extern "C" char B_003D4A60[];
extern "C" void *g_2e1e40;
extern "C" void *g_2dd5bc;
extern "C" void *g_2f7900;

static inline void SetGameSaveValue_1DDB08(void *path, CRef *pref)
{
    CRef copy;
    CRef_CopyConstruct(&copy, pref);
    CRef result;
    RefSetGameSaveValue(&result, path, &copy, B_003D4A60);
    CRef_Destruct(&result);
    CRef_Destruct(&copy);
}

void StartNewGame()
{
    {
        CRef zero;
        zero.tagk = 0x16;
        zero.n = 0;
        SetGameSaveValue_1DDB08(B_003E0FAC, &zero);
        CRef_Destruct(&zero);
    }
    if (g_2e1e40) bevy_player_p18_gadget_refill(g_2e1e40, 1);
    if (g_2dd5bc) bevy_player_p18_gadget_refill(g_2dd5bc, 1);
    if (g_2f7900) bevy_player_p18_gadget_refill(g_2f7900, 1);
    StartGameFromSave(B_003D4A60);
}
