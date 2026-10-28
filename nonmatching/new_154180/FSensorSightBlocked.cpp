#include "sly2.h"
struct SENSOR { char pad[0xF8]; int flags; };
extern "C" char B_003DD490;
extern "C" QW D_002BDBF0[1];
extern "C" void CStackFrame_Construct(void *);
extern "C" void CStackFrame_Destructor(void *, int);
extern "C" QW func_00153E60(SENSOR *);
extern "C" void *PvAllocStackImpl__Fi(void *);
extern "C" QW ConvertAloPos(void *, int, QW);
extern "C" int FFilterSensorSight(void *, void *);
extern "C" int FFilterSensorBasic(void *, void *);
extern "C" void bevy_camera_follow_push_out(void *, QW, QW, void *, void *, int *, int *);
extern "C" void *PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(int, QW, QW, int, int, int);
extern "C" int FSensorSightBlocked(SENSOR *sensor, void *plo)
{
    char frame[0x10];
    int req[2];
    int apso;
    int cgeom;
    QW spillMin;
    QW spillMax;
    CStackFrame_Construct(frame);
    QW anchor = func_00153E60(sensor);
    req[0] = 0x10;
    req[1] = 0x10;
    QW *probes = (QW *)PvAllocStackImpl__Fi(req);
    asm volatile("qmtc2.ni %0, vf3" : : "r" (anchor));
    asm volatile("qmtc2.ni %0, vf2" : : "r" (anchor));
    for (int i = 0; i < 1; i++) {
        asm volatile("sqc2 vf2, %0" : "=m" (spillMin));
        asm volatile("sqc2 vf3, %0" : "=m" (spillMax));
        QW pos = ConvertAloPos(plo, 0, D_002BDBF0[i]);
        asm volatile("qmtc2.ni %1, vf1\n\tsqc2 vf1, %0" : "=m" (probes[i]) : "r" (pos));
        asm volatile("lqc2 vf3, %0\n\tlqc2 vf2, %1\n\tvmax.xyz vf3, vf3, vf1\n\tvmini.xyz vf2, vf2, vf1" : : "m" (spillMax), "m" (spillMin));
    }
    void *filter = (void *)FFilterSensorSight;
    if (sensor->flags & 4) filter = (void *)FFilterSensorBasic;
    QW boundMin;
    QW boundMax;
    asm volatile("qmfc2.ni %0, vf2" : "=r" (boundMin));
    asm volatile("qmfc2.ni %0, vf3" : "=r" (boundMax));
    bevy_camera_follow_push_out(&B_003DD490, boundMin, boundMax, filter, sensor, &cgeom, &apso);
    int i = 0;
    while (i < 1) {
        if (!PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(0, anchor, probes[i], cgeom, apso, 0)) break;
        i++;
    }
    CStackFrame_Destructor(frame, 2);
    return i >= 1;
}
