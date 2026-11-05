extern "C" {
int sceMcOpen(int port, int slot, const char *name, int flags);
extern int D_002C8350;
int sceMcMkdir(int port, int slot, const char *name) {
    int result = sceMcOpen(port, slot, name, 0x40);
    if (result == 0) {
        D_002C8350 = 0xB;
    }
    return result;
}
}
