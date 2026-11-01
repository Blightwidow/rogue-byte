#include "sly2.h"
struct NODE { float nx, ny, gDist; unsigned short aichild[2]; };
struct CG { char pad[0xC]; void *aface; int cnode; NODE *anode; };
struct Frame_1BF110 { QW dead[1]; };
/* lane 0 or 1 (after prot3w) of a QW to a float: mtc1 */
static inline float Lane(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
/* a QW from three floats: mfc1 x and y, pextlw into lanes 0 and 1, mfc1 z, pcpyld into the upper doubleword */
static inline QW Vec3(float x, float y, float z) { QW r; int t; asm("mfc1 %0, %2\n\tmfc1 %1, %3\n\tpextlw %0, %1, %0\n\tmfc1 %1, %4\n\tpcpyld %0, %1, %0" : "=&r" (r), "=&r" (t) : "f" (x), "f" (y), "f" (z)); return r; }
void *PcgtPointInCgQuick(CG *cg, QW pos, unsigned long grf)
{
    Frame_1BF110 frame;
    NODE *node = cg->anode;
    NODE *anode = node;
    NODE *end = node + cg->cnode;
    float x = Lane(pos);
    float y = Lane(__builtin_prot3w(pos));
    QW vec = Vec3(x, y, -1.0f);
    unsigned leaf = (grf & 1) ? 0x8000 : 0x4000;
    frame.dead[0] = vec;
    if (node != end) {
        asm("qmtc2.ni %0, vf3" : : "r" (vec));
        do {
            float dist;
            asm("lqc2 vf1, 0(%0)" : : "r" (node));
            asm("vmul.xyz vf1, vf1, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z");
            asm("qmfc2.ni $2, vf1\n\tmtc1 $2, %0\n\tnop" : "=f" (dist) : : "$2");
            unsigned child = node->aichild[0.0f < dist ? 1 : 0];
            if (child & 0x8000) {
                if (!(child & leaf))
                    break;
                return (char *)cg->aface + (child & 0x3FFF) * 12;
            }
            node = anode + child;
        } while (node != end);
    }
    return 0;
}
