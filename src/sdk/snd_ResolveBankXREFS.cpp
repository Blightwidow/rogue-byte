extern "C" {
void snd_SendIOPCommandNoWait__FiiPcPFiUl_vUl(int, int, char *, void (*)(int, unsigned long), unsigned long);
void snd_ResolveBankXREFS(void) {
    snd_SendIOPCommandNoWait__FiiPcPFiUl_vUl(8, 0, 0, 0, 0);
}
}
