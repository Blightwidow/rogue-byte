#include "sly2.h"
struct PAIR { int idFilter; int dofFilter; };
struct XF { char pad[0x94]; int dof; int pad98; int id; };
struct ALO { char pad[0x50]; int cxf; char *axf; };
struct ASEGA;
extern "C" void func_00131B10(ASEGA *, ALO *, XF *);

extern "C" void func_00131B60(ASEGA *pasega, ALO *palo, int cpair, PAIR *apair)
{
    for (int ixf = 0; ixf < palo->cxf; ixf++) {
        XF *pxf = (XF *)(palo->axf + ixf * 0x100);
        for (int ipair = 0; ipair < cpair; ipair++) {
            PAIR *ppair = &apair[ipair];
            if (pxf->id != ppair->idFilter && ppair->idFilter != -1)
                continue;
            if (pxf->dof == ppair->dofFilter || ppair->dofFilter == -1) {
                func_00131B10(pasega, palo, pxf);
                break;
            }
        }
    }
}
