#include "sly2.h"
struct STEP;
struct VT { char pad[0x8]; short d8; short i8; void (*f8)(void *); short d10; short i10; void (*f10)(void *); };
struct OBJ { char pad[0xC]; VT *vt; };
struct Clock { float time; float dt; };
extern Clock g_2dded0;
extern int g_2e1e40;
extern QW g_2a2dd0;
extern "C" {
void RetractAsega(void *);
void ApplyAseg(void *, void *, float, float, int, void *);
int FIsGuardInSgs(void *, int);
char *func_00205458(void *, int);
void func_0012E460(void *);
int func_0012DC18(void *, int, int, int, int, QW);
}
void SetStepSpinRatio(STEP *, float);
#define F(type, base, off) (*(type *)((char *)(base) + (off)))

extern "C" void func_001BA408(void *guard, int mode)
{
    int modeOld = F(int, guard, 0x1018);
    if (mode == modeOld)
        return;
    if (modeOld == 1) {
        RetractAsega(F(void *, guard, 0x1024));
        OBJ *pasega = F(OBJ *, guard, 0x1024);
        pasega->vt->f10((char *)pasega + pasega->vt->d10);
        F(int, guard, 0x1024) = 0;
        func_0012E460((char *)guard + 0x102C);
        F(int, guard, 0x102C) = 0;
        F(int, guard, 0x1028) = 0;
        if (FIsGuardInSgs(guard, 2))
            F(int, func_00205458(guard, 0x9E), 0x38) = g_2e1e40;
        SetStepSpinRatio((STEP *)guard, 1.0f);
        F(int, guard, 0x1018) = mode;
    } else {
        F(int, guard, 0x1018) = mode;
    }
    F(float, guard, 0x101C) = g_2dded0.time;
    if (mode == 1) {
        ApplyAseg(F(void *, guard, 0x1020), guard, 0.0f, 1.0f, 1, (char *)guard + 0x1024);
        OBJ *pasega = F(OBJ *, guard, 0x1024);
        pasega->vt->f8((char *)pasega + pasega->vt->d8);
        F(int, guard, 0x102C) = func_0012DC18(guard, F(int, guard, 0x1034), 5, 8, 3, g_2a2dd0);
        if (FIsGuardInSgs(guard, 2)) {
            F(int, func_00205458(guard, 0x9E), 0x38) = F(int, guard, 0x1028);
            SetStepSpinRatio((STEP *)guard, 4.0f);
        }
    }
}
