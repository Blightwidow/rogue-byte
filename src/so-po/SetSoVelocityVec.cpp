#include "sly2.h"
struct XF { char pad0[0x94]; int dof; short kind; char pad9a[0xA0 - 0x9A]; int parent; char pada4[0xB0 - 0xA4]; QW vec; };
struct SO;
struct VT { char pad[0x108]; short delta; short index; QW (*fn)(void *); };
struct SO { char pad0[0xC]; VT *vptr; char pad10[0x58 - 0x10]; XF *xf; };
extern "C" int FXfKindHasVelocity(int);
extern "C" void SetXfKind(SO *, XF *, int);
extern "C" QW ConvertXfVec(int, int, QW);
extern "C" void WakeXf(SO *, XF *);
extern "C" void func_001F4BF8(SO *);
extern "C" void func_001F5078(SO *);
extern "C" void func_001F8668(SO *, int);

void SetSoVelocityVec(SO *so, QW v)
{
    XF *xf = so->xf;
    if (xf && xf->dof == 1) {
        if (!FXfKindHasVelocity(xf->kind)) {
            SetXfKind(so, xf, 1);
        }
        int *vel = (int *)&xf->vec;
        vel[2] = 0;
        vel[1] = 0;
        vel[0] = 0;
        VT *vtable = so->vptr;
        QW base = vtable->fn((char *)so + vtable->delta);
        register QW result asm("$2");
        register int parentArg asm("$5") = xf->parent;
        asm volatile("lqc2 vf1, %1\n\tdaddu $4, $0, $0\n\tqmtc2.ni %2, vf2\n\tlw $5, 0xA0(%3)\n\tvsub.xyzw vf1, vf1, vf2\n\t.set noreorder\n\tjal ConvertXfVec\n\tqmfc2.ni $6, vf1\n\t.set reorder" : "=r"(result) : "m"(v), "r"(base), "r"(xf) : "$3", "$4", "$5", "$6", "$7", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "$24", "$25", "$31", "memory");
        xf->vec = result;
        WakeXf(so, xf);
        func_001F4BF8(so);
        func_001F5078(so);
        func_001F8668(so, 0);
    }
}
