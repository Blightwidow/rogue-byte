struct Patch { int number; int handler; };
extern "C" {
void FlushCache(int);
int PatchIsNeeded();
int RFU091(int);
void RFU116_SetSyscall_2(int, int);
void func_00239728(unsigned, void *, int);
extern char D_002C4AC0[];
extern Patch D_002C5268[];
void InitExecPS2() {
    if (PatchIsNeeded() != 0) {
        Patch *patches = D_002C5268;
        RFU116_SetSyscall_2(patches[0].number, patches[0].handler);
        func_00239728(0x80074000, D_002C4AC0, 0x7A8);
        FlushCache(0);
        FlushCache(2);
        RFU116_SetSyscall_2(patches[1].number, patches[1].handler);
        Patch *cursor = patches + 2;
        unsigned count = 2;
        do {
            count++;
            int handler = RFU091(cursor->number);
            int number = cursor->number;
            cursor++;
            RFU116_SetSyscall_2(number, handler);
        } while (count < 3);
    }
}
}
