#include "types.h"

struct ENTRYPOOL {
    char pad[0x50];
    s32 centry;
    char *pbase;
};

struct POOLOWNER {
    char pad[0x10];
    struct ENTRYPOOL *ppool;
};

struct ENTRY {
    char pad[0x88];
    char *pvA;
    char *pvB;
};

void func_00231220(struct POOLOWNER *powner, struct POOLOWNER *pownerSrc, struct ENTRY **ppentry) {
    s32 temp_a0;
    struct ENTRYPOOL *ppoolSrc;
    struct ENTRY *pentrySrc;
    struct ENTRY *pentryNew;

    pentrySrc = *ppentry;
    if (pentrySrc != (struct ENTRY *)0) {
        ppoolSrc = pownerSrc->ppool;
        temp_a0 = (s32) ((char *)pentrySrc - ppoolSrc->pbase) >> 8;
        pentryNew = (struct ENTRY *)0;
        if ((temp_a0 >= 0) && (temp_a0 < ppoolSrc->centry)) {
            pentryNew = (struct ENTRY *)(powner->ppool->pbase + (temp_a0 << 8));
        }
        if (pentryNew->pvA == ((char *)pentrySrc + 0x80)) {
            pentryNew->pvA = (char *)pentryNew + 0x80;
        }
        if (pentryNew->pvB == ((char *)pentrySrc + 0x84)) {
            pentryNew->pvA = (char *)pentryNew + 0x84;
        }
        *ppentry = pentryNew;
    }
}
