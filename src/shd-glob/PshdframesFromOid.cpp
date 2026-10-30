#include "sly2.h"
struct SAAFRAMES { int oid; char pad[0x18 - 4]; SAAFRAMES *next; };
extern "C" {
extern SAAFRAMES *B_003E1590;
SAAFRAMES *PshdframesFromOid(int oid)
{
    char frame[0x10] __attribute__((aligned(16))); // retail frame shows a dead 0x10 area
    if (oid == -1) return 0;
    SAAFRAMES *cursor = B_003E1590;
    while (cursor) {
        if (cursor->oid == oid) return cursor;
        cursor = cursor->next;
    }
    return 0;
}
}
