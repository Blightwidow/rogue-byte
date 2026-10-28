struct CRef { int tagk; int pad[3]; void operator=(const CRef &); };
extern "C" {
int CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void BuildSavePath(const char *, char *, void *);
void RefSetSaveValue(CRef *, void *, void *, CRef *, void *);
void CRef_Destruct(CRef *);
CRef *CRef_CopyConstruct(CRef *, CRef *);
extern char B_003D4A60[];
extern char B_003E0EA8[];
}

CRef *func_001D8B20(CRef *result, CRef *pvalue, const char *first, ...)
{
    CRef ref;
    char frame[16];
    char path[16];
    CRef value;
    ref.tagk = -1;
    CStackFrame_Construct(frame);
    BuildSavePath(first, (char *)__builtin_next_arg(first) - 40, path);
    RefSetSaveValue(&value, B_003E0EA8, path, pvalue, B_003D4A60);
    ref = value;
    CRef_Destruct(&value);
    CRef_CopyConstruct(result, &ref);
    CStackFrame_Destructor(frame, 2);
    CRef_Destruct(&ref);
    return result;
}
