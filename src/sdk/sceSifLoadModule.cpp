extern "C" {
int func_00238F38(int, int, int, int *);
int sceSifLoadModule(int first, int second, int third) {
    int result[4];
    return func_00238F38(first, second, third, result);
}
}
