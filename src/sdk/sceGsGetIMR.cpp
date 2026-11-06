extern "C" {
unsigned int GsGetIMR(void);
unsigned int sceGsGetIMR(void) {
    return GsGetIMR();
}
}
