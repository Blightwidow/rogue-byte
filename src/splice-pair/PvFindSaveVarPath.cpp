#include "sly2.h"
struct CRef { int tagk; int n; };
struct SAVEPATH { char b[0x10]; };
extern "C" char B_003E0EA8[];
extern "C" char B_003D4A60[];
extern "C" void CStackFrame_Construct(void *);
extern "C" void CStackFrame_Destructor(void *, int);
extern "C" void BuildSavePath(const char *, void *, SAVEPATH *);
extern "C" void *PvFindSaveVar(char *, SAVEPATH *, char *);
extern "C" void CRef_Destruct(CRef *);

void *PvFindSaveVarPath(const char *first, ...)
{
    CRef ref;
    ref.tagk = -1;
    char frame[0x10];
    SAVEPATH path;
    CStackFrame_Construct(frame);
    void *args = (void *)((char *)__builtin_next_arg(first) - 0x38);
    BuildSavePath(first, args, &path);
    void *var = PvFindSaveVar(B_003E0EA8, &path, B_003D4A60);
    CStackFrame_Destructor(frame, 2);
    CRef_Destruct(&ref);
    return var;
}
