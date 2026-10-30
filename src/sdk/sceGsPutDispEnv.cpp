extern "C" {
struct DispEnv_240600 {
    unsigned long pmode;
    unsigned long smode2;
    unsigned long dispfb;
    unsigned long display;
    unsigned long bgcolor;
};
struct Mode_240600 {
    char pad0[6];
    short interlace;
};
Mode_240600 *func_002405F0();
void sceGsPutDispEnv(DispEnv_240600 *disp) {
    if (func_002405F0()->interlace == 1) {
        *(volatile unsigned long *)0x12000000 = disp->pmode;
        *(volatile unsigned long *)0x12000070 = disp->dispfb;
        *(volatile unsigned long *)0x12000080 = disp->display;
        *(volatile unsigned long *)0x120000C0 = disp->bgcolor;
    } else {
        *(volatile unsigned long *)0x12000000 = disp->pmode;
        *(volatile unsigned long *)0x12000020 = disp->smode2;
        *(volatile unsigned long *)0x12000090 = disp->dispfb;
        *(volatile unsigned long *)0x120000A0 = disp->display;
        *(volatile unsigned long *)0x120000E0 = disp->bgcolor;
    }
}
}
