extern "C" {
struct exception_246060 { int type; const char *name; double arg1; double arg2; double retval; int err; };
float __ieee754_sqrtf(float);
int func_0024A0C0(float);
int matherr(struct exception_246060 *);
int *func_002401C8(void);
extern int RO_002AC138;
extern double RO_002AB940;
float sqrtf(float x) {
    struct exception_246060 exc;
    float z = __ieee754_sqrtf(x);
    int version = RO_002AC138;
    if (version == -1 || func_0024A0C0(x)) return z;
    if (x < 0.0f) {
        exc.type = 1;
        exc.name = "sqrtf";
        exc.err = 0;
        exc.arg1 = exc.arg2 = (double)x;
        if (version == 0) exc.retval = 0.0;
        else exc.retval = RO_002AB940;
        if (RO_002AC138 == 2) *func_002401C8() = 0x21;
        else if (!matherr(&exc)) *func_002401C8() = 0x21;
        if (exc.err != 0) *func_002401C8() = exc.err;
        return (float)exc.retval;
    }
    return z;
}
}
