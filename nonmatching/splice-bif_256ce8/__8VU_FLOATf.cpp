// 0x256CE8 __8VU_FLOATf
extern "C" void __8VU_FLOATf(int a0, float f12);
void __8VU_FLOATf(int a0, float f12) {
    int v0 = a0;
    int v1 = 0;
    __asm__ ("mfc1 $v1, $f12");
    __asm__ ("sq $v1, 0($v0)");
    __asm__ ("sq $v1, 0($sp)");
    __asm__ ("jr $ra");
    __asm__ ("addiu $sp, $sp, 0x10");
    return;
}
