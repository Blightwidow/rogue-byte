typedef unsigned int u32;
int func_00239450();
void func_002394A0();
void func_00253478(u32 arg0, int arg1) {
    int enabled = func_00239450();
    if ((arg0 >> 0x1C) == 7) {
        arg0 &= 0x0FFFFFFF;
        arg0 |= 0x80000000;
    } else {
        arg0 &= 0x0FFFFFFF;
    }
    *(volatile u32 *)0x1000B010 = arg0;
    *(volatile u32 *)0x1000B020 = arg1 >> 4;
    *(volatile u32 *)0x1000B000 = 0x100;
    if (enabled != 0) {
        func_002394A0();
    }
}
