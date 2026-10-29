#include "sly2.h"
struct Button { char p0[0x2AC]; int cploPush; int aploPush[8]; int ccidPush; int acidPush[8]; };
extern "C" int FIsBasicDerivedFrom(int, int);
static inline int IndexOf(int *a, int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (a[i] == x)
            break;
    return i;
}
int FCheckButtonObject(Button *pbutton, int pobject)
{
    int result;
    int cploPush = pbutton->cploPush;
    if (cploPush > 0) {
        if (IndexOf(pbutton->aploPush, cploPush, pobject) >= cploPush)
            { result = 0; goto done; }
    }
    if (pbutton->ccidPush > 0) {
        int icid;
        for (icid = 0; icid < pbutton->ccidPush; icid++)
            if (FIsBasicDerivedFrom(pobject, pbutton->acidPush[icid]))
                break;
        if (icid >= pbutton->ccidPush)
            return 0;
    }
    { result = 1; goto done; }
done:
    return result;
}
