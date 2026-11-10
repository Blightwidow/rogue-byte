#include "sly.h"
int FAllowBinocSly(SLY *pjt)
{
    switch (pjt->jts) {
    case 0: return 1;
    case 1: return 1;
    case 5: return 1;
    case 10: return 1;
    case 12: return 1;
    case 24: return 1;
    }
    return 0;
}
