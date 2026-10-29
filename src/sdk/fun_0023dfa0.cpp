// SPDX-License-Identifier: GPL-3.0-or-later
extern "C" {
typedef unsigned long long UDI;
typedef unsigned int USI;
typedef struct { int cls; USI sign; int exp; UDI frac; } fpd;
typedef struct { int cls; USI sign; int exp; USI frac; } fpf;
extern void func_0023D468(double*, fpd*);
extern fpd* func_0023D508(fpd*, fpd*, fpd*);
extern double func_0023D338(fpd*);
extern int func_0023DC18(fpd*, fpd*);
extern double func_0023DF70(int, USI, int, UDI);
extern float func_0023DFF8(fpf*);
extern void func_0023E108(float*, fpf*);
extern float func_0023E260(int, USI, int, USI);

float func_0023DFA0(double a) { fpd in; USI f; func_0023D468(&a, &in); f = (USI) (in.frac >> 30); if (in.frac & 0x3FFFFFFF) f |= 1; return func_0023E260(in.cls, in.sign, in.exp, f); }
}
