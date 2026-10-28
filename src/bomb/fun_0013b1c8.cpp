#include "sly2.h"
struct BASIC { char pad[0x10]; BASIC *pbasicParent; };
extern "C" int FIsBasicDerivedFrom(BASIC *, void *);
extern "C" void *D_002BC9D0[4];

int func_0013B1C8(int unused, BASIC *pbasic)
{
    while (pbasic) {
        for (unsigned i = 0; i < 4; i++) {
            if (FIsBasicDerivedFrom(pbasic, D_002BC9D0[i]))
                return 0;
        }
        pbasic = pbasic->pbasicParent;
    }
    return 1;
}
