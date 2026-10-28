// SPDX-License-Identifier: GPL-3.0-or-later
struct PVT { char pad[0xA8]; short delta; short index; void (*fn)(void *, int); };
struct PART { char pad[0xC]; PVT *vt; };
struct JT { char pad[0x19A0]; PART *p0; PART *p1; PART *p2; };
extern "C" void func_00205D10();
#define SETPART(p, v) ((p)->vt->fn((char *)(p) + (p)->vt->delta, (v)))
void SetSlyHide(JT *pjt, int fHide)
{
    func_00205D10();
    if (fHide != 0) {
        SETPART(pjt->p0, 0);
        SETPART(pjt->p1, 0);
        SETPART(pjt->p2, 0);
    } else {
        SETPART(pjt->p0, 1);
        SETPART(pjt->p1, 1);
        SETPART(pjt->p2, 1);
    }
}
