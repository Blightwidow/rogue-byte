extern "C" {
int snd_SendIOPCommandNoWait__FiiPcPFiUl_vUl(int, int, char *, int, int);
void snd_SendIOPCommand21(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) {
    int buf[6];
    buf[0] = a0;
    buf[1] = a1;
    buf[2] = a2;
    buf[3] = a3;
    buf[4] = a4;
    buf[5] = a5;
    snd_SendIOPCommandNoWait__FiiPcPFiUl_vUl(0x21, 0x18, (char *)buf, a6, a7);
}
}
