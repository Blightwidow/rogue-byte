#include "sly2.h"
typedef int QW __attribute__((mode(TI)));
struct CRef { int tagk; int pad[3]; };
struct BASIC;
struct B8 { char b[8]; int w; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" CRef *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void func_00185E30(BASIC *, QW, QW, QW);
extern const B8 RO_002A3F08;

CRef *func_0010B618(CRef *result, BASIC *object, int count, CRef *args)
{
    struct L { B8 aotyp; int pad; QW q; QW r; QW s; CRef ref;  } l;
    l.aotyp = RO_002A3F08;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&l.ref, 3, args, (const int *)&l.aotyp, &l.q, &l.r, &l.s);
    CRef_Destruct(&l.ref);
    SetTag__4CRef4TAGK(&l.ref, 0x24);
    func_00185E30(object, l.q, l.r, l.s);
    CRef_CopyConstruct(result, &l.ref);
    CRef_Destruct(&l.ref);
    return result;
}
