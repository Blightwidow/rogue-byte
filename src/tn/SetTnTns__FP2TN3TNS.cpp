#include "sly2.h"
struct VT { char pad[0x18]; short delta; short index; void (*fn)(void *, int, int, int, int, int); };
struct CM { char pad[1]; };
struct CPLCY { char pad[1]; };
struct SO { char pad[1]; };
enum TNS { TNS_X };
enum CPP { CPP_NONE = -1, CPP_X };
struct TN { char pad0[0xC]; VT *vptr; char pad10[0xD0]; SO *so; char pade4[0x44]; int pri; char pad12c[8]; int tns; float tTns; };
extern char B_002DDF40[];
extern float g_2dded0;
void SetCmPolicy(CM *, CPP, CPLCY *, SO *, void *);
void RevokeCmPolicy(CM *, int, CPP, CPLCY *, SO *, void *);

void SetTnTns(TN *t, TNS tns)
{
    if (tns == t->tns)
        return;
    switch (tns) {
    case 1:
        SetCmPolicy((CM *)B_002DDF40, (CPP)(t->pri + 2), (CPLCY *)(B_002DDF40 + 0x3B0), t->so, t);
        t->vptr->fn((char *)t + t->vptr->delta, 5, 1, 0, 0, 0);
        t->tns = tns;
        break;
    case 0:
        RevokeCmPolicy((CM *)B_002DDF40, 8, CPP_NONE, 0, 0, t);
        t->vptr->fn((char *)t + t->vptr->delta, 6, 1, 0, 0, 0);
    default:
        t->tns = tns;
        break;
    }
    t->tTns = g_2dded0;
}
