typedef unsigned int u32;
int func_00239450();
void func_002394A0();
void func_00254898(u32 arg0) {
    int enabled = func_00239450();
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 | 0x10000;
    *(volatile u32 *)0x1000B000 = arg0;
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 & 0xFFFEFFFF;
    if (enabled != 0) {
        func_002394A0();
    }
}
