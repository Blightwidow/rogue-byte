typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
extern "C" {
struct Block_44E300 { Block_44E300 *next; char pad[0xC]; };
extern Block_44E300 B_0044E300[64];
extern Block_44E300 *B_0044E700;
s32 func_0023A618(void) {
    s32 i;
    B_0044E700 = B_0044E300;
    for (i = 0x3F; i >= 0; i--) {
        B_0044E300[i].next = &B_0044E300[i + 1];
    }
    B_0044E300[0x3F].next = 0;
    return 0;
}
}
