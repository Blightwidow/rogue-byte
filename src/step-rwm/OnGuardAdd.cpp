#include "sly2.h"
struct VT { char pad[0x40]; short delta; short index; void (*fn)(void *); };
struct VT48 { char pad[0x48]; short delta; short index; void (*fn)(void *); };
struct OBJ { char pad[0xC]; VT48 *vptr; };
struct OBJ40 { char pad[0xC]; VT *vptr; };
struct HOME { char pad[8]; void *pos; float yaw; };
struct SENSOR { char pad[0xE0]; void *owner; struct OXA *f; };
#include "stepguard.h"
extern "C" {
void func_001CB518(STEPGUARD *, void *);
void GoalStack_Clear(void *);
void func_00209778(void *);
void SetGuardGrfsgs(STEPGUARD *, int);
void func_0020CE40(void *);
void func_0020D1C8(void *);
void EnableFallCheck(void *);
QW PosLoWorld(STEPGUARD *);
float RadYawSo(STEPGUARD *);
void SetStepRadTarget(STEPGUARD *, float);
int GrfsgsFromSgs(int);
void *PguardanimBestMatch(STEPGUARD *, int);
void func_00153EF8(SENSOR *, STEPGUARD *, int);
void func_001F1A40(STEPGUARD *);
void func_001F1CF8(STEPGUARD *);
OBJ40 *func_00205438(STEPGUARD *, int);
void func_001A58D0(SENSOR *, STEPGUARD *, int);
extern int g_2e1e40, g_2f7900, g_2dd5bc, B_002DD648;
}
void OnGuardAdd(STEPGUARD *guard, void *pool)
{
    func_001CB518(guard, pool);
    void *home = &guard->posHome;
    guard->field_0x33C = guard->field_0x338;
    guard->field_0xE88 = guard->field_0xE84;
    guard->field_0x344 = guard->field_0x340;
    GoalStack_Clear(((char *)guard + 0x26C));
    func_00209778(&guard->field_0xFD0);
    SetGuardGrfsgs(guard, 0);
    func_0020CE40(guard->field_0x498);
    func_0020D1C8(guard->field_0x49C);
    EnableFallCheck(guard->field_0x498);
    guard->posHome = PosLoWorld(guard);
    guard->radHome = RadYawSo(guard);
    guard->phome->pos = home;
    guard->phome->yaw = guard->radHome;
    SetStepRadTarget(guard, guard->radHome);
    guard->grf = 0;
    if (PguardanimBestMatch(guard, GrfsgsFromSgs(9)))
        guard->grf |= 2;
    else
        guard->field_0xE78 = 2;
    if (PguardanimBestMatch(guard, GrfsgsFromSgs(8)))
        guard->grf |= 4;
    if (PguardanimBestMatch(guard, GrfsgsFromSgs(0xF)))
        guard->grf |= 1;
    if (PguardanimBestMatch(guard, GrfsgsFromSgs(0x11)))
        guard->grf |= 8;
    func_00153EF8(guard->psensor, guard, g_2e1e40);
    func_00153EF8(guard->psensor, guard, g_2f7900);
    func_00153EF8(guard->psensor, guard, g_2dd5bc);
    func_00153EF8(guard->psensor, guard, B_002DD648);
    if (guard->prig) {
        func_001F1A40(guard);
        func_001F1CF8(guard);
    }
    if (guard->field_0xFEC)
        guard->field_0xFEC->Remove();
    OBJ40 *goal = func_00205438(guard, 0x9C);
    goal->vptr->fn((char *)goal + goal->vptr->delta);
    func_001A58D0(guard->psensor, guard, 0xF);
    guard->psensor->owner = guard;
    guard->psensor->f = guard->poxa;
}
