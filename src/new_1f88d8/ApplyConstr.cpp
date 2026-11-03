#include "sly2.h"
struct CONSTR { QW normal; int ct; };
/* dot product of a and b (xyz) in lane x */
static inline QW Dot(QW a, QW b)
{
    QW product;
    QW one;
    asm("vmul.xyz %0, %2, %3\n\tvaddw.x %1, vf0, vf0w\n\tvadday.x ACC, %0, %0y\n\tvmaddz.x %0, %1, %0z" : "=j"(product), "=j"(one) : "j"(a), "j"(b));
    return product;
}
/* a scaled by lane x of b */
static inline QW Scale(QW a, QW b)
{
    QW result;
    asm("vmulx.xyzw %0, %2, %1x" : "=j"(result) : "j"(b), "j"(a));
    return result;
}
static inline QW Sub(QW a, QW b)
{
    QW result;
    asm("vsub.xyzw %0, %1, %2" : "=j"(result) : "j"(a), "j"(b));
    return result;
}
extern "C" QW ApplyConstr(CONSTR *pconstr, QW v)
{
    switch (pconstr->ct) {
    case 3:
        asm("vsub.xyzw %0, vf0, vf0" : "=j"(v));
        break;
    case 2: {
        QW normal = pconstr->normal;
        v = Scale(normal, Dot(v, normal));
        break;
    }
    case 1: {
        QW normal = pconstr->normal;
        v = Sub(v, Scale(normal, Dot(v, normal)));
        break;
    }
    }
    return v;
}
