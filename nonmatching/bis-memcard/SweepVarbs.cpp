#include "sly2.h"
struct SLOTHEAP { int pad[3]; void *freelist; };
extern "C" {
void FreeSlotheapPv(SLOTHEAP *, void *);
void UnlinkVarbNode(void *);
extern SLOTHEAP B_004520D0;
extern void *B_004520C0[];
extern unsigned *B_002DD290;
extern unsigned *B_002DD298;
extern unsigned g_2dd598;
static inline unsigned *NextNode(unsigned *node)
{
    unsigned grf = node[1];
    unsigned index = (grf >> 16) & 0x1FFF;
    unsigned chunk = (grf >> 29) & 3;
    unsigned *result;
    if (index == 0) {
        if (chunk == 0) { result = 0; goto done; }
    }
    result = (unsigned *)((char *)B_004520C0[chunk] + index * 24);
done:
    return result;
}
static inline unsigned *NextNodeA(unsigned *node)
{
    int grf = node[1];
    unsigned index = (grf >> 16) & 0x1FFF;
    unsigned chunk = (grf >> 29) & 3;
    unsigned *result = 0;
    if (index != 0 || chunk != 0) result = (unsigned *)((char *)B_004520C0[chunk] + index * 24);
    return result;
}
void SweepVarbs(void)
{
    unsigned *node = B_002DD290;
    unsigned *tailNode = B_002DD298;
    if (node != tailNode) {
        do {
            unsigned grf = node[1];
            if ((grf >> 31) != g_2dd598) node[1] = (grf & 0x7FFFFFFF) | (g_2dd598 << 31);
            node = NextNode(node);
        } while (node != tailNode);
    }
    if (node) {
        unsigned *next;
        unsigned *cur = node;
        do {
            next = NextNode(cur);
            node = next;
            if ((cur[1] >> 31) != g_2dd598) {
                UnlinkVarbNode(cur);
                FreeSlotheapPv(&B_004520D0, cur);
            }
            cur = node;
        } while (next);
    }
}
}
