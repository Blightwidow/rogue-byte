typedef unsigned int u32;
extern "C" {
struct Ipu_251FC8 { int pad0[0x20B]; unsigned cmdState; int pad830[0xE]; void *field868; int pad86C[3]; int field878; };
int func_0024B6E8(void *);
void func_0024F8D0();
long func_00251FC8(Ipu_251FC8 *ipu) {
    int count = 0;
    long command;
    while ((command = *(volatile long *)0x10002000) < 0 && (*(volatile u32 *)0x10002010 & 0x4000) == 0) {
        u32 bitPosition = *(volatile u32 *)0x10002020;
        unsigned state = ipu->cmdState;
        u32 fifo = ((bitPosition & 0xFF00) >> 1) + ((bitPosition & 0x30000) >> 9) - (bitPosition & 0x7F);
        if (state == 0x20000000 || state == 0x30000000 || state == 0x40000000) {
            if (fifo < 0x20 && *(volatile u32 *)0x1000B420 == 0) {
                func_0024B6E8(ipu->field868);
                count = 0;
                if (ipu->field878 != 0) {
                    func_0024F8D0();
                    break;
                }
            }
        }
        if (count++ > 0x1F4) {
            func_0024B6E8(ipu->field868);
            count = 0;
            if (ipu->field878 != 0) {
                func_0024F8D0();
                break;
            }
        }
    }
    ipu->cmdState = 0;
    return command;
}
}
