#include "sly2.h"
struct CRef { int tagk; int n; int pad[2]; CRef &operator=(const CRef &); };
struct VTB { char pad[0x198]; short delta; short index; void (*fn)(void *, int *); };
struct OBJ { char pad[0xC]; VTB *vt; };
struct VTC { char pad[0x18]; short delta; short index; void (*fn)(void *, int, int, int, int, int); };
struct LOOTDEF { int pad; int lootkc; };
struct COIN { char pad0[0xC]; VTC *vt; char pad1[0x150 - 0x10]; int state; char pad2[0x210 - 0x154]; OBJ *owner; char pad3[0x230 - 0x214]; float waitMin; float waitMax; float wait; char pad4[0x244 - 0x23C]; LOOTDEF *lootdef; };
extern "C" {
float GRandInRange(float, float);
void CRef_Destruct(CRef *);
void func_001D8A38(CRef *, const char *, const char *, char *, int);
void func_001D8B20(CRef *, CRef *, const char *, const char *, char *, int);
int sprintf(char *, const char *, ...);
void SetDprizeDprizes(COIN *, int);
extern const char RO_002A7768[];
extern const char RO_002A7770[];
extern const char RO_002A7778[];
}

void SetCoinState(COIN *coin, int state)
{
    if (coin->state == state) return;
    switch (state) {
    case 0:
        coin->wait = GRandInRange(coin->waitMin, coin->waitMax);
        break;
    case 1: {
        struct L { CRef ref; char name[0x10]; CRef result; CRef value; int msg[2]; char pad[0x38]; } l;
        l.ref.tagk = -1;
        sprintf(l.name, RO_002A7768, coin->lootdef->lootkc);
        func_001D8A38(&l.result, RO_002A7770, RO_002A7778, l.name, 0);
        l.ref = l.result;
        CRef_Destruct(&l.result);
        l.value.tagk = 0x15;
        l.value.n = l.ref.n + 1;
        func_001D8B20(&l.result, &l.value, RO_002A7770, RO_002A7778, l.name, 0);
        CRef_Destruct(&l.result);
        CRef_Destruct(&l.value);
        OBJ *owner = coin->owner;
        if (owner) {
            l.msg[0] = state;
            l.msg[1] = (int)coin;
            VTB *vt = owner->vt;
            vt->fn((char *)owner + vt->delta, l.msg);
        }
        state = 2;
        coin->vt->fn((char *)coin + coin->vt->delta, 5, 0, 0, 0, 0);
        CRef_Destruct(&l.ref);
        break;
    }
    }
    SetDprizeDprizes(coin, state);
}
