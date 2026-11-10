#include "types.h"

struct SLOTHEAP {
    char pad[0xC];
    void **ppvFree;
    s32 cpvUsed;
};

void FreeSlotheapPv(struct SLOTHEAP *pslotheap, void **ppv) {
    pslotheap->cpvUsed = pslotheap->cpvUsed - 1;
    *ppv = pslotheap->ppvFree;
    pslotheap->ppvFree = ppv;
}
