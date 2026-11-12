extern "C" {
int snd_SendIOPCommandNoWait__FiiPcPFiUl_vUl(int, int, char *, void *, int);
void func_00233088(int a0, int a1, int a2, int a3, int a4, int a5, int a6) {
    int buf[7];
    buf[0] = a0;
    buf[1] = a1;
    buf[2] = a2;
    buf[3] = a3;
    buf[4] = a4;
    buf[5] = a5;
    buf[6] = a6;
    snd_SendIOPCommandNoWait__FiiPcPFiUl_vUl(0x4C, 0x1C, (char *)buf, 0, 0);
}
}
