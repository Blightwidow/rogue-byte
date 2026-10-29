// SPDX-License-Identifier: GPL-3.0-or-later
extern "C" {
typedef unsigned long long UDI;
typedef unsigned int USI;
typedef struct { USI cls; USI sign; int exp; UDI frac; } fpd;
typedef struct { USI cls; USI sign; int exp; USI frac; } fpf;
extern void func_0023D468(double*, fpd*);
extern fpd* func_0023D508(fpd*, fpd*, fpd*);
extern double func_0023D338(fpd*);
extern int func_0023DC18(fpd*, fpd*);
extern double func_0023DF70(int, USI, int, UDI);
extern float func_0023DFF8(fpf*);
extern void func_0023E108(float*, fpf*);
extern float func_0023E260(int, USI, int, USI);

static inline int iszero(fpf* p) { return p->cls == 2; }
static inline int isnan(fpf* p) { return p->cls < 2; }
static inline int isinf(fpf* p) { return p->cls == 4; }
USI func_0023E1C8(float a) { fpf in; func_0023E108(&a, &in); if (iszero(&in)) return 0; if (isnan(&in)) return 0; if (in.sign) return 0; if (isinf(&in)) return 0xFFFFFFFF; if (in.exp < 0) return 0; if (in.exp >= 32) return 0xFFFFFFFF; if (in.exp >= 31) return in.frac << (in.exp - 30); return in.frac >> (30 - in.exp); }
}
