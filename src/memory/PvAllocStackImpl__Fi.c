#include "types.h"

struct AllocStackRequest {
    s32 size;
    s32 alignment;
};

void CheckForOutOfMemory__Fv(s32);
extern s32 g_2f6388;

s32 PvAllocStackImpl__Fi(struct AllocStackRequest *request) {
    s32 size;
    s32 result;

    size = request->size;
    result = 0;
    if (size != 0) {
        CheckForOutOfMemory__Fv(size);
        result = (g_2f6388 - ((request->size + 0xF) & ~0xF)) & -request->alignment;
        g_2f6388 = result;
    }
    return result;
}
