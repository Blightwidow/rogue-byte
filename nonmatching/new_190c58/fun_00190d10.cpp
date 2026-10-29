#include "sly2.h"
struct Pin2 { char pad0[0x30]; QW pos; char pad1[0x4]; };
struct PinP;
struct PinP { char pad0[0x30]; QW pos; MATRIX4 world; char pad1[0x20]; PinP *pparent; int gen; int unk; };
struct JTV { char pad[0x90]; short delta; short idx; void (*fn)(void *); };
struct JT { char pad0[0xC]; JTV *vt; char pad1[0x1960-0x10]; QW grip; char pad2[0x19A4-0x1970]; void *part; char pad3[0x19C4-0x19A8]; PinP *pin; char pad4[4]; PinP *pin2; };
extern "C" {
QW PosJtHangGrip(JT *);
QW PosLoWorld(void *);
QW ConvertXfVec(int, void *, QW);
void SolveIkLimb(JT *, void *);
void __as__6VECTORG9VU_VECTOR(void *, QW);
}
MATRIX4 operator*(const MATRIX4 &, const MATRIX4 &);
struct SW { char pad[0x3D58]; int gen; };
extern SW B_003DD490;
extern "C" void func_00190D10(JT *self)
{
    QW grip = PosJtHangGrip(self);
    QW sum;
    asm("lqc2 vf1, %0" : : "m" (self->grip));
    asm("qmtc2.ni %0, vf2" : : "r" (grip));
    asm("vadd.xyzw vf2, vf2, vf1");
    asm("sqc2 vf2, %0" : "=m" (sum));
    QW world = PosLoWorld(self->part);
    QW diff;
    PinP *pinA = self->pin;
    asm("qmtc2.ni %1, vf2\n\tlqc2 vf1, %2\n\tvsub.xyzw vf1, vf1, vf2\n\tqmfc2.ni %0, vf1" : "=r" (diff) : "r" (world), "m" (sum));
    PinP *pin = self->pin;
    QW off = ConvertXfVec(0, pinA->pparent, diff);
    QW newpos;
    asm("qmtc2.ni %0, vf2" : : "r" (off));
    asm("lqc2 vf1, %0" : : "m" (pin->pos));
    asm("vadd.xyzw vf2, vf1, vf2");
    asm("qmfc2.ni %0, vf2" : "=r" (newpos));
    __as__6VECTORG9VU_VECTOR(&pin->pos, newpos);
    ((float *)&pin->pos)[3] = 1.0f;
    SW *psw = &B_003DD490;
    int gen = psw->gen + 1;
    psw->gen = gen;
    self->pin->gen = gen;
    pin = self->pin;
    MATRIX4 result = *(MATRIX4 *)((char *)pin->pparent + 0x40) * *(MATRIX4 *)pin;
    pin->world = result;
    SolveIkLimb(self, *(void **)((char *)self->pin2 + 0xA8));
    self->vt->fn((char *)self + self->vt->delta);
}
