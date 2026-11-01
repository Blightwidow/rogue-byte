struct CRef { int tagk; int n; int p2; int p3; };
struct SAVEPATH { int csym; short *asym; };
extern "C" {
extern int B_003D4A60[];
void CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
SAVEPATH *PpathClueFlag(int);
CRef *CRef_Destruct(CRef *);
CRef *RefGetGameSaveValue(CRef *, SAVEPATH *, int *);
}
extern "C" int FClueFound(int idClue)
{
    char frame[0x10];
    CRef ref;
    CStackFrame_Construct(frame);
    SAVEPATH *path = PpathClueFlag(idClue);
    int result;
    if (path != 0) {
        RefGetGameSaveValue(&ref, path, B_003D4A60);
        result = ref.n;
        CRef_Destruct(&ref);
        CStackFrame_Destructor(frame, 2);
    } else {
        CStackFrame_Destructor(frame, 2);
        result = 0;
    }
    return result;
}
