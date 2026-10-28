#include "sly2.h"
struct MURRAY { char pad[0x13D0]; int state; };
int FInvulnerableJt(void *, int);
extern "C" int func_00194640(void *, int);
int FInvulnerableMurray(MURRAY *pmurray, int grftak)
{
    switch (pmurray->state) {
    case 20:
        if (grftak == 0x4000)
            return 1;
        break;
    case 15:
        return 1;
    case 13:
        if (func_00194640((char *)pmurray + 0x4c0, grftak) != 0)
            return 1;
        break;
    }
    return FInvulnerableJt(pmurray, grftak);
}
