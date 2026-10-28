#include "sly2.h"

void LoadVolumeFromBrx(void *pvolbtn, void *pbis);
void InitBtn(void *pbtn, void *pvolbtn);

void LoadVolbtnFromBrx__FP6VOLBTNP18CBinaryInputStream(void *pvolbtn, void *pbis)
{
    LoadVolumeFromBrx(pvolbtn, pbis);
    InitBtn((char *)pvolbtn + 0x130, pvolbtn);
    if (*(int *)((char *)pvolbtn + 0x2C8) != 0)
        *(int *)((char *)pvolbtn + 0x1D4) = 1;
}