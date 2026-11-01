#include "sly2.h"
struct NODE_1BF1F8 { float plane[3]; unsigned short back; unsigned short front; };
struct TREE_1BF1F8 { char pad0[0xC]; char *leaves; int count; NODE_1BF1F8 *nodes; };
/* lane 0 or 1 (after prot3w) of a QW to a float: mtc1 */
static inline float Lane(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
/* a QW from three floats: mfc1 x and y, pextlw into lanes 0 and 1, mfc1 z, pcpyld into the upper doubleword */
static inline QW Vec3(float x, float y, float z) { QW r; int t; asm("mfc1 %0, %2\n\tmfc1 %1, %3\n\tpextlw %0, %1, %0\n\tmfc1 %1, %4\n\tpcpyld %0, %1, %0" : "=&r" (r), "=&r" (t) : "f" (x), "f" (y), "f" (z)); return r; }
extern "C" {
extern float RO_002C0C00;
}
extern "C" char *PcgtPointInCgSafe(TREE_1BF1F8 *tree, NODE_1BF1F8 *node, QW point, int flags)
{
    QW frame[2] __attribute__((aligned(16)));
    QW saved = point;
    NODE_1BF1F8 *nodes = tree->nodes;
    float x = Lane(saved);
    float y = Lane(__builtin_prot3w(saved));
    QW vector = Vec3(x, y, -1.0f);
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
            } else {
                child = node->front;
                if (!(tolerance < dot)) {
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
