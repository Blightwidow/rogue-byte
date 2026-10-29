typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64;
#define NULL 0
extern "C" {
s32 FIsBasicDerivedFrom(s32 object, s32 kind);

void func_001C20E8(char *arg0, s32 arg1) {
    u32 count;
    char *slot;

    count = *(u32 *)(arg0 + 0x50);
    if (count < 6) {
        *(u32 *)(arg0 + 0x50) = count + 1;
        slot = arg0 + ((count << 5) + 0x60);
        if (FIsBasicDerivedFrom(arg1, 0xA)) {
            *(s32 *)slot = arg1;
        } else {
            *(s32 *)(slot + 4) = arg1;
        }
    }
}

}
