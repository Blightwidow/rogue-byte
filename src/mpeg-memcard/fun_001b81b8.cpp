#include "sly2.h"
struct VT { char pad[0xA8]; short delta; short index; void (*fn)(void *, int); char pad2[0x2B8 - 0xB0]; short delta2; short index2; void (*fn2)(void *, int); };
struct OBJ { char pad[0xC]; VT *vt; };
struct MURRAY { char pad[0xF1C]; OBJ *held; char pad2[0x13F0 - 0xF20]; OBJ *carrier; };
struct CARRIER { char pad[0x180]; OBJ *obj; };
extern "C" void func_00205D10();
extern "C" int FIsBasicDerivedFrom(void *, int);
void func_001B81B8(MURRAY *m, int f)
{
    func_00205D10();
    if (f) {
        CARRIER *c = (CARRIER *)m->carrier;
        if (c) {
            OBJ *o = c->obj;
            if (o) {
                m->held = o;
                o->vt->fn((char *)o + o->vt->delta, 0);
                if (FIsBasicDerivedFrom(m->held, 0x33)) {
                    OBJ *h = m->held;
                    h->vt->fn2((char *)h + h->vt->delta2, f);
                }
            }
        }
    } else {
        OBJ *o = m->held;
        if (o) {
            o->vt->fn((char *)o + o->vt->delta, 1);
            if (FIsBasicDerivedFrom(m->held, 0x33)) {
                OBJ *h = m->held;
                h->vt->fn2((char *)h + h->vt->delta2, 0);
            }
            m->held = 0;
        }
    }
}
