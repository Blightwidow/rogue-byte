/* SPDX-License-Identifier: GPL-3.0-or-later */
struct VT_142340 { char pad[0x2C0]; short delta; short unused; void (*fn)(void *, int, void *); };
struct JT_142340 { char pad[0xC]; VT_142340 *vt; char pad2[0x4C0 - 0x10]; char attach[8]; int kind; };
extern "C" void StartAttach(void *, int, void *, int);
extern "C" void SetJtAttach9(JT_142340 *pjt, void *ptarget, void *pextra) {
    if (ptarget != 0) {
        StartAttach(pjt->attach, 9, ptarget, 0);
    } else if (pjt->kind == 9) {
        pjt->vt->fn((char *)pjt + pjt->vt->delta, 0, pextra);
    }
}
