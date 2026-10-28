#include "sly2.h"
extern QW RO_002A2DF0;
extern "C" QW VecMinOfVerts(int count, QW *verts)
{
    register QW result asm("$2");
    asm("lqc2 vf2, %0" : : "m" (RO_002A2DF0));
    if (count > 0) {
        do {
            asm("lqc2 vf1, %0" : : "m" (*verts));
            count--;
            asm("vmini.xyz vf2, vf1, vf2\n\tnop");
            verts++;
        } while (count != 0);
    }
    asm("qmfc2.ni %0, vf2" : "=r" (result));
    return result;
}
