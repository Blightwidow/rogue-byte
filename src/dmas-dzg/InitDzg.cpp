#include "sly2.h"
struct ALLOCREQ { int size; int align; };
struct DZG { int crow; char pad[0x4C]; int cxp; int axp; int cso; int apso; void *axpd; };
extern "C" DZG *func_0011A550(DZG *, int);
extern "C" void *PvAllocStackClearImpl__Fi(ALLOCREQ *);
extern "C" DZG *InitDzg(DZG *pdzg, int cxp, int axp, int cso, int apso)
{
    ALLOCREQ req;
    func_0011A550(pdzg, cxp << 1);
    pdzg->cxp = cxp; 
    req.size = pdzg->crow * 0x60;
    pdzg->axp = axp; pdzg->cso = cso; req.align = 0x10; pdzg->apso = apso;
    pdzg->axpd = PvAllocStackClearImpl__Fi(&req);
    return pdzg;
}
