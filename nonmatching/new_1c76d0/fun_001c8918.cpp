#include "sly2.h"
struct XF { char pad0[0xA0]; void *parent; char pad1[4]; float tArrive; char pad2[4]; QW vel; QW pos; QW tan; };
struct KP {
    char pad0[0x188];
    int state; float tState; void *jt; int icell;
    char pad1[8];
    void *handle; char pad2[4];
    void *cells[8]; char pad3[4];
    void *asegs[8]; char pad4[0x204 - 0x1EC];
    XF *xf; void *camera;
};
extern "C" {
void ReleaseAsegaHandle(void *);
void SetJtAttach5(void *, void *);
QW bevy_camera_follow_track_heading_weight(void *, void *, QW);
QW ConvertXfVec(void *, void *, QW);
QW ConvertXfPos(void *, void *, QW);
QW PosLoWorld(void *);
void SetXfKind(KP *, XF *, int);
void ApplyAsegToHandle(void *, void *, int, void *, float, float);
extern float g_2dded0;
extern QW D_002C1080;
extern QW D_002C1090;
}

void func_001C8918(KP *kp, int state)
{
    if (state == kp->state) return;
    ReleaseAsegaHandle(&kp->handle);
    kp->state = state;
    kp->tState = g_2dded0;
    switch (state) {
    case -1:
        kp->icell = state;
        SetJtAttach5(kp->jt, 0);
        break;
    case 0:
        SetJtAttach5(kp->jt, kp->cells[kp->icell]);
        break;
    case 1: {
        SetJtAttach5(kp->jt, kp->camera);
        kp->xf->tArrive = g_2dded0 + 0.25f;
        XF *xf = kp->xf;
        QW heading = bevy_camera_follow_track_heading_weight(kp->jt, 0, D_002C1080);
        xf->vel = ConvertXfVec(0, xf->parent, heading);
        xf = kp->xf;
        QW cellPos = PosLoWorld(kp->cells[kp->icell]);
        xf->pos = ConvertXfPos(0, xf->parent, cellPos);
        xf = kp->xf;
        QW tangent = bevy_camera_follow_track_heading_weight(kp->jt, 0, D_002C1090);
        xf->tan = ConvertXfVec(0, xf->parent, tangent);
        SetXfKind(kp, kp->xf, 0x11);
        break;
    }
    case 2:
        SetJtAttach5(kp->jt, kp->cells[kp->icell]);
        ApplyAsegToHandle(kp->asegs[kp->icell], kp, 0, &kp->handle, 0.0f, 1.0f);
        break;
    }
}
