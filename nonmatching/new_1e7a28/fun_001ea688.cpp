#include "sly2.h"

int CpassMaterial(const unsigned char* pmaterial)
{
    if (pmaterial[4] == 1)
        return 2;
    if (pmaterial[4] == 7) {
        int cpass = 2;
        if ((pmaterial[5] & 0x20) == 0)
            cpass = 3;
        return cpass;
    }
    return 1;
}
