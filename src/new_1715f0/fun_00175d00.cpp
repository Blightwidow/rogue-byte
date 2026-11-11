#include "vu0inline.h"
struct LM { float gMin; float gMax; };
struct LSG { QW pos; char rest[0x50]; };
struct VCALL { short delta; short index; int (*fn)(void *); };
struct ACTOR { char pad0[0xEC]; void *poxa; char padF0[0xF00 - 0xF0]; int field_0xF00; char padF04[0xF48 - 0xF04]; LM lmYaw; LM lmPitch; LM lmRoll; char padF60[0xFE8 - 0xF60]; unsigned grf; };
struct TARGET { char pad0[0xC]; char *vtable; char pad10[0x28 - 0x10]; u64 grf; char pad30[0x2DC - 0x30]; int field_0x2DC; char pad2E0[0x4C8 - 0x2E0]; int field_0x4C8; int field_0x4CC; char pad4D0[0xF54 - 0x4D0]; int field_0xF54; char padF58[0x18C8 - 0xF58]; int field_0x18C8; };
struct HITOBJ { char pad[0x14]; TARGET **pptarget; };
struct HIT { char pad[4]; HITOBJ *pobj; };
struct CHECK { char pad0[0x10]; ACTOR *pactor; char pad14[0x30 - 0x14]; TARGET *ptarget; int field_0x34; float field_0x38; int field_0x3C; };
extern "C" {
void CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void CalculateVectorPanTilt__FP6VECTORPfT1(QW, float *, float *);
void DecomposeSphere(QW, float *, float *, float *);
int FIsBasicDerivedFrom(void *, int);
QW *PmatLoWorld(void *);
QW PosLoWorld(void *);
HIT *PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(int, QW, QW, int, int, LSG *);
float RadYawSo(void *);
void bevy_camera_follow_push_out(void *, QW, QW, void *, void *, int *, int *);
extern char B_003DD490;
extern char FFilterOxaBasic;
extern float g_2dded0;
}
int FCheckLm(LM *, float);
float RadNormalize(float);
extern "C" int func_00175D00(CHECK *pcheck)
{
    ACTOR *pactor = pcheck->pactor;
    if (!(pactor->grf & 8) || pactor->field_0xF00 || pcheck->field_0x3C)
        return 0;
    if (!pcheck->ptarget)
        return 0;
    if (((pcheck->ptarget->grf >> 60) & 1) == 0)
        return 0;
    if (FIsBasicDerivedFrom(pcheck->ptarget, 0x32)) {
        VCALL *pcall = (VCALL *)(pcheck->ptarget->vtable + 0x268);
        if (pcall->fn((char *)pcheck->ptarget + pcall->delta) == 2)
            return 0;
    }
    int fForce = 0;
    if (FIsBasicDerivedFrom(pcheck->ptarget, 0x34)) {
        TARGET *ptarget = pcheck->ptarget;
        if (ptarget->field_0x4CC != -1) {
            if (ptarget->field_0x4C8 < 5)
                fForce = ptarget->field_0x4C8 >= 3;
        }
        if (ptarget->field_0x2DC != -1) {
            if ((ptarget->field_0x2DC ^ 0x11) == 0)
                fForce = 1;
        }
        if (~ptarget->field_0xF54 != 0)
            fForce = 1;
        if (FIsBasicDerivedFrom(ptarget, 0x35)) {
            switch (ptarget->field_0x18C8) {
            case 3:
            case 0x15:
            case 0x16:
                fForce = 1;
                break;
            }
        }
    }
    char frame[0x10];
    LSG lsg;
    float yaw, pitch, dist, pan;
    int count, list;
    QW posActor = PosLoWorld(pcheck->pactor);
    QW posTarget = PosLoWorld(pcheck->ptarget);
    QW delta = VectorSub(posTarget, posActor);
    float yawSo = RadYawSo(pcheck->pactor);
    DecomposeSphere(delta, &yaw, &pitch, &dist);
    if (!FCheckLm(&pcheck->pactor->lmYaw, dist))
        return 0;
    float yawDiff = RadNormalize(yaw - yawSo);
    if (!FCheckLm(&pcheck->pactor->lmPitch, yawDiff))
        return 0;
    CalculateVectorPanTilt__FP6VECTORPfT1(*PmatLoWorld(pcheck->pactor), 0, &pan);
    float pitchDiff = RadNormalize(pitch - pan);
    if (!FCheckLm(&pcheck->pactor->lmRoll, pitchDiff))
        return 0;
    if (!fForce) {
        if (pcheck->field_0x34 == 0) {
            if (g_2dded0 - pcheck->field_0x38 < 3.0f)
                return 0;
        } else if (pcheck->field_0x34 != 2) {
            return 0;
        }
    }
    CStackFrame_Construct(frame);
    bevy_camera_follow_push_out(&B_003DD490, posActor, posTarget, &FFilterOxaBasic, pcheck->pactor->poxa, &count, &list);
    HIT *phit = PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(0, posActor, posTarget, count, list, &lsg);
    if (phit && *phit->pobj->pptarget != pcheck->ptarget) {
        CStackFrame_Destructor(frame, 2);
        return 0;
    }
    CStackFrame_Destructor(frame, 2);
    return 1;
}
