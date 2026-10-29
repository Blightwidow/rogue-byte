// SPDX-License-Identifier: GPL-3.0-or-later
extern "C" {
typedef struct { int a, b, c, d, e, f, g, h; } fp;
extern fp* func_0023D508(fp*, fp*, fp*);
extern void func_0023D468(double*, fp*);
extern double func_0023D338(fp*);
double __adddf3(double a, double b)
{
    fp x, y, z;
    func_0023D468(&a, &x);
    func_0023D468(&b, &y);
    return func_0023D338(func_0023D508(&x, &y, &z));
}
}
