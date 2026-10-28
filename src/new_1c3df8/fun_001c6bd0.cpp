#include "sly2.h"
struct XFV { char pad[0xB0]; int x, y, z; };
struct DVT {
    char pad[0x40]; short d40; short i40; void (*f40)(void *);
    char pad1[0xE8 - 0x48]; short dE8; short iE8; void (*fE8)(void *, QW);
    short dF0; short iF0; void (*fF0)(void *, const void *);
    char pad2[0x260 - 0xF8]; short d260; short i260; void (*f260)(void *, int);
};
struct PD {
    char pad[0xC]; DVT *vt;
    char pad1[0x58 - 0x10]; XFV *pxfLinear; XFV *pxfAngular;
    char pad2[0x160 - 0x60]; float dtDelay;
    char pad3[0x180 - 0x164];
    QW vel;
    char pad4[0x1C4 - 0x190]; int bounced;
    char pad5[0x1CC - 0x1C8]; float tExpire;
};
extern "C" void func_001A58D0(PD *, int, int);
extern "C" const char RO_002A2D00[];
extern "C" const float g_2a7758;
extern "C" float g_2dded0;
void func_001C6BD0(PD *pdprize, QW pos, QW vel, float dtDelay, float dtLife)
{
    pdprize->vt->f40((char *)pdprize + pdprize->vt->d40);
    func_001A58D0(pdprize, 0, 0);
    pdprize->vt->fE8((char *)pdprize + pdprize->vt->dE8, pos);
    pdprize->vt->fF0((char *)pdprize + pdprize->vt->dF0, RO_002A2D00);
    XFV *xfLinear = pdprize->pxfLinear;
    int *vecLinear = &xfLinear->x;
    vecLinear[2] = 0;
    vecLinear[1] = 0;
    xfLinear->x = 0;
    XFV *xfAngular = pdprize->pxfAngular;
    int *vecAngular = &xfAngular->x;
    vecAngular[2] = 0;
    vecAngular[1] = 0;
    xfAngular->x = 0;
    pdprize->dtDelay = dtDelay;
    pdprize->bounced = 0;
    pdprize->vt->f260((char *)pdprize + pdprize->vt->d260, 3);
    pdprize->vel = vel;
    float expire = g_2a7758;
    if (dtLife != g_2a7758)
        expire = g_2dded0 + dtLife;
    pdprize->tExpire = expire;
}
