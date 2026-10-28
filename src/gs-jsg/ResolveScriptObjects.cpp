#include "sly2.h"
struct CMD { int op; int oid; char pad[0x10]; CMD *pnext; };
struct SCRIPT { char pad[0x50]; CMD *pcmd; };
extern char B_003DD490[];
extern "C" void *PloFindSwObject_thunk(void *, int, int, void *);
extern "C" int func_001709A8(void *);
extern "C" void EnsureCrvExcludedRanges(void *);
extern "C" void ResolveScriptObjects(SCRIPT *pscript)
{
    void *ploContext = pscript;
    CMD *pcmd = pscript->pcmd;
    while (pcmd != 0) {
        if (pcmd->op != 0) {
            if (pcmd->op == 6) {
                void *plo = PloFindSwObject_thunk(B_003DD490, 4, pcmd->oid, ploContext);
                if (plo != 0 && func_001709A8(plo) == -1)
                    EnsureCrvExcludedRanges(plo);
            }
        } else {
            ploContext = PloFindSwObject_thunk(B_003DD490, ploContext != 0 ? 4 : 5, pcmd->oid, ploContext);
        }
        pcmd = pcmd->pnext;
    }
}
