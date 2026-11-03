struct CPair;
struct CRef {
    int tagk;
    int n;
    CRef() { tagk = -1; }
    CRef(const CRef &) asm("CRef_CopyConstruct");
    inline ~CRef();
    CRef &operator=(const CRef &);
};
struct CPair { int cref; int pad4; CRef ref; CPair *next; };
struct SLOTHEAP;
struct CFrame { int cref; };
extern "C" {
void CRef_Destruct(CRef *);
void CPairPtr_Destructor(CPair **, int);
void UnlinkPairNode(CPair *);
void FreeSlotheapPv(SLOTHEAP *, void *);
extern SLOTHEAP B_004520A8;
void CFrame_DeletingDestructor(CFrame *, int);
CPair *PpairNew(void);
void PairHandle_Assign(CPair **, CPair *);
void SetTag__4CRef4TAGK(CRef *, int);
CRef *bevy_splice_value_list_ref(CRef *, CPair *);
CFrame *PframeNew(void);
void bevy_splice_frame_set_parent(CFrame *, CFrame *);
}
CRef::~CRef() { CRef_Destruct(this); }

static inline void ReleasePair_1272E0(CPair *held)
{
    if (held) {
        if (--held->cref == 0) {
            CPairPtr_Destructor(&held->next, 2);
            CRef_Destruct(&held->ref);
            UnlinkPairNode(held);
            FreeSlotheapPv(&B_004520A8, held);
        }
    }
}
struct PairHandle {
    CPair *p;
    int pad;
    PairHandle() { p = 0; }
    PairHandle(CPair *) asm("PairHandle_Init");
    ~PairHandle() { ReleasePair_1272E0(p); }
};
struct FrameHandle {
    CFrame *p;
    int pad;
    FrameHandle(CFrame *) asm("func_00257058");
    ~FrameHandle()
    {
        CFrame *held = p;
        if (held) {
            if (--held->cref == 0)
                CFrame_DeletingDestructor(held, 3);
        }
    }
};
struct ENTRY { CRef (*fn)(int, CRef *, CFrame *); int count; int hasRest; };
struct CALLEE { int pad0; int pad4; int data; CRef (*fn)(int, int, CRef *); int count; };
struct PROC { int pad0; int pad4; CFrame *frame; int count; int rest; CPair *params; };
extern "C" {
CRef RefEval(CPair *, CFrame *);
CRef RefEvalProcBody(PROC *, CFrame *);
CRef CFrame_RefAddBinding(CFrame *, int, CRef *);
extern ENTRY D_002BBB90[];
}

extern "C" CRef RefEvalApply(CPair *expr, CFrame *env)
{
    CRef result;
    ENTRY *entry = 0;
    PROC *proc = 0;
    CALLEE *callee = 0;
    CPair *call = (CPair *)expr->ref.n;
    CRef kind = RefEval(call, env);
    int fixedCount;
    int hasRest;
    if (kind.tagk == 25) {
        entry = &D_002BBB90[kind.n];
        fixedCount = entry->count;
        hasRest = entry->hasRest;
    } else if (kind.tagk == 34) {
        callee = (CALLEE *)kind.n;
        hasRest = 0;
        fixedCount = callee->count;
    } else {
        proc = (PROC *)kind.n;
        fixedCount = proc->count;
        hasRest = proc->rest;
    }
    int total = fixedCount + (hasRest != 0);
    CRef args[32];
    CPair *cursor = call->next;
    int count = fixedCount;
    int index;
    for (index = 0; index < fixedCount; index++) {
        result = RefEval(cursor, env);
        args[index] = result;
        cursor = cursor->next;
    }
    if (hasRest) {
        PairHandle rest(cursor);
        PairHandle tail;
        PairHandle head;
        while (rest.p) {
            PairHandle item(PpairNew());
            item.p->ref = RefEval(rest.p, env);
            if (tail.p) {
                PairHandle_Assign(&tail.p->next, item.p);
                PairHandle_Assign(&tail.p, item.p);
            } else {
                PairHandle_Assign(&tail.p, item.p);
                PairHandle_Assign(&head.p, tail.p);
            }
            count++;
            PairHandle_Assign(&rest.p, rest.p->next);
        }
        if (head.p) {
            bevy_splice_value_list_ref(&args[index], head.p);
        } else {
            CRef_Destruct(&args[index]);
            SetTag__4CRef4TAGK(&args[index], 0);
        }
    }
    switch (kind.tagk) {
    case 25:
        result = entry->fn(count, args, env);
        break;
    case 32: {
        FrameHandle frame(PframeNew());
        bevy_splice_frame_set_parent(frame.p, proc->frame);
        cursor = proc->params;
        for (int bound = 0; bound < total; bound++) {
            if (cursor->ref.tagk == 0x14)
                cursor = cursor->next;
            CRef binding = CFrame_RefAddBinding(frame.p, cursor->ref.n, &args[bound]);
            cursor = cursor->next;
        }
        result = RefEvalProcBody(proc, frame.p);
        break;
    }
    case 34:
        result = callee->fn(callee->data, count, args);
        break;
    }
    return result;
}
