extern "C" {
int func_002325E0(int, int, char *);
void snd_GetMasterVolume(int a0) {
    int buf[4];
    buf[0] = a0;
    func_002325E0(0xA, 4, (char *)buf);
}
}
