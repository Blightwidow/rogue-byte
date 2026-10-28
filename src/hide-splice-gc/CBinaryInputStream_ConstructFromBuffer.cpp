#include "sly2.h"
extern "C" void CBinaryInputStream_Constructor(void *);
extern "C" char D_002D2918[];

void *CBinaryInputStream_ConstructFromBuffer(void *pstream, int size, int address, int grf)
{
    int *pint = (int *)pstream;
    CBinaryInputStream_Constructor(pstream);
    int start = (address + 0x3F) & ~0x3F;
    pint[0x30 / 4] = (int)D_002D2918;
    pint[0] = grf;
    pint[0x34 / 4] = (address + size - start) & ~0x3F;
    pint[0x50 / 4] = -1;
    pint[0x3C / 4] = -1;
    pint[0x38 / 4] = start;
    pint[0x60 / 4] = 0;
    pint[0x5C / 4] = 0;
    pint[0x58 / 4] = 0;
    pint[0x54 / 4] = 0;
    pint[0x4C / 4] = 0;
    pint[0x48 / 4] = 0;
    pint[0x44 / 4] = 0;
    pint[0x40 / 4] = 0;
    return pstream;
}
