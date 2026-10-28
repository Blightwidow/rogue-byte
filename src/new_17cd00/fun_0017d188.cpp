#include "sly2.h"
struct OWNER { char pad[0xF88]; float zRef; };
struct GOAL { char pad[0x10]; OWNER *powner; char pad2[0x24]; float z; };
int func_0017D188(GOAL *pgoal)
{
    float diff = pgoal->powner->zRef - pgoal->z;
    int result = 1;
    if (__builtin_fabsf(diff) < 50.0f) {
    } else
        result = 0;
    return result;
}
