extern "C" {
extern void BASIC_Destruct(char *, int);
extern int FreeAmb(char *);

void AMB_Release(char *arg0) {
    int temp_v0;

    temp_v0 = *(unsigned short *)(arg0 + 0x4C) - 1;
    *(unsigned short *)(arg0 + 0x4C) = temp_v0;
    if (((temp_v0 << 0x10) == 0) && (arg0 != 0)) {
        BASIC_Destruct(arg0, 0);
        FreeAmb(arg0);
    }
}
}
