#include "sly2.h"
struct UL { unsigned long v; } __attribute__((packed));
#include "stepguard.h"
/* The routine PostGuardLoad creates (class 0x71): its home follows LO's fields. */
struct ROUTINE : LO { HOME *phome; };
extern "C" {
void PostStepLoad(STEPGUARD *);
void SetSoProperties(STEPGUARD *, int, void *);
void SetStepGravityRatio__FP4STEPf(STEPGUARD *, float);
void SetXfKind(STEPGUARD *, XF *, int);
void BindGuardAnimrefs(STEPGUARD *);
void ResolveGuardAimObjects(STEPGUARD *);
void *__builtin_new(unsigned int);
void func_0020CE28(void *, STEPGUARD *);
void func_0020D1B0(void *, STEPGUARD *);
void QueueSwCallback(void *, STEPGUARD *, unsigned long, int);
ROUTINE *PloNew(int, int, int, int);
void AddScriptGoto(LO *, int, int, float);
void *func_001F4C58(STEPGUARD *, int, int);
void *func_0012DC18(STEPGUARD *, void *, int, int, int, QW);
extern char D_002C3CF8[];
extern char B_003DD490[];
extern const UL RO_002A8608;
extern QW RO_002A2DE0;
}
void PostGuardLoad(STEPGUARD *guard)
{
    PostStepLoad(guard);
    SetSoProperties(guard, 1, D_002C3CF8);
    SetStepGravityRatio__FP4STEPf(guard, guard->field_0x260);
    SetXfKind(guard, guard->pxfLinear, 2);
    SetXfKind(guard, guard->pxfAngular, 2);
    BindGuardAnimrefs(guard);
    ResolveGuardAimObjects(guard);
    void *hurt = __builtin_new(0x10);
    guard->field_0x498 = hurt;
    func_0020CE28(hurt, guard);
    void *damage = __builtin_new(0x14);
    guard->field_0x49C = damage;
    func_0020D1B0(damage, guard);
    if (guard->pscope->field_0x24 == 0)
        QueueSwCallback(B_003DD490, guard, RO_002A8608.v, 0);
    ROUTINE *routine = PloNew(0x71, 0, 0x2CB, -1);
    guard->field_0x2EC = routine;
    AddScriptGoto(routine, -1, -1, 40.0f);
    ROUTINE *home = (ROUTINE *)guard->field_0x2EC;
    guard->phome = home->phome;
    home->Remove();
    if (guard->field_0x3F4) {
        guard->field_0x3F4->Remove();
    }
    if (guard->field_0x3F8) {
        guard->field_0x3F8->Remove();
    }
    void *found = func_001F4C58(guard, guard->oid, 0xC);
    if (found)
        guard->field_0xFC4 = func_0012DC18(guard, found, 0, 7, 2, RO_002A2DE0);
}
