#include "sly2.h"
struct VT { char pad[8]; short deltaAdd; short indexAdd; void (*fnAdd)(void *); short deltaRel; short indexRel; void (*fnRel)(void *); };
struct SMT { char pad[0xC]; unsigned grfsmt; };
struct SMA { char pad[0xC]; VT *vt; char pad10[0x14]; int psm; char pad28[8]; void *pasega; int pad34[2]; int isms; SMT *psmt; };
extern "C" int FSmaRetracted(SMA *);
extern "C" int IsmsFindSmRequired__FP2SM3OID(int, int);
extern "C" void RetractAsega(void *);
extern "C" void ChooseSmaTransition(SMA *, int);
struct HOLD {
    SMA *p;
    HOLD(SMA *s) { p = s; VT *vt = s->vt; vt->fnAdd((char *)s + vt->deltaAdd); }
    ~HOLD() { VT *vt = p->vt; vt->fnRel((char *)p + vt->deltaRel); }
};

void SetSmaGoal__FP3SMA3OID(SMA *psma, int oid)
{
    if (FSmaRetracted(psma))
        return;
    int isms;
    if (oid != -1)
        isms = IsmsFindSmRequired__FP2SM3OID(psma->psm, oid);
    else
        isms = -1;
    if (isms == psma->isms)
        return;
    HOLD hold(psma);
    psma->isms = isms;
    if (psma->pasega) {
        if (psma->psmt->grfsmt & 2)
            RetractAsega(psma->pasega);
    } else {
        ChooseSmaTransition(psma, 0);
    }
}
