#include "sly2.h"
extern "C" int FXfKindDynamic(int kind)
{
    if (kind < 4) {
        if (kind > 0)
            return 1;
    }
    return 0;
}
