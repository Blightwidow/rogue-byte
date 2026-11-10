// SPDX-License-Identifier: GPL-3.0-or-later
struct PVT { char pad[0xA8]; short delta; short index; void (*fn)(void *, int); };
struct PART { char pad[0xC]; PVT *vt; };
#include "sly.h"
extern "C" void func_00205D10();
#define SETPART(p, v) ((p)->vt->fn((char *)(p) + (p)->vt->delta, (v)))
void SetSlyHide(SLY *pjt, int fHide)
{
    func_00205D10();
    if (fHide != 0) {
        SETPART(pjt->apartHide[0], 0);
        SETPART(pjt->apartHide[1], 0);
        SETPART(pjt->apartHide[2], 0);
    } else {
        SETPART(pjt->apartHide[0], 1);
        SETPART(pjt->apartHide[1], 1);
        SETPART(pjt->apartHide[2], 1);
    }
}
