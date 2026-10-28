#include "sly2.h"
struct GEOM { char pad[0x10]; int lo; int hi; };
struct XF { char pad[0x98]; short kind; char pad1[0xB0 - 0x9A]; QW velocity; char pad2[0xF0 - 0xC0]; int ax; int ay; int az; };
struct PHYS { char pad[0x60]; QW linear; QW angular; };
struct SO;
struct VT { char pad[0x230]; short delta; short index; void (*fn)(void *); };
struct SO { char pad[0xC]; VT *vt; char pad1[0x58 - 0x10]; XF *pxfLinear; XF *pxfAngular; char pad2[0xE0 - 0x60]; int cgeom; GEOM *ageom; PHYS *pphys; };
extern "C" {
extern float g_2dded0[];
void func_001F3900(SO *);
void IntegrateCloth(GEOM *, float);
void func_001F38A8(GEOM *);
int FXfKindDynamic(int);
void bevy_physics_driven_22de88(SO *);
void ProjectSoTransform(SO *pso)
{
    int index;
    func_001F3900(pso);
    for (index = 0; index < pso->cgeom; index++) {
        GEOM *pgeom = (GEOM *)((char *)pso->ageom + index * 0xB0);
        if (pgeom->lo != 0) IntegrateCloth(pgeom, g_2dded0[1]);
    }
    PHYS *pphys = pso->pphys;
    if (pphys != 0) {
        if (pso->pxfLinear != 0) pphys->linear = pso->pxfLinear->velocity;
        if (pso->pxfAngular != 0) pso->pphys->angular = pso->pxfAngular->velocity;
        if ((unsigned short)(pso->pxfLinear->kind - 1) < 2 || pso->pxfAngular->kind == 1 || pso->pxfAngular->kind == 2) {
            if (FXfKindDynamic(pso->pxfLinear->kind)) {
                XF *pxf = pso->pxfLinear;
                int *accel = &pxf->ax;
                accel[2] = 0;
                accel[1] = 0;
                pxf->ax = 0;
            }
            if (FXfKindDynamic(pso->pxfAngular->kind)) {
                XF *pxf = pso->pxfAngular;
                int *accel = &pxf->ax;
                accel[2] = 0;
                accel[1] = 0;
                pxf->ax = 0;
            }
            VT *vt = pso->vt;
            vt->fn((char *)pso + vt->delta);
        }
    }
    bevy_physics_driven_22de88(pso);
    for (index = 0; index < pso->cgeom; index++) {
        GEOM *pgeom = (GEOM *)((char *)pso->ageom + index * 0xB0);
        if ((*(unsigned long *)&pgeom->lo & 0x4000000000000UL) == 0) func_001F38A8(pgeom);
    }
}
}
