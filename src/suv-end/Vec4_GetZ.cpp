#include "sly2.h"
extern "C" {
/* pextuw moves the z word (word 2) of the vector into the low word */
float Vec4_GetZ(QW *pvec) { QW v = *pvec; float z; asm("pextuw %0, $zero, %1" : "=r"(z) : "r"(v)); return z; }
}
