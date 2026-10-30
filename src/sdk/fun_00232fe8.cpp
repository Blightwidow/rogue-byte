extern "C" {
int func_002325E0(int, int, char *);
void func_00232FE8(int a0, int a1) {
    int buf[4];
    buf[0] = a0;
    buf[1] = a1;
    func_002325E0(0x5A, 8, (char *)buf);
}
}
