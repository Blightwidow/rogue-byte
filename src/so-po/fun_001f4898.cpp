#include "sly2.h"
struct XF { char pad[0x98]; short kind; char pad2[0x6]; int unk0xA0; char pad3[0xC]; QW vel; };
struct SO { char pad[0x58]; XF *linear; XF *angular; XF *parent; };
extern "C" int FXfKindHasVelocity(short);
extern "C" void SetXfKind(SO *, XF *, int);
extern "C" QW ConvertXfVec(XF *, int, QW);
extern "C" void WakeXf(SO *, XF *);
extern "C" void func_001F4BF8(SO *);
extern "C" void func_001F5078(SO *);
extern "C" void func_001F8668(SO *, int);

void func_001F4898(SO *so, QW v)
{
    if (!FXfKindHasVelocity(so->linear->kind))
        SetXfKind(so, so->linear, 1);
    XF *xf = so->linear;
    xf->vel = ConvertXfVec(so->parent, xf->unk0xA0, v);
    WakeXf(so, so->linear);
    func_001F4BF8(so);
    func_001F5078(so);
    func_001F8668(so, 0);
}
