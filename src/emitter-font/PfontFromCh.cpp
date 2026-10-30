extern "C" {
extern unsigned char D_002BE328[];
extern int B_002DE9F0[];
int PfontFromCh(int ch) {
    int code = ch & 0xFF;
    int index = 0;
    while (index < 2 && code != D_002BE328[index]) index++;
    if (index < 2) return B_002DE9F0[index];
    return 0;
}
}
