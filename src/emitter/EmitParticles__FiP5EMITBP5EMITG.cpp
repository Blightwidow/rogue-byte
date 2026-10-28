#include "sly2.h"
struct EMITB { int a0; int pk; char pad[0xC4 - 8]; int blipmk; };
struct EMITG;
struct EMITGEN { VECTOR *apos; VECTOR *av; float *atc; float *atd; int fconv; };
extern "C" {
void CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
}
void OriginateParticles(int, EMITB *, EMITGEN *);
void OriginateSplineSinkParticles(int, EMITB *, EMITGEN &, EMITGEN &);
void EmitRips(EMITB *, EMITG *, int, VECTOR *, VECTOR *, float *, float *);
void EmitBlips(EMITB *, EMITG *, int, VECTOR *, VECTOR *, float *, float *, VECTOR *, VECTOR *);
void EmitParticles(int count, EMITB *pemitb, EMITG *pemitg)
{
    if (count == 0) return;
    struct L { EMITGEN gen; char pad[0x20 - sizeof(EMITGEN)]; char frame[0x10]; EMITGEN target; } l;
    CStackFrame_Construct(l.frame);
    l.gen.fconv = 1;
    OriginateParticles(count, pemitb, &l.gen);
    if (pemitb->pk == 1) {
        EmitRips(pemitb, pemitg, count, l.gen.apos, l.gen.av, l.gen.atc, l.gen.atd);
    } else {
        if (pemitb->blipmk == 2) {
            OriginateSplineSinkParticles(count, pemitb, l.gen, l.target);
        } else {
            l.target.apos = 0;
            l.target.av = 0;
        }
        EmitBlips(pemitb, pemitg, count, l.gen.apos, l.gen.av, l.gen.atc, l.gen.atd, l.target.apos, l.target.av);
    }
    CStackFrame_Destructor(l.frame, 2);
}
