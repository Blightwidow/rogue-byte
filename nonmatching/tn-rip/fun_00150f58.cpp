#include "sly2.h"
static inline float Lane(QW q) { float f; asm volatile("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
static inline float Tol() { float f; asm volatile("lui $1, 0x38D1\n\tori $1, $1, 0xB717\n\tmtc1 $1, %0" : "=f" (f)); return f; }
extern "C" int FFloatsNear__Ffff(float, float, float);
extern "C" QW bevy_classes_k30_cam_150780(void *);
int func_00150F58(char *self)
{
    register QW zeroReg asm("$0");
    QW b;
    QW a = *(QW *)(self + 0x20);
    b = bevy_classes_k30_cam_150780(self);
    int result;
    asm("" : "=r"(result) : "0"(0));
    float tol = Tol();
    if (FFloatsNear__Ffff(Lane(a), Lane(b), tol)) {
        QW a1 = __builtin_prot3w(a);
        tol = Tol();
        float fa = Lane(a1);
        QW b1 = __builtin_prot3w(b);
        float fb = Lane(b1);
        if (FFloatsNear__Ffff(fa, fb, tol)) {
            QW a2 = __builtin_pextuw(zeroReg, a);
            tol = Tol();
            fa = Lane(a2);
            QW b2 = __builtin_pextuw(zeroReg, b);
            fb = Lane(b2);
            result = FFloatsNear__Ffff(fa, fb, tol) != 0;
        }
    }
    return result;
}
