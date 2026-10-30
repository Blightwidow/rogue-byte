typedef int s32;
extern "C" {
s32 func_00143C78(char *self) {
    if (*(s32 *)(self + 0x204) != 0) return 0;
    s32 b = *(s32 *)(self + 0x4C8);
    if (b < 5) {
        if (b >= 3) return 4;
    }
    if (*(s32 *)(self + 0x2DC) != -1) return 1;
    switch (*(s32 *)(self + 0xDF4)) {
    case -1: case 0: case 6: return 7;
    case 4: case 7: case 8: case 12: return 1;
    default: return 0;
    }
}
}
