#include "sly2.h"
#include "vu0inline.h"
struct VT { char pad[0x40]; short d40; short i42; void (*f44)(void *); char pad2[0xE8 - 0x48]; short dE8; short iEA; void (*fEC)(void *, QW);
 char pad3[0x118 - 0xF0]; short d118; short i11A; void (*f11C)(void *, QW); short d120; short i122; void (*f124)(void *, QW); };
struct OBJ { char pad[0xC]; VT *vt; };
#include "goal.h"
struct GOAL_17E9B0 : GOAL { };
extern "C" {
void Goal_Pop(void *);
QW PosLoWorld(void *);
QW func_001C1EC0(void *, QW);
int FFindSurfaceAlongUp(QW *, int, void *, float, float);
void func_0017D608(QW *);
OBJ *func_00205438(void *, int);
void ClearGuardPathMode(void *);
extern QW g_2a2dd0;
}
extern "C" void func_0017E9B0(GOAL_17E9B0 *pgoal)
{
    QW pos;
    Goal_Pop((char *)pgoal + 0x18);
    pos = func_001C1EC0((char *)pgoal + 0x30, PosLoWorld(((OBJ *)pgoal->pstep)));
    if (!FFindSurfaceAlongUp(&pos, 1, 0, 150.0f, -250.0f))
        func_0017D608(&pos);
    if (*(unsigned *)((char *)((OBJ *)pgoal->pstep) + 0xFE8) & 1) {
        OBJ *pmove = func_00205438(((OBJ *)pgoal->pstep), 0xAC);
        *(QW *)((char *)pmove + 0x50) = pos;
        *(int *)((char *)pmove + 0x68) = 1;
        pmove->vt->f44((char *)pmove + pmove->vt->d40);
    } else {
        ClearGuardPathMode(((OBJ *)pgoal->pstep));
        OBJ *pg = ((OBJ *)pgoal->pstep);
        pos = VectorSub(pos, *(QW *)((char *)pg + 0x240));
        pg->vt->fEC((char *)pg + pg->vt->dE8, pos);
        QW *pzero = &g_2a2dd0;
        pg = ((OBJ *)pgoal->pstep);
        pg->vt->f11C((char *)pg + pg->vt->d118, *pzero);
        pg = ((OBJ *)pgoal->pstep);
        pg->vt->f124((char *)pg + pg->vt->d120, *pzero);
    }
}
