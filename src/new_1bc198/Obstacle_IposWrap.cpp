#include "sly2.h"
extern "C" int Obstacle_IposWrap(void *p, int ipos)
{
    int cpos = ((int *)p)[0x3a];
    int r = ipos % cpos;
    if (!(r >= 0)) {
        int before = r - 1;
        r = before + cpos;
    } else {
        if (r == cpos - 1) {
            r = 0;
        }
    }
    return r;
}
