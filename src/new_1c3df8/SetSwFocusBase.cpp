#include "sly2.h"
struct CRef { int tagk; int n; int pad[2]; };
struct VT { char pad[0x270]; short delta; short idx; void (*fn)(void *, int); };
struct PO { char pad[0xC]; VT *vt; char pad2[0x18 - 0x10]; int oid; };
struct SW { char pad[0x3EFC]; PO *base; PO *over; };
extern "C" {
PO *PpoSwFocus(SW *);
int FIsBasicDerivedFrom(PO *, int);
void func_001D8B20(CRef *, CRef *, const char *, int);
void CRef_Destruct(CRef *);
void UpdateSwTargetList(SW *, int, int, int);
void func_001C48C0(SW *);
extern const char RO_002A76F8[];
}
void SetSwFocusBase(SW *psw, PO *ppo)
{
    PO *ppoOld = PpoSwFocus(psw);
    PO *ppoNew = psw->over;
    if (ppoNew == 0)
        ppoNew = ppo;
    if (ppoOld != ppoNew && ppoOld != 0)
        ppoOld->vt->fn((char *)ppoOld + ppoOld->vt->delta, 0);
    psw->base = ppo;
    if (ppoOld != ppoNew && ppoNew != 0)
        ppoNew->vt->fn((char *)ppoNew + ppoNew->vt->delta, 1);
    if (ppo != 0) {
        if (FIsBasicDerivedFrom(ppo, 0x34)) {
            CRef result;
            CRef value;
            value.tagk = 0x15;
            value.n = ppo->oid;
            func_001D8B20(&result, &value, RO_002A76F8, 0);
            CRef_Destruct(&result);
            CRef_Destruct(&value);
        }
    }
    UpdateSwTargetList(psw, 0, 0, 0);
    func_001C48C0(psw);
}
