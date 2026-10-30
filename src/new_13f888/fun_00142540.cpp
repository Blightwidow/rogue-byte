#include "sly2.h"
struct VT { char pad[0x40]; short delta; short index; void (*fn)(void *); };
struct GO { char pad[0x0C]; VT *vptr; char pad1[0x30 - 0x10]; int a30; char p34[0x40 - 0x34]; QW a40; };
extern "C" void GoalStack_Clear(char *);
extern "C" GO *func_00205438(char *, int);
extern "C" void func_00142540(char *self, int arg1, QW arg2)
{
    GoalStack_Clear(self + 0x26C);
    if (arg1 != 0) {
        GO *go = func_00205438(self, 0xC2);
        go->a30 = arg1;
        go->a40 = arg2;
        VT *vt = go->vptr;
        vt->fn((char *)go + vt->delta);
    }
}
