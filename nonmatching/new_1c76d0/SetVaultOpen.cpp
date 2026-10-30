#include "sly2.h"
struct CRef;
extern "C" {
CRef *CRef_CopyConstruct(CRef *, CRef *);
void CRef_Destruct(CRef *);
}
struct CRef {
    int tagk; int n; int p2; int p3;
    CRef() {}
    CRef(CRef &other) { CRef_CopyConstruct(this, &other); }
    ~CRef() { CRef_Destruct(this); }
};
extern int B_003D4A60;
extern int B_002E65E0;
extern "C" void CStackFrame_Construct(void *);
extern "C" void CStackFrame_Destructor(void *, int);
extern "C" int PpathVaultFlag(void);
extern "C" CRef RefGetGameSaveValue(int, int *);
extern "C" CRef RefSetGameSaveValue(int, CRef &, int *);
extern "C" void TryAutosave(int *, int);

void SetVaultOpen(int open)
{
    char frame[16];
    CRef value;
    CStackFrame_Construct(frame);
    int path = PpathVaultFlag();
    if (path == 0) {
        CStackFrame_Destructor(frame, 2);
        { goto done; }
    }
    if (open != 0) {
        if (RefGetGameSaveValue(path, &B_003D4A60).n == 0)
            TryAutosave(&B_002E65E0, 0);
    }
    {
        value.tagk = 0x17;
        CRef copy(value);
        value.n = open != 0;
        RefSetGameSaveValue(path, copy, &B_003D4A60);
    }
    { goto done; }
done:
    return;
}
