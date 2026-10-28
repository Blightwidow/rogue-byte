#include "sly2.h"
extern "C" {
extern int B_003E1C38;
void *PdescFromLevelRow(int irow);
int IrowFromLevelDesc(void *pdesc)
{
    for (int irow = 0; irow < B_003E1C38; irow++) {
        int *pdescRow = (int *)PdescFromLevelRow(irow);
        int fMatch;
        if (pdesc == pdescRow)
            fMatch = 1;
        else if (pdesc == 0 || pdescRow == 0)
            fMatch = 0;
        else
            { int *pd = (int *)pdesc; int a = pd[2] ^ pd[14]; int b = pdescRow[2] ^ pdescRow[14]; fMatch = a == b; }
        if (fMatch)
            return irow;
    }
    return -1;
}
}
