#include "sly2.h"
struct NODE_1BF1F8 { float plane[3]; unsigned short back; unsigned short front; };
struct TREE_1BF1F8 { char pad0[0xC]; char *leaves; int count; NODE_1BF1F8 *nodes; };
extern "C" {
extern float RO_002C0C00;
}
extern "C" char *PcgtPointInCgSafe(TREE_1BF1F8 *tree, NODE_1BF1F8 *node, QW point, int flags)
{
    QW frame[2] __attribute__((aligned(16)));
    QW saved = point;
    QW rotated = __builtin_prot3w(saved);
    float x, y;
    asm("mtc1 %2, %0\n\tmtc1 %3, %1" : "=f" (x), "=f" (y) : "r" (saved), "r" (rotated));
    NODE_1BF1F8 *nodes = tree->nodes;
    float minusOne = -1.0f;
    int xBits, yBits, zBits;
    asm("mfc1 %0, %1" : "=r" (xBits) : "f" (x));
    asm("mfc1 %0, %1" : "=r" (yBits) : "f" (y));
    QW vector;
    asm("pextlw %0, %1, %2" : "=r" (vector) : "r" (yBits), "r" (xBits));
    asm("mfc1 %0, %1" : "=r" (zBits) : "f" (minusOne));
    asm("pcpyld %0, %1, %0" : "+r" (vector) : "r" (zBits));
    asm volatile("qmtc2.ni %0, vf3" : : "r" (vector));
    NODE_1BF1F8 *end = nodes + tree->count;
    asm volatile("sqc2 vf3, 0(%0)" : : "r" (frame));
    unsigned mask = (flags & 1) ? 0x8000 : 0x4000;
    if (node != end) {
        do {
            float tolerance = RO_002C0C00;
            int bits;
            asm volatile("lqc2 vf1, 0(%1)\n\tvmul.xyz vf1, vf1, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tqmfc2.ni %0, vf1" : "=r" (bits) : "r" (node));
            float dot;
            asm volatile("mtc1 %1, %0" : "=f" (dot) : "r" (bits));
            unsigned child;
            if (dot < -tolerance) {
                child = node->back;
            } else if (tolerance < dot) {
                child = node->front;
            } else {
                child = node->front;
                if (child & 0x8000) {
                    if (child & mask)
                        return tree->leaves + (child & 0x3FFF) * 0xC;
                } else {
                    NODE_1BF1F8 *sub = nodes + child;
                    if (sub != end) {
                        asm volatile("sqc2 vf3, 0x10(%0)" : : "r" (frame));
                        char *found = PcgtPointInCgSafe(tree, sub, saved, flags);
                        asm volatile("lqc2 vf3, 0x10(%0)" : : "r" (frame));
                        if (found != 0)
                            return found;
                    }
                }
                child = node->back;
            }
            if (child & 0x8000) {
                if (child & mask)
                    return tree->leaves + (child & 0x3FFF) * 0xC;
                break;
            }
            node = nodes + child;
        } while (node != end);
    }
    return 0;
}
