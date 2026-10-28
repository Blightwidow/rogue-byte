#include "sly2.h"
void *PcmdAllocScript(void *, int, int);
void AddScriptJump(void *pscript, int oid)
{
    PcmdAllocScript(pscript, 10, oid);
}
