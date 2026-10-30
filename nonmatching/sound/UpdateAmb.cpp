extern "C" {
void SetAmbGrf(char *, int, int);
#define VTAB(object) (*(char **)((char *)(object) + 0xC))
#define VADJ(object, off) ((char *)(object) + *(short *)(VTAB(object) + (off) - 4))
#define VFN(object, off) (*(void **)(VTAB(object) + (off)))
#define VCALL0(object, off) ((void (*)(char *))VFN(object, off))(VADJ(object, off))
#define VCALL1(object, off, arg) ((void (*)(char *, char *))VFN(object, off))(VADJ(object, off), (arg))
void UpdateAmb(char *arg0) {
    char *sp0 = arg0;
    unsigned short flags;
    VCALL0(arg0, 0xC);
    if (!(*(unsigned short *)(arg0 + 0x50) & 0x200)) {
        *(float *)(arg0 + 0x44) = *(float *)(arg0 + 0x10);
    } else {
        VCALL0(arg0, 0x84);
    }
    flags = *(unsigned short *)(arg0 + 0x50);
    if (flags & 1) {
        VCALL0(arg0, 0x4C);
        if (((int (*)(char *))VFN(arg0, 0x44))(VADJ(arg0, 0x44)) == 1) {
            SetAmbGrf(arg0, 0x400, 0x400);
        }
    } else {
        if (*(int *)(arg0 + 0x40) != 0) {
            if (flags & 8) {
                VCALL0(arg0, 0x54);
                *(int *)(arg0 + 0x40) = 0;
                SetAmbGrf(arg0, 0x1DFF, 0);
            } else {
                if (flags & 0x1C00) {
                    VCALL0(arg0, 0x74);
                }
                if (*(unsigned short *)(arg0 + 0x52) != 0) {
                    VCALL1(sp0, 0x14, sp0);
                    return;
                }
                if (*(unsigned short *)(arg0 + 0x50) & 0x1F0) {
                    VCALL1(arg0, 0x6C, sp0);
                    SetAmbGrf(arg0, 0x1F0, 0);
                }
                flags = *(unsigned short *)(arg0 + 0x50);
                if (flags & 2) {
                    VCALL0(arg0, 0x5C);
                    SetAmbGrf(arg0, 2, 0);
                } else if (flags & 4) {
                    VCALL1(arg0, 0x64, sp0);
                    SetAmbGrf(arg0, 4, 0);
                }
            }
        } else if ((*(unsigned short *)(arg0 + 0x52) == 0) && !(flags & 0x200)) {
            SetAmbGrf(arg0, 0x1FFF, 0);
        }
    }
    VCALL1(sp0, 0x14, sp0);
}
}
