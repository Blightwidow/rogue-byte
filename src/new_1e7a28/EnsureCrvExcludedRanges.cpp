#include "types.h"
#define NULL 0
extern "C" {

s32 PvAllocSwClearImpl__Fi(s32 *info);
s32 BuildCrvExcludedRanges(s32 ranges, char *owner);

void EnsureCrvExcludedRanges(char *arg0) {
    /* Two-word argument block; the frame keeps the full 16 bytes. */
    s32 info[4];
    s32 allocated;

    if (*(s32 *)(arg0 + 0x180) == 0) {
        info[0] = 0x9C;
        info[1] = 0x10;
        allocated = PvAllocSwClearImpl__Fi(info);
        *(s32 *)(arg0 + 0x180) = allocated;
        BuildCrvExcludedRanges(allocated, arg0);
    }
}

}
