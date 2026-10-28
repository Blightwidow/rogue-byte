#include "sly2.h"
struct VT { short delta; short index; void (*fn)(void *, int, void *); };
struct VTmsg { char pad[0x198]; short delta; short index; void (*fn)(void *, int *); };
struct VTstate { char pad[0x260]; short delta; short index; void (*fn)(void *, int); };
struct Obj { char pad0[0xC]; char *vptr; };
struct LO2 { char pad[0xC]; VTmsg *vt; };
struct LO3 { char pad[0xC]; VTstate *vt; };
struct DPRIZE { char pad0[0xC]; VTstate *vt; char pad[0x168 - 0x10]; int psma; char pad2[0x218 - 0x16C]; LO2 *onExpire; };
extern "C" void HandleLoMessage(DPRIZE *, int, int *);

void func_001C5098(DPRIZE *prize, int msg, int *pv)
{
    HandleLoMessage(prize, msg, pv);
    if (msg == 10) {
        if (pv[0] == prize->psma) {
            if (pv[2] == 0x186) {
                LO2 *lo = prize->onExpire;
                if (lo) {
                    int amsg[16];
                    amsg[0] = 1;
                    amsg[1] = (int)prize;
                    VTmsg *vtable = lo->vt;
                    vtable->fn((char *)lo + vtable->delta, amsg);
                }
                VTstate *vtable = prize->vt;
                vtable->fn((char *)prize + vtable->delta, 2);
            }
        }
    }
}
