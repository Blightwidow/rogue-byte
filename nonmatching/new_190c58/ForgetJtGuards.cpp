#include "vu0inline.h"
#include "ps2inline.h"

struct CSF {};
extern "C" {
void *PentryFindSensorLo(int, void *);
QW PosLoWorld(void *);
void SetSensorEntryState(void *, void *, int);
void CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void bevy_camera_follow_push_out(void *, QW, QW, void *, void *, int *, int *);
int PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(int, QW, QW, int, int, int);
extern char B_003DD490[];
extern char FFilterSensorSight[];
extern float g_2bf638;
}

struct GUARD_192A28 { char pad0[0xF64]; char *psensor; char padF68[0xFE0 - 0xF68]; GUARD_192A28 *pnext; };
extern "C" GUARD_192A28 *B_003E1444;

extern "C" void ForgetJtGuards(void **arg0)
{
    CSF first;
    CSF frame;
    int count;
    int list;
    QW posGuard;
    QW posTarget;
    for (GUARD_192A28 *pguard = B_003E1444; pguard != 0; pguard = pguard->pnext) {
        void *pentry = PentryFindSensorLo((int)pguard->psensor, *arg0);
        if (pentry != 0 && *(int *)((char *)pentry + 4) != 0 && !(*(int *)(pguard->psensor + 0xF8) & 1)) {
            posGuard = PosLoWorld(pguard);
            posTarget = PosLoWorld(*arg0);
            float distance = LaneX(SqrtX(SquaredLength(VectorSub(posGuard, posTarget))));
            int fOutOfRange = g_2bf638 < distance;
            if (fOutOfRange) {
                SetSensorEntryState(pguard->psensor, pentry, 0);
            } else {
                CStackFrame_Construct(&frame);
                bevy_camera_follow_push_out(B_003DD490, posGuard, posTarget, FFilterSensorSight, pguard, &count, &list);
                if (PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(0, posGuard, posTarget, count, list, 0) != 0) {
                    SetSensorEntryState(pguard->psensor, pentry, 0);
                    CStackFrame_Destructor(&frame, 2);
                } else {
                    CStackFrame_Destructor(&frame, 2);
                }
            }
        }
    }
}
