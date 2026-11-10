#include "sly2.h"
struct TASK { char pad[0x18]; int oid; };
#include "sw.h"
extern int B_002DEB44;
void SetSwCurrentTask(SW *psw, TASK *ptask)
{
    psw->ptaskCurrent = ptask;
    if (ptask)
        B_002DEB44 = ptask->oid;
    else
        B_002DEB44 = -1;
}
