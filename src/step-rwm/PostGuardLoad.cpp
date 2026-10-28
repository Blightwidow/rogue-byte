#include "sly2.h"
struct UL { unsigned long v; } __attribute__((packed));
struct VT { char pad[0x48]; short delta; short index; void (*fn)(void *); };
struct OBJ { char pad[0xC]; VT *vptr; };
struct LO { char pad[0xC]; VT *vptr; char pad2[0x40]; int f50; };
struct GUARD {
    char pad0[0x18];
    int f18;
    char pad1C[0x20];
    int *f3c;
    char pad40[0x18];
    void *f58;
    void *f5c;
    char pad60[0x200];
    float f260;
    char pad264[0x88];
    LO *f2EC;
    int f2F0;
    char pad2F4[0x100];
    OBJ *f3F4;
    OBJ *f3F8;
    char pad3FC[0x9C];
    int *f498;
    int *f49C;
    char pad4A0[0xB24];
    void *fFC4;
};
extern "C" {
void PostStepLoad(GUARD *);
void SetSoProperties(GUARD *, int, void *);
void SetStepGravityRatio__FP4STEPf(GUARD *, float);
void SetXfKind(GUARD *, void *, int);
void BindGuardAnimrefs(GUARD *);
void ResolveGuardAimObjects(GUARD *);
void *__builtin_new(unsigned int);
void func_0020CE28(void *, GUARD *);
void func_0020D1B0(void *, GUARD *);
void QueueSwCallback(void *, GUARD *, unsigned long, int);
LO *PloNew(int, int, int, int);
void AddScriptGoto(LO *, int, int, float);
void *func_001F4C58(GUARD *, int, int);
void *func_0012DC18(GUARD *, void *, int, int, int, QW);
extern char D_002C3CF8[];
extern char B_003DD490[];
extern const UL RO_002A8608;
extern QW RO_002A2DE0;
}
void PostGuardLoad(GUARD *guard)
{
    PostStepLoad(guard);
    SetSoProperties(guard, 1, D_002C3CF8);
    SetStepGravityRatio__FP4STEPf(guard, guard->f260);
    SetXfKind(guard, guard->f58, 2);
    SetXfKind(guard, guard->f5c, 2);
    BindGuardAnimrefs(guard);
    ResolveGuardAimObjects(guard);
    int *hurt = (int *)__builtin_new(0x10);
    guard->f498 = hurt;
    func_0020CE28(hurt, guard);
    int *damage = (int *)__builtin_new(0x14);
    guard->f49C = damage;
    func_0020D1B0(damage, guard);
    if (guard->f3c[9] == 0)
        QueueSwCallback(B_003DD490, guard, RO_002A8608.v, 0);
    LO *routine = PloNew(0x71, 0, 0x2CB, -1);
    guard->f2EC = routine;
    AddScriptGoto(routine, -1, -1, 40.0f);
    LO *home = guard->f2EC;
    guard->f2F0 = home->f50;
    home->vptr->fn((char *)home + home->vptr->delta);
    if (guard->f3F4) {
        OBJ *object = guard->f3F4;
        object->vptr->fn((char *)object + object->vptr->delta);
    }
    if (guard->f3F8) {
        OBJ *object = guard->f3F8;
        object->vptr->fn((char *)object + object->vptr->delta);
    }
    void *found = func_001F4C58(guard, guard->f18, 0xC);
    if (found)
        guard->fFC4 = func_0012DC18(guard, found, 0, 7, 2, RO_002A2DE0);
}
