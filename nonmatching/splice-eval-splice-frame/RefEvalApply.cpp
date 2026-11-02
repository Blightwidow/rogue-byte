struct CREF;
struct PAIR;
extern "C" {
void CRef_Destruct(CREF *);
void CPairPtr_Destructor(PAIR **, int);
void UnlinkPairNode(PAIR *);
void FreeSlotheapPv(void *, void *);
extern char B_004520A8;
}
struct CREF { int tag; int value; };
struct CRefD { int tag; int value; ~CRefD() { CRef_Destruct((CREF *)this); } } __attribute__((aligned(16)));
struct SLOT { CREF ref; } __attribute__((aligned(16)));
struct CRefC { int tag; int value; CRefC() { tag = -1; } ~CRefC() { CRef_Destruct((CREF *)this); } };
struct PAIR { int refs; int pad4; CREF key; PAIR *next; };
struct HANDLE {
    PAIR *ptr;
    ~HANDLE() {
        PAIR *pair = ptr;
        if (pair != 0) {
            if (--pair->refs == 0) {
                CPairPtr_Destructor(&pair->next, 2);
                CRef_Destruct(&pair->key);
                UnlinkPairNode(pair);
                FreeSlotheapPv(&B_004520A8, pair);
            }
        }
    }
} __attribute__((aligned(16)));
struct ENTRY { void (*fn)(CREF *, int, CREF *, int); int count; int hasRest; };
struct CALLEE { int pad0; int pad4; int field8; void (*fn)(CREF *, int, int, CREF *); int count; };
struct FRAME { int refs; };
struct PROC { char pad0[8]; FRAME *frame; int count; int rest; PAIR *params; };
extern "C" {
void CFrame_DeletingDestructor(FRAME *, int);
void CFrame_RefAddBinding(CREF *, FRAME *, int, CREF *);
void CRef_CopyConstruct(CREF *, CREF *);
void PairHandle_Assign(PAIR **, PAIR *);
void PairHandle_Init(PAIR **, PAIR *);
FRAME *PframeNew();
PAIR *PpairNew();
void RefEval(CREF *, PAIR *, int);
void RefEvalProcBody(CREF *, PROC *, FRAME *);
void SetTag__4CRef4TAGK(CREF *, int);
void __as__4CRefRC4CRef(void *, void *);
void bevy_splice_value_list_ref(CREF *, PAIR *);
void func_00257058(FRAME **, FRAME *);
void bevy_splice_frame_set_parent(FRAME *, FRAME *);
extern ENTRY D_002BBB90[];
}
extern "C" CREF *RefEvalApply(CREF *pret, PAIR *expr, int env) {
    CRefC result;
    ENTRY *entry = 0;
    PROC *proc = 0;
    CALLEE *callee = 0;
    CRefD kind;
    PAIR *callExpr = (PAIR *)expr->key.value;
    int fixedCount;
    int hasRest;
    RefEval((CREF *)&kind, callExpr, env);
    if (kind.tag == 25) {
        entry = &D_002BBB90[kind.value];
        fixedCount = entry->count;
        hasRest = entry->hasRest;
    } else if (kind.tag == 34) {
        hasRest = 0;
        callee = (CALLEE *)kind.value;
        fixedCount = callee->count;
    } else {
        proc = (PROC *)kind.value;
        fixedCount = proc->count;
        hasRest = proc->rest;
    }
    int total = fixedCount + (hasRest != 0);
    CRefC args[32];
    PAIR *cursor = callExpr->next;
    int count = fixedCount;
    int index = 0;
    if (count > 0) {
        CRefC *slot = args;
        do {
            index++;
            SLOT temp;
            RefEval(&temp.ref, cursor, env);
            __as__4CRefRC4CRef(&result, &temp.ref);
            CRef_Destruct(&temp.ref);
            __as__4CRefRC4CRef(slot, &result);
            slot++;
            cursor = cursor->next;
        } while (index < fixedCount);
    }
    if (hasRest != 0) {
        HANDLE handleA;
        PairHandle_Init(&handleA.ptr, cursor);
        HANDLE handleB;
        handleB.ptr = 0;
        HANDLE handleC;
        handleC.ptr = 0;
        if (handleA.ptr != 0) {
            do {
                HANDLE handleD;
                PairHandle_Init(&handleD.ptr, PpairNew());
                SLOT evaluated;
                RefEval(&evaluated.ref, handleA.ptr, env);
                __as__4CRefRC4CRef(&handleD.ptr->key, &evaluated.ref);
                CRef_Destruct(&evaluated.ref);
                if (handleB.ptr != 0) {
                    PairHandle_Assign(&handleB.ptr->next, handleD.ptr);
                    PairHandle_Assign(&handleB.ptr, handleD.ptr);
                } else {
                    PairHandle_Assign(&handleB.ptr, handleD.ptr);
                    PairHandle_Assign(&handleC.ptr, handleB.ptr);
                }
                count++;
                PairHandle_Assign(&handleA.ptr, handleA.ptr->next);
            } while (handleA.ptr != 0);
        }
        if (handleC.ptr != 0) {
            bevy_splice_value_list_ref((CREF *)&args[index], handleC.ptr);
        } else {
            CRef_Destruct((CREF *)&args[index]);
            SetTag__4CRef4TAGK((CREF *)&args[index], 0);
        }
    }
    switch (kind.tag) {
    case 25: {
        SLOT temp;
        entry->fn(&temp.ref, count, (CREF *)args, env);
        __as__4CRefRC4CRef(&result, &temp.ref);
        CRef_Destruct(&temp.ref);
        break;
    }
    case 32: {
        SLOT evaluated;
        FRAME *frame;
        func_00257058(&frame, PframeNew());
        bevy_splice_frame_set_parent(frame, proc->frame);
        cursor = proc->params;
        CRefC *slot = args;
        if (total > 0) {
            index = total;
            do {
                if (cursor->key.tag == 0x14) {
                    cursor = cursor->next;
                }
                CFrame_RefAddBinding(&evaluated.ref, frame, cursor->key.value, (CREF *)slot);
                slot++;
                cursor = cursor->next;
                CRef_Destruct(&evaluated.ref);
                index--;
            } while (index != 0);
        }
        RefEvalProcBody(&evaluated.ref, proc, frame);
        __as__4CRefRC4CRef(&result, &evaluated.ref);
        CRef_Destruct(&evaluated.ref);
        if (frame != 0) {
            if (--frame->refs == 0) {
                CFrame_DeletingDestructor(frame, 3);
            }
        }
        break;
    }
    case 34: {
        SLOT temp;
        callee->fn(&temp.ref, callee->field8, count, (CREF *)args);
        __as__4CRefRC4CRef(&result, &temp.ref);
        CRef_Destruct(&temp.ref);
        break;
    }
    }
    CRef_CopyConstruct(pret, (CREF *)&result);
    return pret;
}
