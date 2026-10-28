#include "sly2.h"
struct VT { char pad[0x40]; short delta; short index; void (*fn)(void *); };
struct GO { char pad[0x0C]; VT *vptr; char pad1[0x38 - 0x10]; int a38; char pad2[0xC0 - 0x3C]; int aC0; int aC4; float aC8; };
struct PO { char pad[0x150]; int a150; };
struct PG { char pad0[0x10]; void *pjt; char pad1[0x18 - 0x14]; char child[0x18]; void *pleader; char pad2[0x60 - 0x34]; int state; float t; };
extern "C" {
extern float g_2dded0;
struct CK { float t; };
void Goal_Pop(void *);
void WarpJtToPoint(void *, QW);
GO *func_00205438(void *, int);
int FIsBasicDerivedFrom(void *, int);
float GRandInRange(float, float);
void func_001457A8(PG *);
int CidGetBasic(void *);
}
extern "C" void func_00145B18(PG *pgoal, int state)
{
    if (state == pgoal->state)
        return;
    Goal_Pop(pgoal->child);
    pgoal->state = state;
    pgoal->t = ((CK *)&g_2dded0)->t;
    switch (state) {
    case 0: {
        GO *pgo = func_00205438(pgoal->pjt, 0xA8);
        if (FIsBasicDerivedFrom(pgoal->pleader, 0x32) != 0) {
            pgo->aC0 = ((PO *)pgoal->pleader)->a150;
            pgo->aC4 = 8;
            pgo->aC8 = GRandInRange(0.1f, 0.3f);
        }
        func_001457A8(pgoal);
        VT *vt = pgo->vptr;
        vt->fn((char *)pgo + vt->delta);
        break;
    }
    case 1:
        WarpJtToPoint(pgoal->pjt, *(QW *)((char *)pgoal + 0x80));
        break;
    case 2: {
        int cid = CidGetBasic(pgoal->pjt);
        switch (cid) {
        case 0x36: {
            GO *pgoA = func_00205438(pgoal->pjt, 0xC3);
            pgoA->a38 = *(int *)((char *)pgoal + 0x90);
            VT *vtA = pgoA->vptr;
            vtA->fn((char *)pgoA + vtA->delta);
            break;
        }
        case 0x37: {
            GO *pgoB = func_00205438(pgoal->pjt, 0xC4);
            pgoB->a38 = *(int *)((char *)pgoal + 0x90);
            VT *vtB = pgoB->vptr;
            vtB->fn((char *)pgoB + vtB->delta);
            break;
        }
        case 0x35: {
            GO *pgoC = func_00205438(pgoal->pjt, 0xC5);
            pgoC->a38 = *(int *)((char *)pgoal + 0x90);
            VT *vtC = pgoC->vptr;
            vtC->fn((char *)pgoC + vtC->delta);
            break;
        }
        }
        break;
    }
    }
}
