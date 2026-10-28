#include "sly2.h"
struct XF { char pad[0x88]; void *ptCurrent; void *pgEnd; char pad2[0xA]; short kind; };
struct ALO;
struct CURVE { virtual void v0(); virtual void v1(XF *); };
struct ASEGA { char pad[0x1C]; };
struct ACT { int unk0; ALO *palo; XF *pxf; char pad[0x10]; CURVE *pacp; int unk20; ASEGA *pasega; };
void SetXfKind(ALO *, XF *, int);
void func_0022C818(ALO *, XF *);
void GetActsegRotationGoal(ACT *pact)
{
    if (pact->pacp != 0) {
        pact->pxf->ptCurrent = (char *)pact->pasega + 0x1C;
        pact->pxf->pgEnd = (char *)pact->pasega + 0x40;
        pact->pacp->v1(pact->pxf);
    } else {
        pact->pxf->kind = 0;
        SetXfKind(pact->palo, pact->pxf, 0);
        func_0022C818(pact->palo, pact->pxf);
    }
}
