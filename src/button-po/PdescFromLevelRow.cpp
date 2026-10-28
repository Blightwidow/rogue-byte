#include "sly2.h"
struct PDESC { char pad[64]; };
extern PDESC* B_003E1C40;
PDESC* PdescFromLevelRow(int row)
{
    if (row == -1) return 0;
    return B_003E1C40 + row;
}
