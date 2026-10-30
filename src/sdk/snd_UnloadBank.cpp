extern "C" {
int snd_SendIOPCommandNoWait__FiiPcPFiUl_vUl(int, int, char *, void *, int);
void snd_UnloadBank(int bank) {
    int cmd[4];
    cmd[0] = bank;
    snd_SendIOPCommandNoWait__FiiPcPFiUl_vUl(6, 4, (char *)cmd, 0, 0);
}
}
