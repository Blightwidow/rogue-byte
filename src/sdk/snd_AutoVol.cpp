extern "C" {
int snd_SendIOPCommandNoWait__FiiPcPFiUl_vUl(int, int, char *, void *, int);
void snd_AutoVol(int a0, int a1, int a2, int a3) {
    int buf[4];
    buf[0] = a0;
    buf[1] = a1;
    buf[2] = a2;
    buf[3] = a3;
    snd_SendIOPCommandNoWait__FiiPcPFiUl_vUl(0x22, 0x10, (char *)buf, 0, 0);
}
}
