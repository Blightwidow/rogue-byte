#include "sly2.h"
#include "murray.h"
extern "C" int func_00144388(void *);
extern "C" int func_001A6AF8(void *, SO *);
extern "C" int IMax(int, int);
extern "C" int func_00220498(void *, void *, int);
int func_001B8450(MURRAY *pmurray, void *pso)
{
    int level = func_00144388(pmurray);
    if (pmurray->psoDropped != 0 && func_001A6AF8(pso, pmurray->psoDropped) != 0) {
        level = IMax(level, 3);
    } else if (pmurray->state == 0xf) {
        level = func_00220498((char *)pmurray + 0x1910, pso, level);
    }
    return level;
}