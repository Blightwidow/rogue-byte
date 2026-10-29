#include "sly2.h"
struct SLOTHEAP { int pad[3]; void *freelist; };
extern "C" {
void FreeSlotheapPv(SLOTHEAP *, void *);
void UnlinkProcNode(void *);
extern SLOTHEAP B_00452120;
extern void *B_00452110[];
extern unsigned *B_002DD2B0;
extern unsigned *B_002DD2B8;
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
    result = (unsigned *)((char *)B_00452110[chunk] + index * 28);
done:
    return result;
}
static inline unsigned *NextNodeA(unsigned *node)
{
    unsigned grf = node[1];
    unsigned index = (grf >> 16) & 0x1FFF;
    unsigned chunk = (grf >> 29) & 3;
    unsigned *result = 0;
    if (index != 0 || chunk != 0) result = (unsigned *)((char *)B_00452110[chunk] + index * 28);
    return result;
}
void SweepProcs(void)
{
    unsigned *node = B_002DD2B0;
    unsigned *tailNode = B_002DD2B8;
    if (node != tailNode) {
        do {
            unsigned grf = node[1];
            if ((grf >> 31) != g_2dd598) node[1] = (grf & 0x7FFFFFFF) | (g_2dd598 << 31);
            node = NextNode(node);
        } while (node != tailNode);
    }
    if (node) {
        unsigned *cur = node;
        unsigned *next;
        do {
            next = NextNode(cur);
            node = next;
            if ((cur[1] >> 31) != g_2dd598) {
                UnlinkProcNode(cur);
                FreeSlotheapPv(&B_00452120, cur);
            }
            cur = node;
        } while (next);
    }
}
}
