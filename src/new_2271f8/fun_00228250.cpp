#include "types.h"
#include "alloc.h"

extern "C" {
struct HEADER {
    s32 field_0x0;
    s32 field_0x4;
    char pad8[0x34];
    s32 field_0x3C;
};
void CBinaryInputStream_Read_thunk(s8 *, s32, HEADER *);
void *PvAllocSwCopyImpl__FiPv(ALLOCREQ *, void *);
static inline void *PvAllocSwCopy(s32 cb, void *source) {
    ALLOCREQ request;
    request.cb = cb;
    request.cbAlign = 0x10;
    return PvAllocSwCopyImpl__FiPv(&request, source);
}
void func_00228250(s8 *stream, s32 *result) {
    HEADER header __attribute__((aligned(16)));
    CBinaryInputStream_Read_thunk(stream, 0x40, &header);
    if (header.field_0x4 != header.field_0x3C) {
        *result = (s32) PvAllocSwCopy(0x40, &header);
        return;
    }
    *result = 0;
}
}
