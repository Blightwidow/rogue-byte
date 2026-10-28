// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct XFH;
union QF { QW q; float f[4]; };
struct VT { char pad[0x100]; short deltaXf; short indexXf; XFH *(*fnXf)(void *, MATRIX4 *); short deltaVel; short indexVel; QW (*fnVel)(void *); };
struct VTW { char pad[0x198]; short deltaRipple; short indexRipple; void (*fnRipple)(void *, void *); };
struct VTP { char pad[0x248]; short delta; short index; int (*fnInside)(void *, QW); };
struct WATER { char pad0[0xC]; VTP *vt; char pad1[0x174 - 0x10]; struct EMIT *emitter; char pad2[0x184 - 0x178]; int damage; int kind; };
struct EMIT { char pad0[0xC]; VTW *vt; };
struct LINK { struct LO *plo; float tLast; };
struct LO { char pad0[0xC]; VT *vt; };
struct JT { char pad0[0xC]; VT *vt; char pad1[0x2DC - 0x10]; int field2dc; char pad2[0xDF4 - 0x2E0]; int zapState; char pad3[0x108C - 0xDF8]; WATER *water; LINK *links; int count; char pad4[0x10A0 - 0x1098]; float up; };
struct WKR { WATER *source; int pad4; JT *target; int kind; int damage; char pad14[0xC]; QW pos; QW velocity; char pad50[0x20]; };
struct RIPPLE { int kind; char pad[0x1C]; QW pos; };
union MR { MATRIX4 m; RIPPLE r; };
struct LOOPVARS { QF posLo; MATRIX4 predicted; char gap[0x10]; MATRIX4 world; MR product; };
union SCOPE { WKR wkr; LOOPVARS loop; };
struct FRAME { QF surface; SCOPE scope; };
extern "C" {
extern float g_2dded0;
QW PosLoWorld(void *);
void *PaloAbsorbWkr(WKR *);
int FFindWaterSurface(JT *, WATER *, QW *);
void PredictXfTransform(XFH *, XFH *, float, MATRIX4 *, void *);
void __ml__FRC7MATRIX4T0(MATRIX4 *, const MATRIX4 *, const MATRIX4 *);
}
#define surface frame.surface
#define wkr frame.scope.wkr
#define posLo frame.scope.loop.posLo
#define world frame.scope.loop.world
#define predicted frame.scope.loop.predicted
#define product frame.scope.loop.product
void UpdateJtWater(JT *jt)
{
    int inside = 0;
    FRAME frame;
    if (jt->water != 0) {
        surface.q = PosLoWorld(jt);
        surface.f[2] = surface.f[2] + jt->up;
        if (jt->zapState == 3 || jt->zapState == 10)
            surface.f[2] = surface.f[2] - 10.0f;
        WATER *water = jt->water;
        inside = water->vt->fnInside((char *)water + water->vt->delta, surface.q);
    }
    if (inside == 0)
        return;
    if (jt->water->damage != 0) {
        int hurt = 0;
        QW vel = jt->vt->fnVel((char *)jt + jt->vt->deltaVel);
        int word;
        float vz;
        asm("pextuw %1, $0, %2\n\tmtc1 %1, %0\n\tnop" : "=f" (vz), "=&r" (word) : "r" (vel));
        if (vz < 0.0f || (jt->field2dc == -1 && jt->zapState != 7))
            hurt = 1;
        if (hurt != 0) {
            memset(&wkr, 0, 0x60);
            wkr.source = jt->water;
            wkr.target = jt;
            wkr.kind = jt->water->kind;
            wkr.damage = jt->water->damage;
            wkr.pos = PosLoWorld(jt);
            wkr.velocity = jt->vt->fnVel((char *)jt + jt->vt->deltaVel);
            PaloAbsorbWkr(&wkr);
        }
    }
    if (jt->water->emitter == 0)
        return;
    if (FFindWaterSurface(jt, jt->water, &surface.q) == 0)
        return;
    if (jt->count > 0) {
        float interval;
        int rippleKind;
        asm("" : "=f" (interval) : "0" (0.05f));
        asm("" : "=r" (rippleKind) : "0" (4));
        for (int index = 0; index < jt->count; index++) {
            LINK *slot = &jt->links[index];
            if (g_2dded0 - slot->tLast < interval)
                continue;
            LO *plo = slot->plo;
            posLo.q = PosLoWorld(plo);
            XFH *pxf = plo->vt->fnXf((char *)plo + plo->vt->deltaXf, &world);
            PredictXfTransform(pxf, 0, (&g_2dded0)[1], &predicted, 0);
            __ml__FRC7MATRIX4T0(&product.m, &predicted, &world);
            predicted = product.m;
            float zSurface = surface.f[2];
            float zNow = posLo.f[2];
            float zNext = predicted.mat[3][2];
            int crossed = 0;
            if (zSurface <= zNow) {
                if (zNext <= zSurface)
                    crossed = 1;
            } else {
                if (zSurface <= zNext)
                    crossed = 1;
            }
            if (crossed != 0) {
                product.r.kind = rippleKind;
                product.r.pos = posLo.q;
                ((float *)&product.r.pos)[2] = zSurface;
                EMIT *emitter = jt->water->emitter;
                emitter->vt->fnRipple((char *)emitter + emitter->vt->deltaRipple, &product.r);
                slot->tLast = g_2dded0;
            }
        }
    }
}
