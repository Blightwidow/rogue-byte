typedef int QW __attribute__((mode(TI)));
struct CREF_1249A8 { int tag; int value; };
struct PAIR_1249A8 { int refs; int pad4; CREF_1249A8 key; PAIR_1249A8 *next; };
struct HANDLE_1249A8 { PAIR_1249A8 *ptr; } __attribute__((aligned(16)));
struct ELEM_1249A8 { char pad0[0x10]; long flags; char pad18[0xB0 - 0x18]; };
struct OBJ_1249A8 { char pad0[0xE0]; int count; ELEM_1249A8 *elems; };
struct NODE_1249A8 { int pad0; int pad4; CREF_1249A8 key; NODE_1249A8 *next; };
struct ARGS_1249A8 { int tag; NODE_1249A8 *head; CREF_1249A8 start; CREF_1249A8 end; };
extern "C" {
void CPairPtr_Destructor(PAIR_1249A8 **, int);
void CRef_CopyConstruct(CREF_1249A8 *, CREF_1249A8 *);
void CRef_Destruct(CREF_1249A8 *);
void CRef_SetBasic(CREF_1249A8 *, void *);
void CRef_SetVectorPtr(CREF_1249A8 *, QW *);
int ClsgClipEdgeToObject(ELEM_1249A8 *, QW, QW, int);
void FreeSlotheapPv(void *, void *);
void PairHandle_Assign(PAIR_1249A8 **, PAIR_1249A8 *);
void PairHandle_Init(PAIR_1249A8 **, PAIR_1249A8 *);
PAIR_1249A8 *PpairNew();
void UnlinkPairNode(PAIR_1249A8 *);
void __as__4CRefRC4CRef(CREF_1249A8 *, CREF_1249A8 *);
void bevy_splice_value_list_ref(CREF_1249A8 *, PAIR_1249A8 *);
extern char B_004520A8;
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
extern "C" CREF_1249A8 *RefOpHitTestObjectsImpl(CREF_1249A8 *pret, int op, int unused, ARGS_1249A8 *args) {
    CREF_1249A8 result __attribute__((aligned(16)));
    HANDLE_1249A8 first;
    HANDLE_1249A8 last;
    QW vecA;
    QW vecB;
    HANDLE_1249A8 pairA;
    HANDLE_1249A8 pairB;
    HANDLE_1249A8 pairC;
    HANDLE_1249A8 pairD;
    NODE_1249A8 *node;
    OBJ_1249A8 *object;
    ELEM_1249A8 *elem;
    int index;
    result.tag = -1;
    if (args->tag == 0) {
        __as__4CRefRC4CRef(&result, (CREF_1249A8 *)args);
    } else {
        PairHandle_Init(&first.ptr, 0);
        PairHandle_Init(&last.ptr, 0);
        for (node = args->head; node != 0; node = node->next) {
            object = (OBJ_1249A8 *)node->key.value;
            if (object != 0 && object->count > 0) {
                for (index = 0; index < object->count; index++) {
                    elem = &object->elems[index];
                    if (!(elem->flags & (0x8000L << 35)) &&
                        ClsgClipEdgeToObject(elem, *(QW *)args->start.value, *(QW *)args->end.value, 1) > 0) {
                        PairHandle_Init(&pairA.ptr, PpairNew());
                        PairHandle_Init(&pairB.ptr, PpairNew());
                        CRef_SetBasic(&pairA.ptr->key, object);
                        PairHandle_Assign(&pairA.ptr->next, pairB.ptr);
                        if (op != 0x7B) {
                            CRef_SetVectorPtr(&pairB.ptr->key, &vecB);
                            bevy_splice_value_list_ref(&result, pairA.ptr);
                            CRef_CopyConstruct(pret, &result);
                            RELEASE_PAIR(pairB.ptr);
                            RELEASE_PAIR(pairA.ptr);
                            RELEASE_PAIR(last.ptr);
                            RELEASE_PAIR(first.ptr);
                            CRef_Destruct(&result);
                            return pret;
                        }
                        PairHandle_Init(&pairC.ptr, PpairNew());
                        PairHandle_Init(&pairD.ptr, PpairNew());
                        CRef_SetVectorPtr(&pairB.ptr->key, &vecA);
                        PairHandle_Assign(&pairB.ptr->next, pairC.ptr);
                        CRef_SetVectorPtr(&pairC.ptr->key, &vecB);
                        bevy_splice_value_list_ref(&pairD.ptr->key, pairA.ptr);
                        if (first.ptr != 0) {
                            PairHandle_Assign(&last.ptr->next, pairD.ptr);
                        } else {
                            PairHandle_Assign(&first.ptr, pairD.ptr);
                        }
                        PairHandle_Assign(&last.ptr, pairD.ptr);
                        RELEASE_PAIR(pairD.ptr);
                        RELEASE_PAIR(pairC.ptr);
                        RELEASE_PAIR(pairB.ptr);
                        RELEASE_PAIR(pairA.ptr);
                    }
                }
            }
        }
        if (first.ptr != 0) {
            bevy_splice_value_list_ref(&result, first.ptr);
        }
        RELEASE_PAIR(last.ptr);
        RELEASE_PAIR(first.ptr);
    }
    CRef_CopyConstruct(pret, &result);
    CRef_Destruct(&result);
    return pret;
}
