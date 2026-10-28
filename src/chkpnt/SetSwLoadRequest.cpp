#include "sly2.h"
struct LOADREQ { int a[19]; };
struct SW { char pad[0x3BF0]; int pending; LOADREQ req; };

void SetSwLoadRequest(SW *psw, LOADREQ *preq)
{
    psw->pending = 1;
    psw->req = *preq;
}
