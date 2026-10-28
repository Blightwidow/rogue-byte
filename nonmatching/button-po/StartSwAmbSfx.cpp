/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct SW { char pad[0x475C]; float sTimeScale; };
struct LO { char pad[0xFC4]; char *pcomponent; };
struct COMPONENT { char pad[0x20]; float gValue; };
struct AMB;
struct VTX { char pad[0x40]; short delta; short index; int (*fn)(void *); };
struct AMBOBJ { char pad[0xC]; VTX *vt; };
struct AMB { char pad[0x0]; };
extern "C" {
extern float D_FLT_002C3EA0[3];
extern float D_FLT_002C3EB0[2];
void *PloFindSwObject_thunk(SW *, int, int, LO *);
int FIsBasicDerivedFrom(LO *, int);
AMB *NewEmitter(int);
void SetEmitterUnpositioned(AMB *, LO *);
void SetAmbRange(AMB *, float, float);
void SetAmbVolume(AMB *, float);
void SetAmbPitch(AMB *, float);
void func_001FB520(float);
void VirtualRefPtr_Assign(unsigned *, void *);
void StartSwAmbSfx(SW *psw, int sfxid, int oid, int sStart, int sFull, LO *plo, LO *ploContext, int iUnused,
                   unsigned *ppambRef, float gPitch, float gPan, float uVolume)
{
    if (sfxid == -1)
        return;
    LO *ploFound = plo;
    if (oid != -1)
        ploFound = (LO *)PloFindSwObject_thunk(psw, 4, oid, ploContext);
    plo = ploFound;
    if (plo != 0 && FIsBasicDerivedFrom(plo, 0x38) != 0) {
        COMPONENT *pcomponent = (COMPONENT *)plo->pcomponent;
        if (pcomponent != 0) {
            float gValue = pcomponent->gValue;
            float gCurve = D_FLT_002C3EA0[0] + gValue * (D_FLT_002C3EA0[1] + gValue * D_FLT_002C3EA0[2]);
            if (gCurve < D_FLT_002C3EB0[0])
                gCurve = D_FLT_002C3EB0[0];
            else if (D_FLT_002C3EB0[1] < gCurve)
                gCurve = D_FLT_002C3EB0[1];
            gPitch = gPitch + gCurve;
        }
    }
    gPitch = gPitch + psw->sTimeScale;
    AMB *pamb = NewEmitter(sfxid);
    SetEmitterUnpositioned(pamb, plo);
    SetAmbRange(pamb, (float)sStart, (float)sFull);
    SetAmbVolume(pamb, uVolume);
    SetAmbPitch(pamb, gPitch);
    func_001FB520(gPan);
    AMBOBJ *pobj = (AMBOBJ *)pamb;
    VTX *vt = pobj->vt;
    if (vt->fn((char *)pamb + vt->delta) == 2)
        VirtualRefPtr_Assign(ppambRef, pamb);
}
}
