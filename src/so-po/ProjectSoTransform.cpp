#include "sly2.h"
struct GEOM { char pad[0x10]; int lo; int hi; };
#include "xf.h"
struct PHYS { char pad[0x60]; QW linear; QW angular; };
#include "so.h"
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
        if (pso->pxfLinear != 0) pphys->linear = pso->pxfLinear->vel;
        if (pso->pxfAngular != 0) pso->pphys->angular = pso->pxfAngular->vel;
        if ((unsigned short)(pso->pxfLinear->kind - 1) < 2 || pso->pxfAngular->kind == 1 || pso->pxfAngular->kind == 2) {
            if (FXfKindDynamic(pso->pxfLinear->kind)) {
                XF *pxf = pso->pxfLinear;
                int *accel = pxf->accel;
                accel[2] = 0;
                accel[1] = 0;
                pxf->accel[0] = 0;
            }
            if (FXfKindDynamic(pso->pxfAngular->kind)) {
                XF *pxf = pso->pxfAngular;
                int *accel = pxf->accel;
                accel[2] = 0;
                accel[1] = 0;
                pxf->accel[0] = 0;
            }
            pso->Slot70();
        }
    }
    bevy_physics_driven_22de88(pso);
    for (index = 0; index < pso->cgeom; index++) {
        GEOM *pgeom = (GEOM *)((char *)pso->ageom + index * 0xB0);
        if ((*(unsigned long *)&pgeom->lo & 0x4000000000000UL) == 0) func_001F38A8(pgeom);
    }
}
}
