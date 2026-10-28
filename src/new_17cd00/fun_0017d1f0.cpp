#include "sly2.h"
struct VSLOT { short delta; short index; void (*fn)(void *); };
struct Obj { char pad0[0xC]; VSLOT *vtable; char pad1[0x3C - 0x10]; int mode; };
struct Guard { char pad0[0x1B0]; QW facing[3]; };
struct Guard2 { char pad0[0xF84]; void *crv; };
struct Goal { char pad0[0x10]; Guard *guard; };
struct M3 { QW row[3]; };
extern "C" QW g_2a2dc0;
extern "C" void func_001EEF70(Goal *);
extern "C" Obj *func_00205438(Guard *, int);
extern "C" QW *PmatLoWorld(void *);
extern "C" void BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(M3 *, QW, QW);
void func_0017D1F0(Goal *goal)
{
    M3 mat;
    func_001EEF70(goal);
    Obj *obj = func_00205438(goal->guard, 0x9D);
    obj->mode = 2;
    VSLOT *slot = &obj->vtable[8];
    slot->fn((char *)obj + slot->delta);
    Guard *guard = goal->guard;
    QW *path = PmatLoWorld(*(void **)((char *)guard + 0xF84));
    BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(&mat, path[0], g_2a2dc0);
    guard->facing[0] = mat.row[0];
    guard->facing[1] = mat.row[1];
    guard->facing[2] = mat.row[2];
}
