#include "sly2.h"
struct TASK { char pad[0x18]; int oid; };
struct SW { char pad[0x3B10]; TASK *taskCurrent; TASK *taskRestart; };
extern int B_002DEB44;
void SetSwCurrentTask(SW *psw, TASK *ptask)
{
    psw->taskCurrent = ptask;
    if (ptask)
        B_002DEB44 = ptask->oid;
    else
        B_002DEB44 = -1;
}
