// SPDX-License-Identifier: GPL-3.0-or-later
struct SW;
extern SW B_003DD490;
struct VT { char pad[0x158]; short delta; short index; unsigned (*fn)(void *, int); };
struct LOBJ { char pad[0xC]; VT *vt; };
struct CHNPART { int ipart; int oid; };
extern "C" LOBJ *PloFindSwObject_thunk(SW *, int, int, void *);
extern "C" void func_00130010(void *paseg, void *paloRoot, CHNPART *pchnPart, LOBJ **ppalo, unsigned *pnTarget)
{
    if (paloRoot != 0) *ppalo = PloFindSwObject_thunk(&B_003DD490, 1, pchnPart->oid, paloRoot);
    else *ppalo = PloFindSwObject_thunk(&B_003DD490, 4, pchnPart->oid, paseg);
    if (*ppalo == 0) *pnTarget = 0;
    else { VT *vt = (*ppalo)->vt; *pnTarget = vt->fn((char *)*ppalo + vt->delta, pchnPart->ipart); }
}
