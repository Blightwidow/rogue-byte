#include "vu0inline.h"
#include "sly2.h"
#include "xf.h"

struct SMP;
extern "C" {
MATRIX4 InvertMatrix4Affine(const MATRIX4 *);
MATRIX4 __ml__FRC7MATRIX4T0(const MATRIX4 &, const MATRIX4 &);
float GSmooth__FfffP3SMPPf(float, float, float, SMP *, float *);
extern char D_002C3C68[];
extern float g_2dded0[];
}

union STEPPOS { QW quad; float lane[4]; };

struct STEPSIDE {
    XF *pxf;
    char pad4[0xC];
    float **ppout;
    char pad14[0x8];
    int count;
    char pad20[0x5C];
    QW *pvec;
};

struct STEPHOLDER {
    char pad[0x258];
    STEPSIDE *pfirst;
    STEPSIDE *psecond;
};

void UpdateStepPhys__FP4STEP(STEPHOLDER *step)
{
    MATRIX4 local;
    STEPPOS position;
    if (step->pfirst != 0 && step->psecond != 0) {
        QW *pvec = step->psecond->pvec;
        QW *pbase = step->pfirst->pvec;
        float *prow = *step->pfirst->ppout;
        local = __ml__FRC7MATRIX4T0(InvertMatrix4Affine(&step->pfirst->pxf->matWorld), step->psecond->pxf->matWorld);
        int remaining = step->psecond->count - 1;
        if (remaining >= 0) {
            float *pposition = position.lane;
            do {
                QW vector = *pvec;
                QW *pvecNext = pvec + 1;
                QW *pbaseNext = pbase + 1;
                QW point = TransformPoint(vector, local.row[0], local.row[1], local.row[2], local.row[3]);
                float *pwrite = prow;
                position.quad = point;
                float *pcurrent = pposition;
                float *pold = (float *)pbase;
                prow += 4;
                int axis = 2;
                do {
                    float updated = GSmooth__FfffP3SMPPf(*pold, *pcurrent, g_2dded0[1], (SMP *)D_002C3C68, 0);
                    pcurrent++;
                    *pwrite = (updated - *pold) / g_2dded0[1];
                    pold++;
                    pwrite++;
                } while (--axis >= 0);
                pvec = pvecNext;
                pbase = pbaseNext;
                remaining--;
            } while (remaining >= 0);
        }
    }
}
