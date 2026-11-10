#include "so.h"
struct GEOM {
    char pad0[0xC];
    int alo;
    char pad1[0xA0];
};
extern "C" GEOM *PpartFindAlo(SO *so, int alo)
{
    for (int index = 0; index < so->cgeom; index++) {
        if (so->ageom[index].alo == alo)
            return &so->ageom[index];
    }
    return 0;
}
