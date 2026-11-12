extern "C" {
int snd_SendIOPCommandNoWait__FiiPcPFiUl_vUl(int, int, char *, int, int);
void snd_SendIOPCommand68(int a0, int a1, int a2, int a3, int a4, int a5) {
    int buf[4];
    buf[0] = a0;
    buf[1] = a1;
    buf[2] = a2;
    buf[3] = a3;
    snd_SendIOPCommandNoWait__FiiPcPFiUl_vUl(0x68, a2 + 0xC, (char *)buf, a4, a5);
}
}
