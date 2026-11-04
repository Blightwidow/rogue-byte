// SPDX-License-Identifier: GPL-3.0-or-later
struct QWV_k02 { float v[4]; };
struct GVT_k02 { char pad[0x40]; short delta; void (*fn)(void *); };
struct GOBJ_k02 { char pad[0xC]; GVT_k02 *vptr; char p1[0x38 - 0x10]; void *a38; int a3c; int a40; };
struct TVT_k02 { char pad[0x100]; short delta; void *(*fn)(void *, void *); };
struct SRC_k02 { char pad[0xA0]; void *a0A0; char p1[0xC0 - 0xA4]; void *a0C0; };
struct PBEH_k02 {
    char pad0[0x10];
    int id;
    void *sub18;
    void *sub30;
    int state;
    float t;
    SRC_k02 *src;
};
extern "C" {
void Goal_Pop(void *);
void SubscribeLoObject(void *, int);
void UnsubscribeLoObject(void *, int);
GOBJ_k02 *func_00205438(int, int);
void func_0020AC28(int, int, int, QWV_k02);
void func_001EF038(void *);
extern QWV_k02 g_2a2dd0;
extern float g_2dded0;
}
extern "C" void func_00175488(PBEH_k02 *pthis, int state)
{
    if (state == pthis->state)
        return;
    if (pthis->state == 0) {
        UnsubscribeLoObject(pthis->sub30, pthis->id);
        pthis->sub30 = 0;
        func_0020AC28(pthis->id, 0, 0, g_2a2dd0);
    }
    Goal_Pop(&pthis->sub18);
    pthis->state = state;
    pthis->t = g_2dded0;
    if (state == 0) {
        SubscribeLoObject(pthis->sub30, pthis->id);
        GOBJ_k02 *pobj = func_00205438(pthis->id, 0x9F);
        pobj->a38 = pthis->sub30;
        pobj->a40 = (int)pthis->src->a0C0;
        if (pthis->src->a0A0 != 0) {
            TVT_k02 *tvt = *(TVT_k02 **)((char *)pthis->sub30 + 0xC);
            QWV_k02 local;
            void *ret = tvt->fn((char *)pthis->sub30 + tvt->delta, &local);
            func_0020AC28(pthis->id, (int)pthis->src, (int)ret, local);
        }
        pobj->vptr->fn((char *)pobj + pobj->vptr->delta);
    } else if (state == 1) {
        GOBJ_k02 *pobj = func_00205438(pthis->id, 0x9D);
        pobj->a3c = 4;
        pobj->a38 = pthis->sub30;
        pobj->vptr->fn((char *)pobj + pobj->vptr->delta);
    } else if (state == -1) {
        func_001EF038(pthis);
    }
}
