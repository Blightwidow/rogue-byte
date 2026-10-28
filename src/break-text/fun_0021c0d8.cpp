#include "sly2.h"
struct VT { char pad[0x48]; short delta; short index; void (*fn)(void *); };
struct SO { char pad0[0xC]; VT *vptr; char pad10[0x11C]; float u; float du; char pad134[0x24]; int cIdle; char pad15c[8]; int cRec; };
extern "C" void UpdateLo(SO *);
extern float g_2dded4;

void func_0021C0D8(SO *s)
{
    UpdateLo(s);
    register float zero asm("$f3");
    float du = s->du;
    asm("mtc1 $0, %0\n\tnop" : "=f" (zero));
    if (du != zero) {
        float u = s->u + g_2dded4 * du;
        s->u = u;
        if (u <= zero) {
            s->u = zero;
            s->du = zero;
        } else {
            float one;
            asm("lui $at, 0x3f80\n\tmtc1 $at, %0\n\tnop" : "=f" (one) : : "at");
            if (u >= one) {
                s->u = one;
                s->du = zero;
            }
        }
    }
    float zero2;
    float uu = s->u;
    asm("mtc1 $0, %0\n\tnop" : "=f" (zero2));
    if (uu <= zero2 && s->du <= zero2 && s->cRec >= s->cIdle) {
        VT *v = s->vptr;
        v->fn((char *)s + v->delta);
    }
}
