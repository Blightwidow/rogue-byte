#include "sly2.h"
struct SAPEP { int pad; unsigned short fMin; unsigned short islot; };
void CopyAb(void *, void *, unsigned int);
extern "C" void RemovePathzoneEndpoints(int cep, SAPEP *aep, unsigned int islot, int iepMin)
{
    int iepMax;
    for (int iep = 0; iep < cep; iep++) {
        if (aep[iep].islot == islot) {
            if (aep[iep].fMin != 0)
                iepMin = iep;
            else {
                iepMax = iep;
                break;
            }
        }
    }
    SAPEP *dstA = &aep[iepMin];
    CopyAb(dstA, dstA + 1, (iepMax - iepMin - 1) * 8);
    SAPEP *srcB = &aep[iepMax];
    CopyAb(srcB - 1, srcB + 1, (cep - iepMax - 1) * 8);
}
