struct CRef;
extern "C" int CRef_CopyConstruct(CRef *, const CRef *);
extern "C" void CRef_Destruct(CRef *);
struct CRef {
    int tagk;
    int n;
    int pad[2];
    CRef() { tagk = -1; }
    CRef(const CRef &other) { CRef_CopyConstruct(this, &other); }
    ~CRef() { CRef_Destruct(this); }
    CRef &operator=(const CRef &);
};
extern "C" {
int CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void BuildSavePath(const char *, char *, void *);
CRef RefGetSaveValue(void *, void *, void *);
extern char B_003D4A60[];
extern char B_003E0EA8[];
}
static inline CRef GetSaveValue(char *path, void *key)
{
    return RefGetSaveValue(B_003E0EA8, path, key);
}
extern "C" CRef *func_001D8A38(CRef *result, const char *first, ...)
{
    CRef ref;
    char frame[16];
    char path[16];
    CStackFrame_Construct(frame);
    BuildSavePath(first, (char *)__builtin_next_arg(first) - 48, path);
    ref = GetSaveValue(path, B_003D4A60);
    CRef_CopyConstruct(result, &ref);
    CStackFrame_Destructor(frame, 2);
    return result;
}
