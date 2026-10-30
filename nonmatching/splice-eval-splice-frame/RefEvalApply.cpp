struct CREF_1272E0 { int tag; int value; };
struct SLOT_1272E0 { CREF_1272E0 ref; } __attribute__((aligned(16)));
struct PAIR_1272E0 { int refs; int pad4; CREF_1272E0 key; PAIR_1272E0 *next; };
struct HANDLE_1272E0 { PAIR_1272E0 *ptr; } __attribute__((aligned(16)));
struct ENTRY_1272E0 { void (*fn)(CREF_1272E0 *, int, CREF_1272E0 *, int); int count; int hasRest; };
struct CALLEE_1272E0 { int pad0; int pad4; int field8; void (*fn)(CREF_1272E0 *, int, int, CREF_1272E0 *); int count; };
struct FRAME_1272E0 { int refs; };
struct PROC_1272E0 { char pad0[8]; FRAME_1272E0 *frame; int pad0c; int count; int rest; PAIR_1272E0 *params; };
extern "C" {
void CFrame_DeletingDestructor(FRAME_1272E0 *, int);
void CFrame_RefAddBinding(CREF_1272E0 *, FRAME_1272E0 *, int, CREF_1272E0 *);
void CPairPtr_Destructor(PAIR_1272E0 **, int);
void CRef_CopyConstruct(CREF_1272E0 *, CREF_1272E0 *);
void CRef_Destruct(CREF_1272E0 *);
void FreeSlotheapPv(void *, void *);
void PairHandle_Assign(PAIR_1272E0 **, PAIR_1272E0 *);
void PairHandle_Init(PAIR_1272E0 **, PAIR_1272E0 *);
FRAME_1272E0 *PframeNew();
PAIR_1272E0 *PpairNew();
void RefEval(CREF_1272E0 *, PAIR_1272E0 *, int);
void RefEvalProcBody(CREF_1272E0 *, PROC_1272E0 *, FRAME_1272E0 *);
void SetTag__4CRef4TAGK(CREF_1272E0 *, int);
void UnlinkPairNode(PAIR_1272E0 *);
void __as__4CRefRC4CRef(CREF_1272E0 *, CREF_1272E0 *);
void bevy_splice_value_list_ref(CREF_1272E0 *, PAIR_1272E0 *);
void func_00257058(FRAME_1272E0 **, FRAME_1272E0 *);
void bevy_splice_frame_set_parent(FRAME_1272E0 *, FRAME_1272E0 *);
extern char B_004520A8;
extern ENTRY_1272E0 D_002BBB90[];
}
#define RELEASE_PAIR(pair) \
    if (pair != 0) { \
        if (--pair->refs == 0) { \
            CPairPtr_Destructor(&pair->next, 2); \
            CRef_Destruct(&pair->key); \
            UnlinkPairNode(pair); \
            FreeSlotheapPv(&B_004520A8, pair); \
        } \
    }
extern "C" CREF_1272E0 *RefEvalApply(CREF_1272E0 *pret, PAIR_1272E0 *expr, int env) {
    SLOT_1272E0 result;
    SLOT_1272E0 kind;
    CREF_1272E0 args[32];
    SLOT_1272E0 temp;
    HANDLE_1272E0 handleA;
    HANDLE_1272E0 handleB;
    HANDLE_1272E0 handleC;
    HANDLE_1272E0 handleD;
    SLOT_1272E0 evaluated;
    FRAME_1272E0 *frame;
    ENTRY_1272E0 *entry = 0;
    PROC_1272E0 *proc = 0;
    CALLEE_1272E0 *callee = 0;
    PAIR_1272E0 *cursor;
    PAIR_1272E0 *callExpr = (PAIR_1272E0 *)expr->key.value;
    int fixedCount;
    int hasRest;
    int total;
    int index;
    int count;
    CREF_1272E0 *slot;
    result.ref.tag = -1;
    RefEval(&kind.ref, callExpr, -1);
    switch (kind.ref.tag) {
    case 25:
        entry = &D_002BBB90[kind.ref.value];
        fixedCount = entry->count;
        hasRest = entry->hasRest;
        break;
    case 34:
        hasRest = 0;
        callee = (CALLEE_1272E0 *)kind.ref.value;
        fixedCount = callee->count;
        break;
    default:
        proc = (PROC_1272E0 *)kind.ref.value;
        fixedCount = proc->count;
        hasRest = proc->rest;
        break;
    }
    total = fixedCount + (hasRest != 0);
    for (index = 31; index >= 0; index--) {
        args[31 - index].tag = -1;
    }
    cursor = callExpr->next;
    count = fixedCount;
    index = 0;
    if (count > 0) {
        slot = args;
        do {
            index++;
            RefEval(&temp.ref, cursor, env);
            __as__4CRefRC4CRef(&result.ref, &temp.ref);
            CRef_Destruct(&temp.ref);
            __as__4CRefRC4CRef(slot, &result.ref);
            slot++;
            cursor = cursor->next;
        } while (index < fixedCount);
    }
    if (hasRest != 0) {
        PairHandle_Init(&handleA.ptr, cursor);
        handleB.ptr = 0;
        handleC.ptr = 0;
        if (handleA.ptr != 0) {
            do {
                PairHandle_Init(&handleD.ptr, PpairNew());
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
                RELEASE_PAIR(handleD.ptr);
            } while (handleA.ptr != 0);
        }
        if (handleC.ptr != 0) {
            bevy_splice_value_list_ref(&args[index], handleC.ptr);
        } else {
            CRef_Destruct(&args[index]);
            SetTag__4CRef4TAGK(&args[index], 0);
        }
        RELEASE_PAIR(handleC.ptr);
        RELEASE_PAIR(handleB.ptr);
        RELEASE_PAIR(handleA.ptr);
    }
    switch (kind.ref.tag) {
    case 25:
        entry->fn(&temp.ref, count, args, env);
        __as__4CRefRC4CRef(&result.ref, &temp.ref);
        CRef_Destruct(&temp.ref);
        break;
    case 32:
        func_00257058(&frame, PframeNew());
        bevy_splice_frame_set_parent(frame, proc->frame);
        cursor = proc->params;
        slot = args;
        if (total > 0) {
            index = total;
            do {
                if (cursor->key.tag == 0x14) {
                    cursor = cursor->next;
                }
                CFrame_RefAddBinding(&evaluated.ref, frame, cursor->key.value, slot);
                slot++;
                cursor = cursor->next;
                CRef_Destruct(&evaluated.ref);
                index--;
            } while (index != 0);
        }
        RefEvalProcBody(&evaluated.ref, proc, frame);
        __as__4CRefRC4CRef(&result.ref, &evaluated.ref);
        CRef_Destruct(&evaluated.ref);
        if (frame != 0) {
            if (--frame->refs == 0) {
                CFrame_DeletingDestructor(frame, 3);
            }
        }
        break;
    case 34:
        callee->fn(&temp.ref, callee->field8, count, args);
        __as__4CRefRC4CRef(&result.ref, &temp.ref);
        CRef_Destruct(&temp.ref);
        break;
    }
    CRef_CopyConstruct(pret, &result.ref);
    for (index = 31; index >= 0; index--) {
        CRef_Destruct(&args[index]);
    }
    CRef_Destruct(&kind.ref);
    CRef_Destruct(&result.ref);
    return pret;
}
