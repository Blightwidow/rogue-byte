#include "sly2.h"
struct VT { char pad[0x40]; short delta; short index; void (*fn)(void *); };
struct VT48 { char pad[0x48]; short delta; short index; void (*fn)(void *); };
struct OBJ { char pad[0xC]; VT48 *vptr; };
struct OBJ40 { char pad[0xC]; VT *vptr; };
struct HOME { char pad[8]; void *pos; float yaw; };
struct SENSOR { char pad[0xE0]; void *owner; int f; };
struct GUARD {
    char pad0[0xEC];
    int fEC;
    char padF0[0x17C];
    char goalstack[4];
    char pad270[0x80];
    HOME *fHome;
    char pad2F4[0xC];
    QW fPos;
    float fYaw;
    char pad314[0x24];
    int f338;
    int f33C;
    int f340;
    int f344;
    char pad348[0x14C];
    int f494;
    void *fHurt;
    void *fDamage;
    char pad4A0[0x9D8];
    int fE78;
    char padE7C[0x8];
    int fE84;
    int fE88;
    char padE8C[0xD8];
    SENSOR *fSensor;
    char padF68[0x68];
    char fPath[4];
    char padFD4[0x14];
    unsigned fFlags;
    OBJ *fObj;
};
extern "C" {
void func_001CB518(GUARD *, void *);
void GoalStack_Clear(void *);
void func_00209778(void *);
void SetGuardGrfsgs(GUARD *, int);
void func_0020CE40(void *);
void func_0020D1C8(void *);
void EnableFallCheck(void *);
QW PosLoWorld(GUARD *);
float RadYawSo(GUARD *);
void SetStepRadTarget(GUARD *, float);
int GrfsgsFromSgs(int);
void *PguardanimBestMatch(GUARD *, int);
void func_00153EF8(SENSOR *, GUARD *, int);
void func_001F1A40(GUARD *);
void func_001F1CF8(GUARD *);
OBJ40 *func_00205438(GUARD *, int);
void func_001A58D0(SENSOR *, GUARD *, int);
extern int g_2e1e40, g_2f7900, g_2dd5bc, B_002DD648;
}
void OnGuardAdd(GUARD *guard, void *pool)
{
    func_001CB518(guard, pool);
    void *home = &guard->fPos;
    guard->f33C = guard->f338;
    guard->fE88 = guard->fE84;
    guard->f344 = guard->f340;
    GoalStack_Clear(guard->goalstack);
    func_00209778(guard->fPath);
    SetGuardGrfsgs(guard, 0);
    func_0020CE40(guard->fHurt);
    func_0020D1C8(guard->fDamage);
    EnableFallCheck(guard->fHurt);
    guard->fPos = PosLoWorld(guard);
    guard->fYaw = RadYawSo(guard);
    guard->fHome->pos = home;
    guard->fHome->yaw = guard->fYaw;
    SetStepRadTarget(guard, guard->fYaw);
    guard->fFlags = 0;
    if (PguardanimBestMatch(guard, GrfsgsFromSgs(9)))
        guard->fFlags |= 2;
    else
        guard->fE78 = 2;
    if (PguardanimBestMatch(guard, GrfsgsFromSgs(8)))
        guard->fFlags |= 4;
    if (PguardanimBestMatch(guard, GrfsgsFromSgs(0xF)))
        guard->fFlags |= 1;
    if (PguardanimBestMatch(guard, GrfsgsFromSgs(0x11)))
        guard->fFlags |= 8;
    func_00153EF8(guard->fSensor, guard, g_2e1e40);
    func_00153EF8(guard->fSensor, guard, g_2f7900);
    func_00153EF8(guard->fSensor, guard, g_2dd5bc);
    func_00153EF8(guard->fSensor, guard, B_002DD648);
    if (guard->f494) {
        func_001F1A40(guard);
        func_001F1CF8(guard);
    }
    if (guard->fObj)
        guard->fObj->vptr->fn((char *)guard->fObj + guard->fObj->vptr->delta);
    OBJ40 *goal = func_00205438(guard, 0x9C);
    goal->vptr->fn((char *)goal + goal->vptr->delta);
    func_001A58D0(guard->fSensor, guard, 0xF);
    guard->fSensor->owner = guard;
    guard->fSensor->f = guard->fEC;
}
