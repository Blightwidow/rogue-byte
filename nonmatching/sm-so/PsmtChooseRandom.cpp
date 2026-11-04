#include "sly2.h"
struct SMT { char pad[0x14]; float g; };
extern "C" float GRandInRange(float, float);
extern "C" SMT *PsmtChooseRandom(void *sm, int count, SMT **items)
{
    float total = 0.0f;
    for (int index = 0; index < count; index++) total += items[index]->g;
    total = GRandInRange(0.0f, total);
    for (int index = 0; index < count; index++) {
        total -= items[index]->g;
        if (total <= 0.0f) return items[index];
    }
    return 0;
}
