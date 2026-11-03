#include "sly2.h"
struct M4 { QW row[4]; };
struct PLANE { QW plane; };
struct VTOBS { char pad[0xF8]; short delta; short index; M4 *(*fn)(void *); };
struct STAMP { char pad[0xA4]; int stamp; };
struct OBSTACLE {
    char pad0[0xC]; VTOBS *vt; char pad1[0x50 - 0x10]; STAMP *pstamp; char pad2[0xE8 - 0x54];
    int cpos; char pad3[0xF4 - 0xEC]; QW *apos; char pad4[0x1E8 - 0xF8]; int stamp; PLANE *aplane;
};
extern "C" void InitPlaneFromNormalPos(PLANE *, QW, QW);
extern QW g_2a2dc0;

// m.row[0] * v.x + m.row[1] * v.y + m.row[2] * v.z + m.row[3]
static inline QW XformPoint(const M4 &m, QW v)
{
    QW result;
    asm("vmulax.xyz ACC, %1, %5x\n\tvmadday.xyz ACC, %2, %5y\n\tvmaddaz.xyz ACC, %3, %5z\n\tvmaddw.xyz %0, %4, vf0w"
        : "=j"(result) : "j"(m.row[0]), "j"(m.row[1]), "j"(m.row[2]), "j"(m.row[3]), "j"(v));
    return result;
}

static inline QW Cross(QW a, QW b)
{
    QW result;
    asm("vopmula.xyz ACC, %1, %2\n\tvopmsub.xyz %0, %2, %1" : "=j"(result) : "j"(a), "j"(b));
    return result;
}

static inline QW Normalize(QW v)
{
    QW length;
    QW one;
    asm("vmul.xyz %0, %2, %2\n\tvaddw.x %1, vf0, vf0w\n\tvadday.x ACC, %0, %0y\n\tvmaddz.x %0, %1, %0z"
        : "=j"(length), "=j"(one) : "j"(v));
    asm("vsqrt Q, %1x\n\tvwaitq\n\tvaddq.x %0, vf0, Q" : "=j"(length) : "j"(length));
    QW result;
    asm("vdiv Q, vf0w, %2x\n\tvwaitq\n\tvmulq.xyzw %0, %1, Q" : "=j"(result) : "j"(v), "j"(length));
    return result;
}

static inline QW Sub(QW a, QW b)
{
    QW result;
    asm("vsub.xyzw %0, %1, %2" : "=j"(result) : "j"(a), "j"(b));
    return result;
}

extern "C" void Obstacle_UpdatePlanes(OBSTACLE *pobs)
{
    int stamp = 0;
    if (pobs->pstamp != 0)
        stamp = pobs->pstamp->stamp;
    if (pobs->stamp != stamp) {
        M4 mat = *pobs->vt->fn((char *)pobs + pobs->vt->delta);
        QW pos = XformPoint(mat, pobs->apos[0]);
        for (int ipos = 1; ipos < pobs->cpos; ipos++) {
            QW prev = pos;
            pos = XformPoint(mat, pobs->apos[ipos]);
            InitPlaneFromNormalPos(&pobs->aplane[ipos - 1], Normalize(Cross(Sub(pos, prev), g_2a2dc0)), prev);
        }
        pobs->stamp = stamp;
    }
}
