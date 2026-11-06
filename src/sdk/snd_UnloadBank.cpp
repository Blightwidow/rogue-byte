extern "C" {
int snd_SendIOPCommandNoWait__FiiPcPFiUl_vUl(int, int, char *, void (*)(int, unsigned long), unsigned long);
int snd_UnloadBank(int bank) {
    return snd_SendIOPCommandNoWait__FiiPcPFiUl_vUl(6, 4, (char *)&bank, 0, 0);
}
}
