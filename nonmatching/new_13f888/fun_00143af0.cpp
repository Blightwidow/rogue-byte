#include "sly2.h"
struct CRef { int tagk; int n; int pad[2]; };
struct JVT { char pad[0x338]; short delta; short idx; void *(*fn)(void *); };
struct JtObj { char pad0[0xC]; JVT *vt; };
extern "C" char B_003D4A60[];
extern "C" const char RO_002A4DB0[];
extern "C" {
void *PpathFindBootyOid(int);
void RefSetGameSaveValue(CRef *, void *, CRef *);
void CRef_CopyConstruct(CRef *, CRef *);
void CRef_Destruct(CRef *);
void func_001D8B20(CRef *, CRef *, void *, const char *, int);
}
struct Jt { char pad[0x18]; int oid; };
void *func_00143AF0(Jt *pjt, int idLoot)
{
    CRef refs[3];
    void *ppath = PpathFindBootyOid(pjt->oid);
    if (ppath) {
        refs[0].tagk = 0x15;
        refs[0].n = idLoot;
        CRef_CopyConstruct(&refs[1], &refs[0]);
        RefSetGameSaveValue(&refs[2], ppath, &refs[1]);
        CRef_Destruct(&refs[2]);
        CRef_Destruct(&refs[1]);
        CRef_Destruct(&refs[0]);
    }
    refs[1].tagk = 0x15;
    refs[1].n = -1;
    JtObj * obj;
    func_001D8B20(&refs[0], &refs[1], obj->vt->fn((char *)obj + obj->vt->delta), RO_002A4DB0, 0);
    obj = (JtObj *)pjt;
    CRef_Destruct(&refs[1]);
    CRef_Destruct(&refs[0]);
    return ppath;
}
