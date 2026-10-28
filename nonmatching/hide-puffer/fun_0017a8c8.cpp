// SPDX-License-Identifier: GPL-3.0-or-later
struct GUARD { char pad[0x32C]; int fDown; };
struct GOAL { char pad[0x10]; GUARD *pguard; char pad1[0x4]; char child[0x18]; int state; float tState; };
struct VT { char pad[0x40]; short delta; short index; void (*fn)(void *); };
struct OBJ { char pad[0xC]; VT *vt; char pad2[0x2C]; int kind; };
struct B8 { char b[8]; };
struct KT { B8 a; B8 b; int c; };
extern "C" const KT RO_002A55A0;
extern "C" float g_2dded0;
extern "C" void Goal_Pop(void *);
extern "C" void func_001EF038(GOAL *);
extern "C" OBJ *func_00205438(GUARD *, int);
void func_0017A8C8(GOAL *pgoal, int nState)
{
    if (pgoal->state == nState)
        return;
    Goal_Pop(pgoal->child);
    float t = g_2dded0;
    pgoal->state = nState;
    pgoal->tState = t;
    if (nState != -1) {
        if (nState > -2) {
            if (nState < 5) {
                OBJ *pobj = func_00205438(pgoal->pguard, 0x9D);
                KT kinds = RO_002A55A0;
                pobj->kind = ((int *)&kinds)[pgoal->state];
                VT *vt = pobj->vt;
                vt->fn((char *)pobj + vt->delta);
                pgoal->pguard->fDown = (unsigned)pgoal->state < 2;
            }
        }
    } else {
        func_001EF038(pgoal);
        pgoal->pguard->fDown = 0;
    }
}
