#include "sly2.h"
struct VT { char pad[0x18]; short delta; short index; void (*fn)(void *, int, int, int, int, int); };
struct TANK { char pad0[0xC]; VT *vt; char pad1[0x140]; void *pvjoy; char pad2[0x6C]; void *pcloneSrc; void *ptarget; void *pclone; };
extern "C" {
int FVjoyButtonPressed(void *, int);
void *PloLeaseCloneObject(void *, int);
void LaunchSoAtTarget(void *, void *);
void UpdateTankFire(TANK *ptank)
{
    if (ptank->pvjoy == 0)
        return;
    if (FVjoyButtonPressed(ptank->pvjoy, 0xFF) == 0)
        return;
    if (ptank->pcloneSrc != 0) {
        void *pclone = PloLeaseCloneObject(ptank->pcloneSrc, 0);
        if (pclone == 0)
            return;
        ptank->pclone = pclone;
        if (ptank->ptarget != 0)
            LaunchSoAtTarget(ptank->ptarget, pclone);
        VT *vt = ptank->vt;
        vt->fn((char *)ptank + vt->delta, 5, 0, 0, 0, 0);
    } else {
        VT *vt = ptank->vt;
        vt->fn((char *)ptank + vt->delta, 5, 0, 0, 0, 0);
    }
}
}
