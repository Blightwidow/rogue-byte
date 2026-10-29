#include "sly2.h"

void CBinaryFileStream_PumpFile(void *);
void PumpCd__18CBinaryInputStream(void *);

void CBinaryFileStream_Pump(char *arg0)
{
    if (*(int *)(arg0 + 0x3C) >= 0) {
        CBinaryFileStream_PumpFile(arg0);
        return;
    }
    if (*(int *)(arg0 + 0x50) >= 0) {
        PumpCd__18CBinaryInputStream(arg0);
        return;
    }
    *(int *)(arg0 + 0x10) = 0;
    *(int *)(arg0 + 0x14) = 0;
}
