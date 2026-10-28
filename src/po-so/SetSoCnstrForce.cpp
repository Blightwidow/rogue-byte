#include "sly2.h"
struct XF { char p0[0x90]; void *act; char p1[0x4]; short kind; };
struct PH { char p0[0xB0]; char vec[0x10]; int ct; };
struct SOB { char p0[0x58]; XF *xf; XF *xf2; char p1[136]; PH *ph; };
extern "C" void SetXfKind(SOB *, XF *, int);
extern "C" void ConstrFromCnstr(SOB *, XF *, int, void *);
extern "C" void RecalcSoLocked(SOB *);
extern "C" void func_001F8668(SOB *, int);
extern "C" void SetSoCnstrForce(SOB *so, int cnstr)
{
    if (so->ph) {
        XF *xf = so->xf;
        if (xf->act == 0) {
            if (xf->kind != 2)
                SetXfKind(so, xf, 1);
        }
        ConstrFromCnstr(so, xf, cnstr, so->ph->vec);
        RecalcSoLocked(so);
        if (*(int *)((char *)so->ph + 0xC0) != 3)
            func_001F8668(so, 0);
    }
}
