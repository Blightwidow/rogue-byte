#include "sly2.h"
struct M3 { QW row[3]; };
struct VT { char pad[0xF0]; short delta; short index; void (*fn)(void *, M3 *); };
struct OBJ { char pad[0xC]; VT *vptr; };
extern "C" void LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(M3 *, QW);
static inline QW Word(float f) { QW r; asm("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
void func_001A63B0(OBJ *pobj, QW vec)
{
    struct L { M3 copy; QW junk; M3 mat; } l;
    float x, y, z;
    int yb, zb;
    asm("mtc1 %1, %0" : "=f" (x) : "r" (vec));
    asm("prot3w %0, %1" : "=r" (yb) : "r" (vec));
    y = *(float *)&yb;
    asm("pextuw %0, $0, %1" : "=r" (zb) : "r" (vec));
    z = *(float *)&zb;
    float k = 0.017453294f;
    x = x * k;
    z = z * k;
    y = y * k;
    QW low = __builtin_pextlw(Word(y), Word(x));
    QW euler = __builtin_pcpyld(Word(z), low);
    l.junk = euler;
    LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(&l.mat, euler);
    l.copy = l.mat;
    VT *vtable = pobj->vptr;
    vtable->fn((char *)pobj + vtable->delta, &l.copy);
}
