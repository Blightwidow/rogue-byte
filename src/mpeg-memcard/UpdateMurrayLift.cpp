#include "sly2.h"
struct LO { char pad[0x28]; unsigned long grf; };
struct CARRIER { char pad[0x180]; LO *lo; };
struct MURRAY { char pad[0x1030]; void *pasega; char pad2[0x13F0 - 0x1034]; CARRIER *carrier; char pad3[0x1448 - 0x13F4]; int lift; char pad4[4]; int lifts; };
extern "C" void SetMurrayState(MURRAY *, int);
extern "C" int FAsegaGone(void *);
void UpdateMurrayLift(MURRAY *m)
{
    for (;;) {
        int a = m->lifts;
        switch (a) {
        case -1: break;
        case 1:
            if (m->lift) {
                if (!m->carrier) {
                    SetMurrayState(m, 0);
                } else {
                    unsigned long bit = (m->carrier->lo->grf >> 60) & 1;
                    if (!bit) {
                        SetMurrayState(m, 0);
                        m->carrier = 0;
                    }
                }
            }
            break;
        case 2:
            if (FAsegaGone(m->pasega))
                SetMurrayState(m, 5);
            break;
        }
        if (m->lifts == a || m->lifts == -1)
            return;
    }
}
