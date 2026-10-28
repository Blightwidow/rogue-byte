typedef void *va_list;
struct ALLOCREQ { int cb; int cbAlign; };
struct SAVEPATH { int csym; void *asymid; };
extern "C" {
int CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void *PvAllocSwImpl__Fi(ALLOCREQ *);
void *PvAllocSwCopyImpl__FiPv(ALLOCREQ *, void *);
void BuildSavePath(const char *, va_list, SAVEPATH *);
}

SAVEPATH *PsavepathNew(const char *first, ...)
{
    char frame[16];
    CStackFrame_Construct(frame);

    ALLOCREQ req;
    ALLOCREQ *preq = &req;
    va_list args;
    preq->cb = 8;
    preq->cbAlign = 0x10;
    args = (va_list)((char *)__builtin_next_arg(first) - 56);
    SAVEPATH *path = (SAVEPATH *)PvAllocSwImpl__Fi(preq);
    BuildSavePath(first, args, path);
    int csym = path->csym;
    void *old = path->asymid;
    preq->cb = csym << 1;
    preq->cbAlign = 0x10;
    path->asymid = PvAllocSwCopyImpl__FiPv(preq, old);
    CStackFrame_Destructor(frame, 2);
    return path;
}
