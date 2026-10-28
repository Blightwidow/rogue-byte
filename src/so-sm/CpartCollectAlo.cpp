#include "sly2.h"
struct PART;
struct ALO { char pad[0xE0]; int cpart; char *apart; };
int CpartCollectAlo(ALO *palo, int (*pfn)(void *, PART *), void *ctx, PART **appart)
{
    int count = 0;
    for (int i = 0; i < palo->cpart; i++) {
        PART *p = (PART *)(palo->apart + i * 0xB0);
        if (pfn == 0 || pfn(ctx, p) != 0) {
            appart[count] = p;
            count++;
        }
    }
    return count;
}
