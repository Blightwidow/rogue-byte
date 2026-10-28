#include "sly2.h"
struct CRef { int tagk; int pad[3]; void operator=(const CRef &); };
struct NODE { char pad[8]; int ref[2]; NODE *next; };
struct LIST { int carg; NODE *first; };
extern "C" {
void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, int *, ...);
void CRef_Destruct(CRef *);
void SetTag__4CRef4TAGK(CRef *, int);
}
CRef *func_002013D8(CRef *result, LIST *list, int otyp, int unused, int *pcArg, int *apvArg)
{
    if (list->carg == 0) {
        *pcArg = 0;
        SetTag__4CRef4TAGK(result, 0x24);
    } else {
        *pcArg = 0;
        for (NODE *node = list->first; node != 0; node = node->next) {
            CRef refItem;
            refItem.tagk = -1;
            CRef refValue;
            RefSetArgsFromSplice__FiP4CRefP4OTYPe(&refValue, 1, (CRef *)node->ref, &otyp, &apvArg[*pcArg]);
            refItem = refValue;
            CRef_Destruct(&refValue);
            *pcArg = *pcArg + 1;
            CRef_Destruct(&refItem);
        }
        SetTag__4CRef4TAGK(result, 0x24);
    }
    return result;
}
