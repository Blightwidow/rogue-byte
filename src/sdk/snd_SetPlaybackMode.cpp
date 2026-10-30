extern "C" {
int snd_SendIOPCommandNoWait__FiiPcPFiUl_vUl(int, int, char *, void *, int);
void snd_SetPlaybackMode(int a0) {
    int buf[4];
    buf[0] = a0;
    snd_SendIOPCommandNoWait__FiiPcPFiUl_vUl(0xB, 4, (char *)buf, 0, 0);
}
}
