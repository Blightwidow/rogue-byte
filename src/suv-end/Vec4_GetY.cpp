// Behaviour: returns lane 1 (Y) of the 128-bit vector at pvec as a float.
typedef int QW __attribute__((mode(TI)));
// lane 1: prot3w rotates lanes so Y lands in lane 0, then mtc1
static inline float Lane1(QW v) { float f; QW t; asm("prot3w %1, %2\n\tmtc1 %1, %0" : "=f" (f), "=&r" (t) : "r" (v)); return f; }
extern "C" float Vec4_GetY(const QW *pvec) { return Lane1(*pvec); }
