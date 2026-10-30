typedef unsigned int u32;
extern "C" {
struct Ipu_251E60 { int pad0[0x20B]; unsigned cmdState; int pad830[0xE]; void *field868; int pad86C[3]; int field878; };
int func_0024B6E8(void *);
void func_0024F8D0();
void func_00251E60(Ipu_251E60 *ipu) {
    int count = 0;
    while ((*(volatile u32 *)0x10002010 & 0x80004000) == 0x80000000) {
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
        if (count++ > 0x1388) {
            func_0024B6E8(ipu->field868);
            count = 0;
            if (ipu->field878 != 0) {
                func_0024F8D0();
                break;
            }
        }
    }
    ipu->cmdState = 0;
}
}
