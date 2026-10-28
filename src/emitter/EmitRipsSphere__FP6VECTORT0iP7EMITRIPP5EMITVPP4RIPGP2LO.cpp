#include "sly2.h"
struct EMITV { QW q[7]; };
struct EMITRIP { QW q[4]; };
struct EMITG { int a; int ppripg; int lo; };
struct EMITB {
    int unk0;
    int emitpk;
    int pemitref;
    char pad0[0x24];
    QW pos;
    QW vec;
    EMITV emitv;
    EMITRIP emitrip;
};
extern "C" void InitEmitb(EMITB *);
void EmitParticles(int, EMITB *, EMITG *) __asm__("EmitParticles__FiP5EMITBP5EMITG");
extern "C" void EmitRipsSphere__FP6VECTORT0iP7EMITRIPP5EMITVPP4RIPGP2LO(QW pos, QW vec, int crip, EMITRIP *pemitrip, EMITV *pemitv, int pemitref, int ppripg, int lo)
{
    EMITB emitb;
    EMITG emitg;
    InitEmitb(&emitb);
    memset(&emitg, 0, 12);
    emitb.pos = pos;
    emitb.vec = vec;
    emitb.emitv = *pemitv;
    emitb.pemitref = pemitref;
    emitg.ppripg = ppripg;
    emitg.lo = lo;
    emitb.emitpk = 1;
    emitb.emitrip = *pemitrip;
    EmitParticles(crip, &emitb, &emitg);
}
