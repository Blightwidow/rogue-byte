struct A14 { int w[5]; };
struct A18 { int w[6]; };
struct A28 { int w[10]; };
extern "C" {
void func_00169AC8(int, A14 *, A28 *, A18 *, A14 *, A28 *, A18 *, int, int, int, int);
void func_001699E8(int arg0, A14 *arg1, A28 *arg2, A18 *arg3, int arg4, int arg5, int arg6, int arg7, int arg_sp0) {
    int i;
    for (i = 0; i < arg4; i++) {
        func_00169AC8(arg0, arg1, arg2, arg3, arg1 + i + 1, arg2 + i + 1, arg3 ? arg3 + i + 1 : 0, arg5, arg6, arg7, arg_sp0);
    }
}
}
