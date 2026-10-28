// SPDX-License-Identifier: GPL-3.0-or-later
struct VT { char pad[0x40]; short delta; short index; void (*fn)(void *); };
struct ALERT { char pad[0xC]; int palo; };
struct GUARD { char pad[0x294]; void *pcrv; char pad2[0x134]; ALERT *palert; };
struct OBJ { char pad[0xC]; VT *vt; };
struct GOAL { char pad[0x10]; GUARD *pguard; char pad1[0x4]; char child[0x18]; int state; };
extern "C" void Goal_Pop(void *);
extern "C" OBJ *func_00205438(GUARD *, int);
extern "C" void GoalFollowCrv_SetCrv(OBJ *, void *, int);
#define F(o, off, T) (*(T *)((char *)(o) + (off)))
void func_0017C550(GOAL *pgoal, int nState)
{
    if (nState == pgoal->state)
        return;
    Goal_Pop(pgoal->child);
    pgoal->state = nState;
    switch (nState) {
    case 0: {
        OBJ *pobj = func_00205438(pgoal->pguard, 0x9E);
        F(pobj, 0x38, int) = pgoal->pguard->palert->palo;
        VT *vt = pobj->vt;
        vt->fn((char *)pobj + vt->delta);
        break;
    }
    case 1: {
        OBJ *pobj = func_00205438(pgoal->pguard, 0xA7);
        GoalFollowCrv_SetCrv(pobj, pgoal->pguard->pcrv, 0);
        F(pobj, 0xC0, int) = 8;
        F(pobj, 0xC8, int) = pgoal->pguard->palert->palo;
        VT *vt = pobj->vt;
        vt->fn((char *)pobj + vt->delta);
        break;
    }
    }
}
