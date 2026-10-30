extern "C" {
struct exception_2458F0 { int type; const char *name; double arg1; double arg2; double retval; int err; };
float __ieee754_atan2f(float, float);
int func_0024A0C0(float);
int matherr(struct exception_2458F0 *);
int *func_002401C8(void);
extern int RO_002AC138;
float atan2f(float y, float x) {
    struct exception_2458F0 exc;
    float z = __ieee754_atan2f(y, x);
    int version = RO_002AC138;
    if (version == -1 || func_0024A0C0(x) || func_0024A0C0(y)) return z;
    if (x == 0.0f && y == 0.0f) {
        exc.arg1 = (double)y;
        exc.arg2 = (double)x;
        exc.retval = 0.0;
        exc.type = 1;
        exc.name = "atan2f";
        exc.err = 0;
        if (version == 2) *func_002401C8() = 0x21;
        else if (!matherr(&exc)) *func_002401C8() = 0x21;
        if (exc.err != 0) *func_002401C8() = exc.err;
        return (float)exc.retval;
    }
    return z;
}
}
