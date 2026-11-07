#include "sly2.h"

typedef struct S233048 {
    int a0;
    int a1;
    int a2;
    int a3;
    int t0;
    int t1;
    int t2;
} S233048;

extern "C" void func_002325E0(unsigned, unsigned, S233048 *);

extern "C" void func_00233048(int a0, int a1, int a2, int a3, int t0, int t1, int t2)
{
    S233048 s;
    s.a0 = a0;
    s.a1 = a1;
    s.a2 = a2;
    s.a3 = a3;
    s.t0 = t0;
    s.t1 = t1;
    s.t2 = t2;
    func_002325E0(0x4C, 0x1C, &s);
}
