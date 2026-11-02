// SPDX-License-Identifier: GPL-3.0-or-later
struct CRef;
extern "C" {
CRef *CRef_CopyConstruct(CRef *, CRef *);
void CRef_Destruct(CRef *);
}
struct CRef {
    int tagk;
    int pad0;
    int n;
    int pad1;
    CRef(int tag, int count) { tagk = tag; n = count; }
    CRef(CRef &other) { CRef_CopyConstruct(this, &other); }
    ~CRef() { CRef_Destruct(this); }
};
extern "C" {
int CStackFrame_Construct(char *);
void CStackFrame_Destructor(char *, int);
int PpathVaultFlag(void);
CRef RefGetGameSaveValue(int, int *);
CRef RefSetGameSaveValue(int, CRef, int *);
void TryAutosave(int *, int);
extern int B_003D4A60;
extern int B_002E65E0;
void SetVaultOpen(int open)
{
    char frame[16] __attribute__((aligned(16)));
    CStackFrame_Construct(frame);
    int path = PpathVaultFlag();
    if (path == 0) {
        CStackFrame_Destructor(frame, 2);
        return;
    }
    if (open != 0) {
        int saved = RefGetGameSaveValue(open, &B_003D4A60).n;
        if (saved == 0)
            TryAutosave(&B_002E65E0, 0);
    }
    CRef value(0x17, open != 0);
    RefSetGameSaveValue(path, value, &B_003D4A60);
    CStackFrame_Destructor(frame, 2);
}
}
