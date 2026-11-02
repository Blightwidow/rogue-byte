#include "sly2.h"
struct XF { char p0[0x90]; void *act; char p1[0x4]; short kind; };
struct PH { char p0[0x80]; QW vec; };
struct SOB { char p0[0x58]; XF *xf; char p1[0x8C]; PH *ph; };
extern "C" void SetXfKind(SOB *, XF *, int);
extern "C" void func_001F5078(SOB *);
extern "C" void SetSoDvGravity(SOB *so, QW gravity)
{
    if (so->ph) {
        XF *xf = so->xf;
        if (xf->act == 0) {
            if (xf->kind != 2)
                SetXfKind(so, xf, 1);
        }
        so->ph->vec = gravity;
        func_001F5078(so);
    }
}
