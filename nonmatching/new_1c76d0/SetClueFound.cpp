struct CRef;
extern "C" {
CRef *CRef_CopyConstruct(CRef *, const CRef *);
void CRef_Destruct(CRef *);
}
struct CRef {
    int tagk; int n; int p2; int p3;
    CRef() {}
    CRef(int tag, int count) { tagk = tag; n = count; }
    CRef(const CRef &other) { CRef_CopyConstruct(this, &other); }
    ~CRef() { CRef_Destruct(this); }
};
struct SAVEPATH { int csym; short *asym; };
extern int B_003D4A60;
extern int B_003E1BF4;
extern "C" void CStackFrame_Construct(void *);
extern "C" void CStackFrame_Destructor(void *, int);
extern "C" SAVEPATH *PpathClueFlag(int);
extern "C" int CcluesFound(void);
extern "C" CRef RefSetGameSaveValue(SAVEPATH *, CRef, int *);

void SetClueFound(int idClue, int fFound)
{
    char frame[16];
    CStackFrame_Construct(frame);
    SAVEPATH *path = PpathClueFlag(idClue);
    if (path == 0) {
        CStackFrame_Destructor(frame, 2);
        return;
    }
    {
    CRef value(0x17, fFound != 0);
    CRef result = RefSetGameSaveValue(path, value, &B_003D4A60);
    }
    B_003E1BF4 = CcluesFound();
    CStackFrame_Destructor(frame, 2);
}
