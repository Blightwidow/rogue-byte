/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct SW { char pad[0x475C]; float sTimeScale; };
struct LO { char pad[0xFC4]; char *pcomponent; };
struct COMPONENT { char pad[0x20]; float gValue; };
struct AMB;
struct VTX { char pad[0x40]; short delta; short index; int (*fn)(void *); };
struct AMBOBJ { char pad[0xC]; VTX *vt; };
struct LM { float gMin; float gMax; };
static inline float GLimitLm(LM *plm, float g)
{
    float gMin = plm->gMin;
    float gMax = plm->gMax;
    if (g < gMin)
        g = gMin;
    else if (gMax < g)
        g = gMax;
    return g;
}
extern "C" {
extern float D_FLT_002C3EA0[3];
extern LM D_FLT_002C3EB0;
void *PloFindSwObject_thunk(SW *, int, int, LO *);
int FIsBasicDerivedFrom(LO *, int);
AMB *NewEmitter(int);
void SetEmitterUnpositioned(AMB *, LO *);
void SetAmbRange(AMB *, float, float);
void SetAmbVolume(AMB *, float);
void SetAmbPitch(AMB *, float);
void func_001FB520(AMB *, float);
void VirtualRefPtr_Assign(unsigned *, void *);
/*
 * Retail copies ploContext ($t2) into $a3 last, after the float arguments, and
 * reloads $a0 from $s0 before PloFindSwObject_thunk: the float parameters are
 * declared before ploContext (EE ABI gives ints and floats separate registers,
 * so the order only changes the incoming copies), and the object lookup is an
 * if/else whose else label keeps reload_cse from dropping the $a0 copy. The
 * pitch curve is clamped by an inline GLimitLm that loads both limits before
 * comparing (retail loads the max into the bc1f delay slot); 0x1FB520 (empty
 * stub) takes the emitter in $a0 and the pan in $f12.
 */
void StartSwAmbSfx(SW *psw, int sfxid, int oid, int sStart, int sFull, LO *plo, float gPitch, float gPan, float uVolume, LO *ploContext, int iUnused,
                   unsigned *ppambRef)
{
    if (sfxid == -1)
        return;
    LO *ploFound;
    if (oid == -1)
        ploFound = plo;
    else
        ploFound = (LO *)PloFindSwObject_thunk(psw, 4, oid, ploContext);
    if (ploFound != 0 && FIsBasicDerivedFrom(ploFound, 0x38) != 0) {
        COMPONENT *pcomponent = (COMPONENT *)ploFound->pcomponent;
        if (pcomponent != 0) {
            float gValue = pcomponent->gValue;
            float gCurve = D_FLT_002C3EA0[0] + gValue * (D_FLT_002C3EA0[1] + gValue * D_FLT_002C3EA0[2]);
            gPitch = gPitch + GLimitLm(&D_FLT_002C3EB0, gCurve);
        }
    }
    gPitch = gPitch + psw->sTimeScale;
    AMB *pamb = NewEmitter(sfxid);
    SetEmitterUnpositioned(pamb, ploFound);
    SetAmbRange(pamb, (float)sStart, (float)sFull);
    SetAmbVolume(pamb, uVolume);
    SetAmbPitch(pamb, gPitch);
    func_001FB520(pamb, gPan);
    AMBOBJ *pobj = (AMBOBJ *)pamb;
    VTX *vt = pobj->vt;
    if (vt->fn((char *)pamb + vt->delta) == 2)
        VirtualRefPtr_Assign(ppambRef, pamb);
}
}
