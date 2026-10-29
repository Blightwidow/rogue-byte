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
typedef struct { USI fraction : 23; USI exp : 8; USI sign : 1; } fbits;
void func_0023E108(float* arg, fpf* dst) { fbits* s = (fbits*) arg; USI frac = s->fraction; int e = s->exp; USI sign = s->sign; dst->sign = sign; if (e == 0) { dst->cls = 2; } else if (e == 0xFF) { if (frac == 0) { dst->cls = 4; } else { if (frac & 0x100000) dst->cls = 1; else dst->cls = 0; dst->frac = frac; } } else { dst->exp = e - 127; dst->cls = 3; dst->frac = (frac << 7) | 0x40000000; } }
}
