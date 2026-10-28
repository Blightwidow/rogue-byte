#include "sly2.h"
extern "C" int Obstacle_IposWrap(void *p, int ipos)
{
    int cpos = ((int *)p)[0x2c];
    int r = ipos % cpos;
    if (r < 0) {
        r = r - 1 + cpos;
    } else {
        if (r == cpos - 1) {
            r = 0;
        }
    }
    return r;
}
