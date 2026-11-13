#include "lo.h"
// SPDX-License-Identifier: GPL-3.0-or-later
extern "C" void EnableLasen__FP5LASEN5SENSM(LO *plo)
{
    plo->HandleSpliceEvent(5, 0, 0, 0, 0);
}
