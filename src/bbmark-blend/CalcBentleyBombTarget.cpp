#include "sly2.h"
struct BENTLEY { char pad[0xEC]; void *poxa; char pad2[0x16F0 - 0xF0]; QW posTarget; };
struct LSG { QW pos; char rest[0x50]; };
extern "C" char B_002DDF40;
extern "C" char B_003DD490;
extern "C" QW g_2bc970;
extern "C" QW g_2bc980;
extern "C" int FFilterOxaBasic(void *, void *);
extern "C" QW ConvertCmScreenToWorld(void *, QW);
extern "C" void *CStackFrame_Construct(void *);
extern "C" void CStackFrame_Destructor(void *, int);
extern "C" void bevy_camera_follow_push_out(void *, QW, QW, void *, void *, int *, int *);
extern "C" void *PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(int, QW, QW, int, int, LSG *);

extern "C" void CalcBentleyBombTarget(BENTLEY *pbentley)
{
    QW posNear = ConvertCmScreenToWorld(&B_002DDF40, g_2bc970);
    QW posFar = ConvertCmScreenToWorld(&B_002DDF40, g_2bc980);
    char frame[0x10];
    LSG lsg;
    int cpso;
    int apso;
    CStackFrame_Construct(frame);
    bevy_camera_follow_push_out(&B_003DD490, posNear, posFar, (void *)FFilterOxaBasic, pbentley->poxa, &cpso, &apso);
    if (PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(1, posNear, posFar, cpso, apso, &lsg))
        pbentley->posTarget = lsg.pos;
    else
        pbentley->posTarget = posFar;
    CStackFrame_Destructor(frame, 2);
}
