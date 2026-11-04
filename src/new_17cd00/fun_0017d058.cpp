#include "sly2.h"
struct VT { char pad[0x40]; short delta; short index; void (*fn)(void *); };
struct GO { char pad[0xC]; VT *vptr; char pad1[0x2C]; int a3C; };
struct GUARD;
struct CK { float t; };
struct PG { char pad[0x10]; GUARD *guard; char pad1[4]; char child[0x18]; int state; float t; char pad2[4]; int field3C; };
extern "C" void Goal_Pop(void *);
extern "C" GO *func_00205438(GUARD *, int);
extern float g_2dded0;
extern "C" void func_0017D058(PG *pg, int state)
{
    if (state == pg->state)
        return;
    Goal_Pop(pg->child);
    pg->state = state;
    pg->t = ((CK *)&g_2dded0)->t;
    if (state != 0) {
        if (state == 1) {
            GO *go = func_00205438(pg->guard, 0x9D);
            go->a3C = 2;
            VT *vt = go->vptr;
            vt->fn((char *)go + vt->delta);
            pg->field3C = 0;
        }
    } else {
        GO *go = func_00205438(pg->guard, 0x9D);
        go->a3C = 9;
        VT *vt = go->vptr;
        vt->fn((char *)go + vt->delta);
    }
}
