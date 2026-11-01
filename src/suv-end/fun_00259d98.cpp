// Behaviour: returns lane 0 of the 128-bit vector at pvec as a float.
typedef int QW __attribute__((mode(TI)));
static inline float Lane0(QW v) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (v)); return f; }
extern "C" float func_00259D98(const QW *pvec) { return Lane0(*pvec); }
