#include "sly2.h"
#include "sw.h"

void SetSwLoadRequest(SW *psw, LOADREQ *preq)
{
    psw->fLoadPending = 1;
    psw->loadreq = *preq;
}
