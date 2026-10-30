extern "C" {
int snd_SendIOPCommandNoWait__FiiPcPFiUl_vUl(int, int, char *, void *, int);
void snd_SetMasterVolume(int a0, int a1) {
    int buf[4];
    buf[0] = a0;
    buf[1] = a1;
    snd_SendIOPCommandNoWait__FiiPcPFiUl_vUl(9, 8, (char *)buf, 0, 0);
}
}
