#include "sly2.h"
struct Guard { char pad[0xF80]; int mode; void *target; float arc; int n; void *ref; };
struct Obj { char pad[0x124]; int f124; };
extern "C" {
int FIsBasicDerivedFrom(void *, int);
QW PosLoWorld(void *);
void FindCrvClosestPointAll(void *, QW, int, int, int, int, float *);
void func_00204F78(Guard *, void *, int);
}

void SetGuardPathTarget(Guard *guard, void *target, int n)
{
    guard->target = target;
    guard->n = n;
    if (FIsBasicDerivedFrom(target, 0xB) != 0) {
        guard->mode = 1;
        FindCrvClosestPointAll(guard->target, PosLoWorld(guard->ref), 0, 0, 0, 0, &guard->arc);
    } else if (FIsBasicDerivedFrom(guard->target, 0xD) != 0) {
        guard->mode = 0;
        FindCrvClosestPointAll(guard->target, PosLoWorld(guard), 0, 0, 0, 0, &guard->arc);
    } else {
        if (FIsBasicDerivedFrom(guard->target, 0x13) != 0) {
            Obj *obj = (Obj *)guard->target;
            if (obj->f124 == 3) {
                guard->mode = 2;
                func_00204F78(guard, guard->target, 1);
                return;
            }
        }
        if (FIsBasicDerivedFrom(guard->target, 0x27) == 0) {
            guard->target = 0;
            return;
        }
        guard->mode = 3;
    }
    func_00204F78(guard, guard->target, 1);
}
