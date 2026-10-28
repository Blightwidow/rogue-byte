#include "sly2.h"
struct SO { char pad[0xB8]; int rank; char pad2[0xC8 - 0xBC]; int value; };
struct LEVEL { char pad[0x3E5C]; int value; void *plo; };
extern "C" int CploFindSwObjectsByClass(LEVEL *, int, int, int, int, SO **);
extern "C" void SetLoGrfzon(SO *, int);

void func_0020E2B0(LEVEL *plevel)
{
    SO *apso[16];
    int count = CploFindSwObjectsByClass(plevel, 5, 0x31, 0, 16, apso);
    int best = 0;
    SO *pbest = 0;
    int i;
    for (i = 0; i < count; i++) {
        SO *pso = apso[i];
        if (best < pso->rank) {
            best = pso->rank;
            pbest = pso;
        }
    }
    if (pbest) {
        plevel->value = pbest->value;
        SetLoGrfzon(pbest, 0xFF);
    }
}
