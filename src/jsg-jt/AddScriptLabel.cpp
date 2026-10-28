#include "sly2.h"
void *PcmdAllocScript(void *, int, int);
void AddScriptLabel(void *pscript, int oid)
{
    PcmdAllocScript(pscript, 9, oid);
}
