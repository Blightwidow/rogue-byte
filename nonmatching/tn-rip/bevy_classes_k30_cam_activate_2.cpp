#include "sly2.h"
struct CPZ { char pad0[0xA4]; float pan, tilt, a, b, c, d, e; char padc0[0]; };
struct CP { char pad[0xA4]; float f_a4, f_a8, f_ac, f_b0, f_b4, f_b8, f_bc; int e_c0, e_c4; };
struct CM { char pad[0x24]; float fov; char pad2[0x38]; char mat[0x444]; int cnt; };
extern CM B_002DDF40;
extern float g_2dded0;
extern float g_3e1be0;
extern "C" void ActivateCplcy(CP*);
extern "C" int NewEmitter(int);
extern "C" void SetEmitterUnpositioned(int, int);
extern "C" void VirtualRefPtr_Assign(int*, int);
extern "C" void PauseAmb(int);
extern "C" void SetCmNearClip(void*, float);
extern "C" void bevy_classes_k30_cam_150ef0(CP*);
void DecomposeRotateMatrixPanTilt(MATRIX3*, float*, float*);
void bevy_classes_k30_cam_activate_2(CP* p)
{
    ActivateCplcy(p);
    int e = NewEmitter(0x26);
    SetEmitterUnpositioned(e, 0);
    VirtualRefPtr_Assign(&p->e_c0, e);
    e = NewEmitter(0x25);
    SetEmitterUnpositioned(e, 0);
    VirtualRefPtr_Assign(&p->e_c4, e);
    PauseAmb(p->e_c0);
    CM* c = &B_002DDF40;
    DecomposeRotateMatrixPanTilt((MATRIX3*)c->mat, &p->f_a4, &p->f_a8);
    p->f_a8 = 0;
    p->f_ac = 0;
    p->f_b0 = 0;
    p->f_b8 = c->fov / p->f_b4;
    p->f_bc = c->fov;
    SetCmNearClip(c, 49.0f);
    bevy_classes_k30_cam_150ef0(p);
    c->cnt += 1;
    g_3e1be0 = g_2dded0;
}
