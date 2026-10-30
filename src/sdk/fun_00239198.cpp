typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
extern "C" {
struct SifRebootPacket_44C280 {
    u64 psize : 8;
    u64 dsize : 24;
    u32 daddr;
    u32 fcode;
    u32 opt;
    s32 pathLength;
    s32 argument;
    char path[0x50];
};
struct SifDmaTransfer_239198 { void *src; void *dest; s32 size; s32 attr; };
void func_0023A920(s32, s32);
void func_0023B170(void *, s32);
s32 sceSifGetReg(s32);
s32 sceSifSetDma(void *, s32);
void sceSifSetReg(s32, s32);
void sceSifStopDma();
extern SifRebootPacket_44C280 B_0044C280;
s32 func_00239198(char *path, s32 argument) {
    SifDmaTransfer_239198 dma;
    s32 destination;
    s32 length;
    func_0023A920(0, 0);
    func_0023A920(1, 0);
    sceSifStopDma();
    destination = sceSifGetReg(0x80000000);
    B_0044C280.argument = argument;
    for (length = 0; path[length] != 0; length++) {
        B_0044C280.path[length] = path[length];
    }
    B_0044C280.daddr = 0;
    B_0044C280.pathLength = length;
    B_0044C280.fcode = 0x80000003;
    B_0044C280.dsize = 0;
    B_0044C280.psize = 0x68;
    dma.src = &B_0044C280;
    dma.dest = (void *)destination;
    dma.size = 0x68;
    dma.attr = 0x44;
    func_0023B170(&B_0044C280, 0x68);
    sceSifSetReg(4, 0x40000);
    if (sceSifSetDma(&dma, 1) != 0) {
        sceSifSetReg(4, 0x10000);
        sceSifSetReg(4, 0x20000);
        sceSifSetReg(0x80000002, 0);
        sceSifSetReg(0x80000000, 0);
        return 1;
    }
    return 0;
}
}
