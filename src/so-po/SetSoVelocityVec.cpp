// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
#include "xf.h"
#include "so.h"
#include "vu0inline.h"

extern "C" int FXfKindHasVelocity(short);
extern "C" void SetXfKind(SO *, XF *, int);
extern "C" QW ConvertXfVec(XF *, XF *, QW);
extern "C" void WakeXf(SO *, XF *);
extern "C" void func_001F4BF8(SO *);
extern "C" void func_001F5078(SO *);
extern "C" void func_001F8668(SO *, int);

void SetSoVelocityVec(SO *so, QW v)
{
    XF *xf = so->pxfLinear;
    if (xf && xf->dof == 1) {
        if (!FXfKindHasVelocity(xf->kind))
            SetXfKind(so, xf, 1);
        int *vel = (int *)&xf->vel;
        vel[2] = 0;
        vel[1] = 0;
        vel[0] = 0;
        QW base = so->GetVelocityVec();
        xf->vel = ConvertXfVec(0, xf->pxfParent, VectorSub(v, base));
        WakeXf(so, xf);
        func_001F4BF8(so);
        func_001F5078(so);
        func_001F8668(so, 0);
    }
}
