struct CRef { int tagk; int n; int p2; int p3; };
struct SAVEPATH { int csym; short *asym; };
extern "C" {
extern int B_003D4A60[];
void CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
SAVEPATH *PpathVaultFlag(void);
void CRef_Destruct(CRef *);
void RefGetGameSaveValue(CRef *, void *, int *);
}
static inline int GetSaveInt_1C8110(void *path)
{
    CRef ref;
    RefGetGameSaveValue(&ref, path, B_003D4A60);
    int n = ref.n;
    CRef_Destruct(&ref);
    return n;
}
extern "C" int FVaultOpen(void)
{
    char frame[0x10];
    CStackFrame_Construct(frame);
    SAVEPATH *path = PpathVaultFlag();
    if (path == 0) {
        CStackFrame_Destructor(frame, 2);
        return 0;
    }
    int result = GetSaveInt_1C8110(path);
    CStackFrame_Destructor(frame, 2);
    return result;
}
