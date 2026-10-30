extern "C" {
struct exception_2456F0 { int type; const char *name; double arg1; double arg2; double retval; int err; };
float __ieee754_acosf(float);
float func_00244EF8(float); // fabsf, called out of line (the compiler inlines the fabsf name)
int func_0024A0C0(float);
int matherr(struct exception_2456F0 *);
int *func_002401C8(void);
extern int RO_002AC138;
float acosf(float x) {
    struct exception_2456F0 exc;
    float z = __ieee754_acosf(x);
    int version = RO_002AC138;
    if (version == -1 || func_0024A0C0(x)) return z;
    if (func_00244EF8(x) > 1.0f) {
        exc.type = 1;
        exc.name = "acosf";
        exc.err = 0;
        exc.arg1 = exc.arg2 = (double)x;
        exc.retval = 0.0;
        if (version == 2) *func_002401C8() = 0x21;
        else if (!matherr(&exc)) *func_002401C8() = 0x21;
        if (exc.err != 0) *func_002401C8() = exc.err;
        return (float)exc.retval;
    }
    return z;
}
}
