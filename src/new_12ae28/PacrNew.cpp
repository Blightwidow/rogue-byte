#include "sly2.h"
struct ALLOCREQ { int cb; int cbAlign; };
extern "C" void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
extern "C" char D_002CA9A0;
extern "C" char D_002CA978;
extern "C" char D_002CA950;
extern "C" char D_002CA928;
extern "C" char D_002CA900;
extern "C" char D_002CB5A8;

void *PacrNew(int acvk)
{
    ALLOCREQ allocreq;
    void **pobject;
    switch (acvk) {
    case 0:
        allocreq.cb = 0x10;
        allocreq.cbAlign = 0x10;
        pobject = (void **)PvAllocSwClearImpl__Fi(&allocreq);
        *pobject = &D_002CA9A0;
        return pobject;
    case 1:
        allocreq.cb = 0xC;
        allocreq.cbAlign = 0x10;
        pobject = (void **)PvAllocSwClearImpl__Fi(&allocreq);
        *pobject = &D_002CA978;
        return pobject;
    case 2:
        allocreq.cb = 0xC;
        allocreq.cbAlign = 0x10;
        pobject = (void **)PvAllocSwClearImpl__Fi(&allocreq);
        *pobject = &D_002CA950;
        return pobject;
    case 3:
        allocreq.cb = 0x30;
        allocreq.cbAlign = 0x10;
        pobject = (void **)PvAllocSwClearImpl__Fi(&allocreq);
        *pobject = &D_002CA928;
        return pobject;
    case 4:
        allocreq.cb = 0x30;
        allocreq.cbAlign = 0x10;
        pobject = (void **)PvAllocSwClearImpl__Fi(&allocreq);
        *pobject = &D_002CA900;
        return pobject;
    case 5:
        allocreq.cb = 0x20;
        allocreq.cbAlign = 0x10;
        pobject = (void **)PvAllocSwClearImpl__Fi(&allocreq);
        *pobject = &D_002CB5A8;
        return pobject;
    }
    return 0;
}
