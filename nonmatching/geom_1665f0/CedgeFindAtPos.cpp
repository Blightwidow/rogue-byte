typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct CedgeRequest { s32 size; s32 alignment; s32 pad[2]; };
struct CedgeEntry { u16 key0; u16 key1; s32 pad; CedgeEntry *next; };
struct CedgeHolder { s32 pad[4]; CedgeEntry *head; };
struct CedgeElem { s32 pad[2]; CedgeHolder *holder; };
struct CedgeSrc { s32 pad; s32 count; s32 pad2; s32 bsp; };
struct CedgeDst { s32 pad; s128 *base; };
void CStackFrame_Construct(s8 *);
void CStackFrame_Destructor(s8 *, s32);
s32 PruneBsp__FP3BSPP6VECTORfPP3BSP(s32, s32, s128, s32 *, s32 *, f32);
s32 PvAllocStackImpl__Fi(s32 *);
s32 CedgeFindAtPos(CedgeDst *dst, CedgeSrc *src, s32 key, s32 maxOut, CedgeEntry **out) {
    s8 frame[0x10];
    CedgeRequest request;
    s32 counts[2];
    CStackFrame_Construct(frame);
    s32 srcCount = src->count;
    s32 count;
    if (srcCount <= 0x1554) count = srcCount; else count = 0x1555;
    counts[0] = count;
    s32 bytes = count * 12;
    s32 *requestWords = (s32 *)&request;
    request.size = bytes;
    requestWords[1] = 0x10;
    s32 buffer = PvAllocStackImpl__Fi(requestWords);
    counts[1] = buffer;
    if (PruneBsp__FP3BSPP6VECTORfPP3BSP(src->bsp, 0x7FFFFFFF, dst->base[key], &counts[0], &counts[1], 1.0f) != 2) {
        CStackFrame_Destructor(frame, 2);
        return 0;
    }
    s32 index = 0;
    s32 total = ((counts[1] - buffer) * (s32)0xAAAAAAAB) >> 2;
    s32 found = 0;
    if (total > 0) {
        for (; index < total; index++) {
            CedgeElem *element = (CedgeElem *)(buffer + index * 12);
            CedgeEntry *entry = element->holder->head;
            if (entry == 0) continue;
            CedgeEntry **slot = (CedgeEntry **)(found * 4 + (s32)out);
            while (entry != 0) {
                if (key == entry->key0 || key == entry->key1) {
                    s32 scan;
                    for (scan = 0; scan < found; scan++) {
                        if (entry == out[scan]) break;
                    }
                    if (scan >= found && found < maxOut) {
                        *slot = entry;
                        slot++;
                        found++;
                    }
                }
                entry = entry->next;
            }
        }
    }
    CStackFrame_Destructor(frame, 2);
    return found;
}
}
