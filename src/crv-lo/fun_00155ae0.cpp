#include "ps2inline.h"
#include "vu0inline.h"
struct VT { char pad[0x40]; short delta; short index; void (*fn)(void *); };
struct GO { char pad[0x0C]; VT *vptr; char pad1[0x30 - 0x10]; int a30; char p34[4]; int a38; int a3C; int a40; char p44[0x4C-0x44]; int a4C; char p50[0xC0-0x50]; int aC0; char pC4[4]; int aC8; };
struct CURVE { char pad[0xE8]; int a_e8; char padEC[0xF4 - 0xEC]; QW *points; };
struct RANGE { char pad[0x60]; float low; float high; };
struct ACTOR { char pad[0x294]; CURVE *curve; char pad2[0xF04 - 0x298]; float timer; char pad3[0xFD0 - 0xF08]; char heading[4]; };
struct CK { float t; };
struct PG { char pad[0x10]; ACTOR *actor; char pad2[0x18 - 0x14]; char child[0x18]; int state; float t; char p38[4]; float a3c; GO *a40; char p44[0x4C - 0x44]; int a4C; int a50; RANGE *a54; };
extern "C" {
float GRandInRange(float, float);
void Goal_Pop(void *);
GO *func_00155A68(PG *);
GO *func_00205438(void *, int);
QW PosLoWorld(void *);
float atan2f(float, float);
void func_00209818(char *, float);
void func_0020AC28(void *, int, int, QW);
void GoalFollowCrv_SetCrv(GO *, void *, int);
void MeasureCrv(void *);
extern QW g_2a2dd0;
extern CK g_2dded0; // a scalar global as a one-member struct (docs/contributing/exceptions.md)
}
extern "C" void func_00155AE0(PG *pg, int state)
{
    if (state == pg->state)
        return;
    switch (pg->state) {
    case 1:
        func_0020AC28(pg->actor, 0, 0, g_2a2dd0);
        break;
    case 3:
        float base = g_2dded0.t;
        pg->actor->timer = base + GRandInRange(pg->a54->low, pg->a54->high);
        pg->a54 = 0;
        break;
    }
    Goal_Pop(pg->child);
    pg->state = state;
    pg->t = g_2dded0.t;
    switch (state) {
    case 0: {
        pg->a40 = (GO *)func_00155A68(pg);
        GO *go = func_00205438(pg->actor, 0x9D);
        go->a3C = 0xB;
        QW first = PosLoWorld(pg->a40);
        QW second = PosLoWorld(pg->actor);
        QW delta = VectorSub(first, second);
        float angle = atan2f(LaneX(RotateWords3(delta)), LaneX(delta)) + 3.1415927f;
        func_00209818(pg->actor->heading, angle);
        VT *vt = go->vptr;
        vt->fn((char *)go + vt->delta);
        pg->a3c = 3.4028235e38f;
        break; }
    case 1: {
        GO *go = func_00205438(pg->actor, 0x9E);
        go->a38 = pg->a4C;
        VT *vt = go->vptr;
        vt->fn((char *)go + vt->delta);
        break; }
    case 2: {
        GO *follow = func_00205438(pg->actor, 0xA7);
        CURVE *curve = pg->actor->curve;
        curve->a_e8 = state;
        QW *first = curve->points;
        *first = PosLoWorld(pg->actor);
        QW *second = curve->points;
        second[1] = PosLoWorld(pg->a40);
        MeasureCrv(curve);
        GoalFollowCrv_SetCrv(follow, curve, 0);
        VT *vt = follow->vptr;
        follow->aC0 = 8;
        follow->aC8 = pg->a4C;
        follow->a40 = 1;
        vt->fn((char *)follow + vt->delta);
        break; }
    case 3: {
        GO *go = func_00205438(pg->actor, 0xA4);
        go->a3C = (int)pg->a54;
        go->a30 = pg->a4C;
        VT *vt = go->vptr;
        vt->fn((char *)go + vt->delta);
        pg->actor->timer = 3.4028235e38f;
        pg->a50 = pg->a50 + 1;
        break; }
    }
}
