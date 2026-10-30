extern "C" {
void func_00234F48(char *, char *);
extern char *D_002C4640;
extern int D_002C4644;
void func_00231F38(char *arg0, int arg1) {
    D_002C4644 = arg1;
    D_002C4640 = arg0;
    ((int *)arg0)[arg1 + 1] = 0;
    *(int *)arg0 = 0;
    func_00234F48(arg0, arg0 + 3);
    arg0 += arg1 * 4 + 4;
    func_00234F48(arg0, arg0 + 3);
}
}
