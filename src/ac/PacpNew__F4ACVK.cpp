#include "sly2.h"
struct ALLOCREQ { int cb; int cbAlign; };
extern "C" void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
extern "C" char D_002CA8A0;
extern "C" char D_002CA8C0;
extern "C" char D_002CB588;

void *PacpNew__F4ACVK(int acvk)
{
    ALLOCREQ allocreq;
    void **pobject;
    switch (acvk) {
    case 0:
        allocreq.cb = 8;
        allocreq.cbAlign = 0x10;
        pobject = (void **)PvAllocSwClearImpl__Fi(&allocreq);
        *pobject = &D_002CA8A0;
        return pobject;
    case 1:
        allocreq.cb = 0xC;
        allocreq.cbAlign = 0x10;
        pobject = (void **)PvAllocSwClearImpl__Fi(&allocreq);
        *pobject = &D_002CA8C0;
        return pobject;
    case 2:
        allocreq.cb = 0x14;
        allocreq.cbAlign = 0x10;
        pobject = (void **)PvAllocSwClearImpl__Fi(&allocreq);
        *pobject = &D_002CB588;
        return pobject;
    }
    return 0;
}
