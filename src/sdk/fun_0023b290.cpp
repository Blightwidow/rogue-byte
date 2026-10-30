extern "C" {
struct Syscall_23B290 {
    int number;
    int handler;
};
void FlushCache(int);
int RFU091_3(int);
void RFU116_SetSyscall_4(int, int);
void func_0023B228(int, void *, int);
extern char D_002C5A68;
extern int D_002C5DE0;
extern Syscall_23B290 D_002C5DE8[];
void func_0023B290(void) {
    unsigned int index;
    RFU116_SetSyscall_4(D_002C5DE8[0].number, D_002C5DE8[0].handler);
    func_0023B228(0x80075000, &D_002C5A68, 0x330);
    FlushCache(0);
    FlushCache(2);
    RFU116_SetSyscall_4(D_002C5DE8[1].number, D_002C5DE8[1].handler);
    RFU116_SetSyscall_4(D_002C5DE8[2].number, D_002C5DE8[2].handler);
    for (index = 3; index < 8; index++) {
        RFU116_SetSyscall_4(D_002C5DE8[index].number, RFU091_3(D_002C5DE8[index].number));
    }
    D_002C5DE0 = RFU091_3(3);
}
}
