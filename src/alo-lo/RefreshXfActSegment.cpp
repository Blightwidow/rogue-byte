// SPDX-License-Identifier: GPL-3.0-or-later
struct VT22DD00 { char pad[0x20]; short delta; short index; void (*fn)(void *); };
struct Obj22DD00 { char pad[0x18]; VT22DD00 *vptr; };
struct Xf22DD00;
struct XfAct22DD00 {
    char pad0[0x80];
    float low;
    float high;
    float *pvalue;
    char pad8c[4];
    Obj22DD00 *pobj;
    char pad94[4];
    short kind;
    short segment;
};
void func_0022C818(Xf22DD00 *, XfAct22DD00 *);
void SetXfKind(Xf22DD00 *, XfAct22DD00 *, int);

extern "C" void RefreshXfActSegment(Xf22DD00 *pxf, XfAct22DD00 *pact) {
    float value = *pact->pvalue;
    if (value < pact->low || pact->high < value || pact->segment >= 3) {
        Obj22DD00 *pobj = pact->pobj;
        if (pobj != 0) {
            VT22DD00 *vt = pobj->vptr;
            vt->fn((char *)pobj + vt->delta);
            switch (pact->kind) {
            case 10:
                if ((unsigned short)pact->segment - 3U >= 2U) {
                    if (pact->segment != 2)
                        SetXfKind(pxf, pact, 6);
                    break;
                }
                SetXfKind(pxf, pact, 7);
                break;
            case 6:
                if ((unsigned short)pact->segment - 3U < 2U)
                    SetXfKind(pxf, pact, 7);
                break;
            case 0x13:
                if (pact->segment != 2)
                    SetXfKind(pxf, pact, 0x12);
                break;
            case 12:
                if (pact->segment != 2)
                    SetXfKind(pxf, pact, 0xB);
                break;
            }
        } else {
            pact->segment = 0;
            func_0022C818(pxf, pact);
            SetXfKind(pxf, pact, 0);
        }
    }
}
