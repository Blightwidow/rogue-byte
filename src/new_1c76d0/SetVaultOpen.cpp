#include "cref.h"
extern int B_003D4A60;
extern int B_002E65E0;
extern "C" void CStackFrame_Construct(void *);
extern "C" void CStackFrame_Destructor(void *, int);
extern "C" void *PpathVaultFlag(void);
extern "C" CRef RefGetGameSaveValue(void *, int *);
extern "C" CRef RefSetGameSaveValue(void *, const CRef &, int *);
extern "C" void TryAutosave(int *, int);

static inline void SetSaveBool(void *path, int fBool)
{
    CRef value;
    value.m_tagk = TAGK_Bool;
    value.m_tag.m_bool = fBool != 0;
    CRef copy(value);
    RefSetGameSaveValue(path, copy, &B_003D4A60);
}

static inline int GetSaveInt(void *path)
{
    return RefGetGameSaveValue(path, &B_003D4A60).m_tag.m_n;
}

void SetVaultOpen(int open)
{
    char frame[16];
    CStackFrame_Construct(frame);
    void *path = PpathVaultFlag();
    if (path == 0) {
        CStackFrame_Destructor(frame, 2);
        return;
    }
    if (open != 0) {
        int saved = GetSaveInt(path);
        if (saved == 0)
            TryAutosave(&B_002E65E0, 0);
    }
    SetSaveBool(path, open);
    CStackFrame_Destructor(frame, 2);
}
