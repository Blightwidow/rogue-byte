struct CREF_120FB0 { int tag; int value; };
struct PAIR_120FB0 { int refs; int pad4; CREF_120FB0 key; PAIR_120FB0 *next; };
struct HANDLE_120FB0 { PAIR_120FB0 *ptr; } __attribute__((aligned(16)));
struct CREF16_120FB0 { int tag; int value; };
struct LISTREF_120FB0 { int tag; PAIR_120FB0 *head; };
extern "C" {
void CPairPtr_Destructor(PAIR_120FB0 **, int);
void CRef_ConstructPair(void *, PAIR_120FB0 *);
void CRef_Destruct(CREF_120FB0 *);
void FreeSlotheapPv(void *, void *);
int NRandInRange(int, int);
void PairHandle_Assign(PAIR_120FB0 **, PAIR_120FB0 *);
void PairHandle_Init(PAIR_120FB0 **, PAIR_120FB0 *);
PAIR_120FB0 *PpairNew();
void SetTag__4CRef4TAGK(void *, int);
void UnlinkPairNode(PAIR_120FB0 *);
void __as__4CRefRC4CRef(CREF_120FB0 *, CREF_120FB0 *);
extern char B_004520A8;
void *bevy_splice_bif_bif41_shuffle(void *result, int unused, LISTREF_120FB0 *list) {
    CREF_120FB0 *items[0x80];
    HANDLE_120FB0 headHandle;
    HANDLE_120FB0 secondHandle;
    CREF16_120FB0 tagRefHolder;
    CREF_120FB0 *tagRef = (CREF_120FB0 *)&tagRefHolder;
    PAIR_120FB0 *node;
    PAIR_120FB0 *target;
    PAIR_120FB0 **slot;
    CREF_120FB0 *saved;
    CREF_120FB0 *held;
    int count;
    int zeroIndex;
    int flag;
    int index;
    int round;
    int tag = list->tag;
    if (tag == 0 || tag != 0x1F) {
        SetTag__4CRef4TAGK(result, 0);
    } else {
        count = 0;
        zeroIndex = -1;
        for (node = list->head; node != 0; node = node->next) {
            if (node->key.tag == 0) {
                zeroIndex = count;
            } else {
                items[count] = &node->key;
                count++;
            }
        }
        flag = 0;
        if (count >= 2) {
            flag = zeroIndex < 1;
        }
        if (flag != 0) {
            saved = items[0];
            for (round = 0; round < count; round++) {
                index = NRandInRange(0, count - 1);
                held = items[index];
                items[index] = items[round];
                items[round] = held;
            }
            zeroIndex = count;
            if (items[0] == saved) {
                items[0] = items[count - 1];
                items[count - 1] = saved;
            }
        }
        headHandle.ptr = 0;
        slot = &headHandle.ptr;
        target = 0;
        for (index = 0; index < count; index++) {
            PairHandle_Assign(slot, PpairNew());
            node = *slot;
            slot = &node->next;
            __as__4CRefRC4CRef(&node->key, items[index]);
            if (index == zeroIndex - 1) {
                target = node;
            } else {
                target = target;
            }
        }
        if (target != 0) {
            if (target != headHandle.ptr) {
                if (flag == 0) {
                    PairHandle_Init(&secondHandle.ptr, headHandle.ptr);
                    PairHandle_Assign(&headHandle.ptr, headHandle.ptr->next);
                    PairHandle_Assign(&secondHandle.ptr->next, target->next);
                    PairHandle_Assign(&target->next, secondHandle.ptr);
                    if (secondHandle.ptr != 0) {
                        if (--secondHandle.ptr->refs == 0) {
                            CPairPtr_Destructor(&secondHandle.ptr->next, 2);
                            CRef_Destruct(&secondHandle.ptr->key);
                            UnlinkPairNode(secondHandle.ptr);
                            FreeSlotheapPv(&B_004520A8, secondHandle.ptr);
                        }
                    }
                }
                if (headHandle.ptr != target) {
                    PairHandle_Init(&secondHandle.ptr, PpairNew());
                    SetTag__4CRef4TAGK(tagRef, 0);
                    __as__4CRefRC4CRef(&secondHandle.ptr->key, tagRef);
                    CRef_Destruct(tagRef);
                    PairHandle_Assign(&secondHandle.ptr->next, target->next);
                    PairHandle_Assign(&target->next, secondHandle.ptr);
                    if (secondHandle.ptr != 0) {
                        if (--secondHandle.ptr->refs == 0) {
                            CPairPtr_Destructor(&secondHandle.ptr->next, 2);
                            CRef_Destruct(&secondHandle.ptr->key);
                            UnlinkPairNode(secondHandle.ptr);
                            FreeSlotheapPv(&B_004520A8, secondHandle.ptr);
                        }
                    }
                }
            }
        }
        CRef_ConstructPair(result, headHandle.ptr);
        if (headHandle.ptr != 0) {
            if (--headHandle.ptr->refs == 0) {
                CPairPtr_Destructor(&headHandle.ptr->next, 2);
                CRef_Destruct(&headHandle.ptr->key);
                UnlinkPairNode(headHandle.ptr);
                FreeSlotheapPv(&B_004520A8, headHandle.ptr);
            }
        }
    }
    return result;
}
}
