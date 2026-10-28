#include "sly2.h"
void *PcmdAllocScript(void *, int, int);
void AddScriptAseg(void *pscript, int oid)
{
    PcmdAllocScript(pscript, 8, oid);
}
