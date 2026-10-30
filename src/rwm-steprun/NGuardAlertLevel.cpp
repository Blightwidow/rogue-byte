typedef long s64; typedef int s32;
extern "C" {
s64 GrfsgsFromSgs(int);
s32 NGuardAlertLevel(char *arg0) {
    s64 grfs;
    if (*(s64 *)(arg0 + 0x2C0) & GrfsgsFromSgs(7)) {
        return 2;
    }
    grfs = GrfsgsFromSgs(5);
    grfs |= GrfsgsFromSgs(6);
    if (*(s64 *)(arg0 + 0x2C0) & grfs) {
        return 1;
    }
    return 0;
}
}
