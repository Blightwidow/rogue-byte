#include "sly2.h"
struct TASK { char pad[0x18]; int oid; };
#include "sw.h"
extern int B_002DEB48;
void SetSwRestartTask(SW *psw, TASK *ptask)
{
    psw->ptaskRestart = ptask;
    if (ptask)
        B_002DEB48 = ptask->oid;
    else
        B_002DEB48 = -1;
}
