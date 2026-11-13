#include "sly2.h"
#include "so.h"
extern int D_002C42E8[4];
extern "C" int FIsBasicDerivedFrom(LO *, int);

int FGadgetObjAcceptsStick(void *pgadget, LO *plo)
{
    for (; plo; plo = plo->psoParent) {
        for (unsigned i = 0; i < 4; i++) {
            if (FIsBasicDerivedFrom(plo, D_002C42E8[i]))
                return 0;
        }
    }
    return 1;
}
