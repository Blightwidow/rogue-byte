#include "sly2.h"
struct VT {
    char p0[0x40];
    short d40; short i40; void (*f40)(void *);
};
struct OBJ {
    char p0[0xC];
    VT *vt;
    char p10[0x38 - 0x10];
    void *p38;
    char p3C[0x40 - 0x3C];
    void *p40;
};
struct ZSS {
    char p0[0x10];
    void *pworld10;
    char p14[0x18 - 0x14];
    void *p18;
    char p1C[0x30 - 0x1C];
    int state30;
    float f34;
    void *p38;
};
extern "C" {
OBJ *func_00205438(void *, int);
void func_00171C18(void *, void *);
void Goal_Pop(void *);
void SetGuardScript(OBJ *, void *, int, void *);
void bevy_camera_follow_activity(void *, int, void *);
}
extern float g_2dded0;
extern void *g_2e1e40;
extern char B_002DEB30[];
extern "C" void SetZoneScriptState(ZSS *pzs, int state)
{
    if (state == pzs->state30) return;
    if (pzs->state30 == 0) func_00171C18(pzs->p18, (char *)pzs->pworld10 + 0x1090);
    Goal_Pop(&pzs->p18);
    pzs->f34 = g_2dded0;
    pzs->state30 = state;
    switch (state) {
    case 0: {
        OBJ *pobj = func_00205438(pzs->pworld10, 0xA9);
        SetGuardScript(pobj, pzs->p38, 0, (char *)pzs->pworld10 + 0x1090);
        pobj->vt->f40((char *)pobj + pobj->vt->d40);
        break;
    }
    case 1: {
        OBJ *pobj = func_00205438(pzs->pworld10, 0x9E);
        pobj->p38 = g_2e1e40;
        pobj->vt->f40((char *)pobj + pobj->vt->d40);
        break;
    }
    case 2: {
        OBJ *pobj = func_00205438(pzs->pworld10, 0x9D);
        pobj->p40 = (char *)pzs->pworld10 + 0x1060;
        pobj->vt->f40((char *)pobj + pobj->vt->d40);
        bevy_camera_follow_activity(B_002DEB30, 0x33, pzs->pworld10);
        break;
    }
    }
}
