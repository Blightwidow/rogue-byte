#include "sly2.h"
struct Xf { char pad[0x94]; unsigned mode; };
#define BODY(OFFX, OFFZ, OFFY) { \
        float z, y; QW t; \
        asm volatile("pextuw %0, $0, %4\n\tsw %4, %3\n\tmtc1 %0, %1\n\tprot3w %0, %4\n\tmtc1 %0, %2" \
            : "=&r" (t), "=f" (z), "=f" (y), "=m" (pmat[OFFX]) : "r" (vec)); \
        pmat[OFFZ] = z; \
        pmat[OFFY] = y; \
        break; }

float *BuildXfLinearRateMatrix(float *pmat, Xf *pxf, QW vec)
{
    memset(pmat, 0, 0x40);
    switch (pxf->mode) {
    case 15:
    case 0:
        break;
    case 1:
    case 4:
    case 5:
    case 9:
    case 10:
        BODY(12, 14, 13)
    case 11:
        BODY(4, 9, 8)
    case 12:
        BODY(0, 10, 5)
    }
    return pmat;
}
