// SPDX-License-Identifier: GPL-3.0-or-later
struct CPair { int pad0; int pad4; int tagk; int n; CPair *next; };
struct SAVEPATH { int c; short *as; };
struct ALLOCREQ { int cb; int align; };
extern "C" void *PvAllocStackImpl__Fi(ALLOCREQ *);
extern "C" void ConvertListToSavePath(CPair *plist, SAVEPATH *ppath)
{
    ppath->c = 0;
    ppath->as = 0;
    CPair *ppair = plist;
    for (; ppair != 0; ppair = ppair->next) {
        ppath->c = ppath->c + 1;
    }
    ALLOCREQ req;
    if (ppath->c == 0) {
        return;
    }
    req.cb = ppath->c << 1;
    req.align = 0x10;
    ppath->as = (short *)PvAllocStackImpl__Fi(&req);
    int index = 0;
    for (ppair = plist; ppair != 0; ppair = ppair->next) {
        if (ppair->tagk == 0x15 || ppair->tagk == 0x18) {
            int value = ppair->n;
            ppath->as[index] = value;
        }
        index++;
    }
}
