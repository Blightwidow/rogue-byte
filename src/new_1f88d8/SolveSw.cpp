#include "sly2.h"
struct ENT { unsigned flags; void *obj; };
struct VT { char pad[0x88]; short d; short i; void (*fn)(void *); };
struct OBJ { char pad[0xC]; VT *vt; };
struct SW { char pad[0x3F14]; int count; char pad1[4]; int *pidx; ENT *ents; };
extern "C" void RecalcSwXpAll(SW *);
extern "C" void func_001F8F80(SW *, int);
void SolveSw(SW *psw)
{
    int index;
    RecalcSwXpAll(psw);
    psw->pidx = &index;
    index = 0;
    while (index < psw->count) {
        ENT *e = &psw->ents[index];
        if ((e->flags & 0x24) == 4) {
            OBJ *o = (OBJ *)e->obj;
            o->vt->fn((char *)o + o->vt->d);
        }
        index++;
    }
    psw->pidx = 0;
    func_001F8F80(psw, 1);
    RecalcSwXpAll(psw);
    func_001F8F80(psw, 6);
}
