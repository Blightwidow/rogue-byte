#include "sly2.h"
struct Button { char p0[0x2AC]; int cploPush; int aploPush[8]; int ccidPush; int acidPush[8]; };
extern "C" int FIsBasicDerivedFrom(int, int);
int FCheckButtonObject(Button *pbutton, int pobject)
{
    if (pbutton->cploPush > 0) {
        int iplo;
        for (iplo = 0; iplo < pbutton->cploPush; iplo++)
            if (pbutton->aploPush[iplo] == pobject)
                break;
        if (iplo >= pbutton->cploPush)
            return 0;
    }
    if (pbutton->ccidPush > 0) {
        int icid;
        for (icid = 0; icid < pbutton->ccidPush; icid++)
            if (FIsBasicDerivedFrom(pobject, pbutton->acidPush[icid]))
                break;
        if (icid >= pbutton->ccidPush)
            return 0;
    }
    return 1;
}
