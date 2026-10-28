#include "sly2.h"
struct JT { char pad[0x4D4]; void *rail; int pad4d8, pad4dc; float sAttach; int backwards; };
struct XMG { char pad[4]; int hasRail; float radius; char pad2[4]; QW center; QW axis; };
extern "C" {
void SetActadjOffset(void *, QW);
float SMinCrv(void *);
float SMaxCrv(void *);
float GModPositive__Fff(float, float);
void GetPathPosFromS(void *, float, QW *, void *);
QW ConvertAloPos(int, void *, QW);
int ClsgClipEdgeToSphere__FP6VECTORfT0T0iP3LSG(QW, float, QW, QW, int, void *);
extern QW g_2a2dd0;
}
struct Locals { QW pos; QW clip[2]; char pad[0x40]; };

void MatchJtXmgRail__FP2JTP3XMGP6ACTADJ(JT *jt, XMG *xmg, void *actadj)
{
    if (xmg->hasRail == 0) {
        SetActadjOffset(actadj, g_2a2dd0);
        return;
    }
    Locals l;
    void *rail = jt->rail;
    float offset = *(float *)((char *)xmg + 0x10);
    if (jt->backwards != 0)
        offset = -offset;
    float sMin = SMinCrv(rail);
    float sMax = SMaxCrv(rail);
    float s;
    if (*(int *)((char *)rail + 0xE4) != 0) {
        s = GModPositive__Fff(jt->sAttach + offset, sMax);
    } else {
        s = jt->sAttach + offset;
        if (s < sMin)
            s = sMin;
        else if (sMax < s)
            s = sMax;
    }
    GetPathPosFromS(rail, s, &l.pos, 0);
    l.pos = ConvertAloPos(0, jt, l.pos);
    int hit = ClsgClipEdgeToSphere__FP6VECTORfT0T0iP3LSG(xmg->axis, xmg->radius, xmg->center, l.pos, 1, &l.clip[0]);
    if (hit > 0) {
        register void *arg0 asm("$4") = actadj;
        asm volatile("" : : "r" (arg0));
        register QW v3 asm("vf3");
        asm("lqc2 vf2, %1\n\tlqc2 vf1, %2\n\tvsub.xyzw vf3, vf1, vf2" : "=j" (v3) : "m" (xmg->center), "m" (l.clip[1]));
        SetActadjOffset(arg0, v3);
    }
}
