typedef unsigned int u32;
extern "C" {
int func_00239450();
void func_002394A0();
void func_0024F8D0() {
    int flag = func_00239450();
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 | 0x10000;
    *(volatile u32 *)0x1000B000 = 0;
    *(volatile u32 *)0x1000B400 = 0;
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 & 0xFFFEFFFF;
    if (flag != 0) {
        func_002394A0();
    }
    *(volatile u32 *)0x1000B020 = 0;
    *(volatile u32 *)0x1000B420 = 0;
    *(volatile u32 *)0x10002010 = 0x40000000;
}
}
