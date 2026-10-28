struct CRef { int tagk; int n; int pad[2]; };
extern "C" {
void CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void *PpathClueFlag(int);
int CcluesFound();
void CRef_CopyConstruct(CRef *, CRef *);
void CRef_Destruct(CRef *);
void RefSetGameSaveValue(CRef *, void *, CRef *, void *);
extern char B_003D4A60[];
extern int B_003E1BF4;
}
void SetClueFound(int idClue, int fFound)
{
    char frame[0x10];
    CRef refs[3];
    CStackFrame_Construct(frame);
    void *ppath = PpathClueFlag(idClue);
    if (ppath == 0) {
        CStackFrame_Destructor(frame, 2);
        return;
    }
    refs[0].n = fFound != 0;
    refs[0].tagk = 0x17;
    CRef_CopyConstruct(&refs[1], &refs[0]);
    RefSetGameSaveValue(&refs[2], ppath, &refs[1], B_003D4A60);
    CRef_Destruct(&refs[2]);
    CRef_Destruct(&refs[1]);
    CRef_Destruct(&refs[0]);
    B_003E1BF4 = CcluesFound();
    CStackFrame_Destructor(frame, 2);
}
