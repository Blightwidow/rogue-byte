/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct ALO;
struct XF { char pad[0x98]; unsigned short kind; short sub; };
void SetXfKind(ALO *, XF *, int);
void SleepXf(ALO *alo, XF *xf)
{
    switch ((short)(xf->kind - 1)) {
    case 6:
    case 8:
        if (xf->sub == 2)
            SetXfKind(alo, xf, 10);
        else if (xf->sub == 1)
            SetXfKind(alo, xf, 6);
        break;
    case 10:
        if (xf->sub == 2)
            SetXfKind(alo, xf, 0xc);
        break;
    case 17:
        if (xf->sub == 2)
            SetXfKind(alo, xf, 0x13);
        break;
    case 0:
        SetXfKind(alo, xf, 3);
        break;
    }
}
