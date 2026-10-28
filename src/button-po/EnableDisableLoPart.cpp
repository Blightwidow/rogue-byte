#include "sly2.h"
struct SW; struct LO; struct ALO;
extern "C" void *PloFindSwObject_thunk(SW*, int, int, LO*);
extern "C" int FIsBasicDerivedFrom(void*, int);
extern "C" void func_001F6AC8(void*, int);
extern "C" void func_001F6B48(void*, int);
extern "C" void EnableDisableLoPart(SW* psw, int fShow, int oid, int oidGlob, ALO* paloDefault, LO* ploContext)
{
    ALO* palo;
    if (oid == -1)
        palo = paloDefault;
    else
        palo = (ALO*)PloFindSwObject_thunk(psw, 4, oid, ploContext);
    if (palo != 0 && FIsBasicDerivedFrom(palo, 0x30) != 0) {
        if (fShow != 0)
            func_001F6AC8(palo, oidGlob);
        else
            func_001F6B48(palo, oidGlob);
    }
}
