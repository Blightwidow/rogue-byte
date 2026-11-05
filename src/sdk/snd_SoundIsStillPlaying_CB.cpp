extern "C" {
int snd_SendIOPCommandNoWait__FiiPcPFiUl_vUl(int, int, char *, int, int);
void snd_SoundIsStillPlaying_CB(int arg0, int arg1, int arg2) {
    int buf[4];
    buf[0] = arg0;
    snd_SendIOPCommandNoWait__FiiPcPFiUl_vUl(0x19, 4, (char *)buf, arg1, arg2);
}
}
