#include "sly2.h"
struct GOALV {
    int pad0[3];
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
    virtual void Activate();
};
struct GOALPICK {
    int pad0[4];
    GOALV *pguard;
    char child[0x18 - 0x14];
    int pad1[9];
    int state;
    float tState;
    int pad2[2];
    GOALV *pick;
};
struct GOALR : GOALV { char pad[0x30 - 0x10]; GOALV *target; int unk34, unk38, unk3C; int flag; };
extern "C" void Goal_Pop(void *);
extern "C" GOALR *func_00205438(void *, int);
extern "C" void func_00208540(void *, int);
extern float g_2dded0;
void func_0017B8B0(GOALPICK *goal, int newState)
{
    if (newState == goal->state)
        return;
    Goal_Pop((char *)goal + 0x18);
    goal->state = newState;
    goal->tState = g_2dded0;
    switch (newState) {
    case 0: {
        GOALR *watch = func_00205438(goal->pguard, 0x9e);
        watch->Activate();
        func_00208540(goal->pguard, 0);
        break;
    }
    case 1: {
        GOALR *react = func_00205438(goal->pguard, 0xa5);
        react->flag = 1;
        react->target = goal->pick;
        react->Activate();
        break;
    }
    case 2: {
        GOALR *watch = func_00205438(goal->pguard, 0x9e);
        watch->unk3C = 1;
        watch->Activate();
        break;
    }
    }
}
