struct CRef;
extern "C" int CRef_CopyConstruct(CRef *, const CRef *);
extern "C" void CRef_Destruct(CRef *);
struct CRef {
    int tagk;
    int n;
    CRef(int tag, int value) { tagk = tag; n = value; }
    CRef() { tagk = -1; }
    CRef(const CRef &other) { CRef_CopyConstruct(this, &other); }
    ~CRef() { CRef_Destruct(this); }
    CRef &operator=(const CRef &);
};
struct SW { char pad[0x3B20]; int ppath; };
extern "C" {
CRef RefSetGameSaveValue(int, const CRef &, void *);
void ShowCoinBlot(SW *);
extern SW B_003DD490;
extern char B_003D4A60[];
}
static inline void SetSaveInt(int path, int number, void *key)
{
    CRef value(0x15, number);
    CRef copy(value);
    RefSetGameSaveValue(path, copy, key);
}
void SetGameCoins(void *pvUnused, int ccoin)
{
    SetSaveInt(B_003DD490.ppath, ccoin, B_003D4A60);
    ShowCoinBlot(&B_003DD490);
}
