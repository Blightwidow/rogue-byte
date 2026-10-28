#include "sly2.h"
void *PcmdAllocScript(void *, int, int);
void AddScriptContext(void *pscript, int oid)
{
    PcmdAllocScript(pscript, 0, oid);
}
