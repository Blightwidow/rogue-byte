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

double __floatsidf(int a) { fpd in; in.cls = 3; in.sign = ((USI) a) >> 31; if (!a) { in.cls = 2; } else { in.exp = 60; if (in.sign) { if (a == -2147483647 - 1) return -2147483648.0; in.frac = -a; } else in.frac = a; while (in.frac < 0x1000000000000000ULL) { in.frac <<= 1; in.exp -= 1; } } return func_0023D338(&in); }
}
